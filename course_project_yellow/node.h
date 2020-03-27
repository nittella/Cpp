#pragma once

#include "date.h"
#include <memory>
#include <string>

enum class Comparison{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation{
    And,
    Or
};

class Node{
public:
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const string& event);
};

class DateComparisonNode : public Node{
public:
    DateComparisonNode(const Comparison& cmp, const Date& date);

    bool Evaluate(const Date& date, const string& event);



private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& cmp, const string& event_name);

    bool Evaluate(const Date& date, const string& event);



private:
    Comparison cmp_;
    string event_name_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation &logical_operation,
                         const shared_ptr<Node>& left,
                         const shared_ptr<Node>& right);

    bool Evaluate(const Date& date, const string& event);

private:
    LogicalOperation logical_operation_;
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
};