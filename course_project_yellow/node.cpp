#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event){
    return true;
};

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date)
: cmp_(cmp), date_(date){};

bool DateComparisonNode::Evaluate(const Date& date, const string& event){
    if (cmp_ == Comparison::Less){
        return date < date_;
    } else if (cmp_ == Comparison::LessOrEqual){
        return date < date_ || date == date_;
    }
    else if (cmp_ == Comparison::Greater){
        return date > date_;
    }
    else if (cmp_ == Comparison::GreaterOrEqual){
        return date > date_ || date == date_;
    }
    else if (cmp_ == Comparison::Equal){
        return date == date_;
    }
    else if (cmp_ == Comparison::NotEqual){
        return !(date == date_);
    }
    return true;
};

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event_name)
: cmp_(cmp), event_name_(event_name){};

bool EventComparisonNode::Evaluate(const Date& date, const string& event){
    if (cmp_ == Comparison::Equal){
        return event == event_name_;
    }
    else if (cmp_ == Comparison::NotEqual){
        return !(event == event_name_);
    }
    else if (cmp_ == Comparison::Less){
        return event < event_name_;
    }
    else if (cmp_ == Comparison::LessOrEqual){
        return event < event_name_ || event == event_name_;
    }
    else if (cmp_ == Comparison::Greater){
        return event > event_name_;
    }
    else if (cmp_ == Comparison::GreaterOrEqual){
        return event > event_name_ || event == event_name_;
    }

    return true;
};

LogicalOperationNode::LogicalOperationNode(
        const LogicalOperation &logical_operation,const shared_ptr<Node>& left, const shared_ptr<Node>& right)
        : logical_operation_(logical_operation), left_(left),right_(right){};

bool LogicalOperationNode::Evaluate(const Date& date, const string& event){
    if(logical_operation_ == LogicalOperation::And){
        return left_->Evaluate(date, event) && right_ ->Evaluate(date, event);
    } else if (logical_operation_ == LogicalOperation::Or){
        return left_->Evaluate(date, event) || right_ ->Evaluate(date, event);
    } else{
        return true;
    }
};