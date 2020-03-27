#include "internal_coordinate_type.h"

InternalCoordinateType::InternalCoordinateType (InternalCoordinateTypeName type_name, vector<int> atoms)
        : type_name_(type_name),
          atoms_(move(atoms)){}

InternalCoordinateType::InternalCoordinateType(){}

string InternalCoordinateType::GetName()const {
    if(type_name_ == InternalCoordinateTypeName ::Type1){
        return "1";
    } else if(type_name_ == InternalCoordinateTypeName ::Type2){
        return "2";
    } else if(type_name_ == InternalCoordinateTypeName ::Type3){
        return "3";
    } else if(type_name_ == InternalCoordinateTypeName ::Type4){
        return "4";
    } else if(type_name_ == InternalCoordinateTypeName ::Type5){
        return "5";
    } else if(type_name_ == InternalCoordinateTypeName ::Type6){
        return "6";
    } else {
        return "?";
    }
}

InternalCoordinateTypeName InternalCoordinateType::GetType() const{
    return type_name_;
};

vector<int> InternalCoordinateType::GetAtoms()const{
    return atoms_;
}

ostream& operator<<(ostream& os, vector<int> s){
    for (auto& item : s){
        os << " " << item;
    }
    return os;
}