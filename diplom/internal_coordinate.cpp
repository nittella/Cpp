#include "internal_coordinate.h"

int InternalCoordinate::GetNumber() const {
    return number_;
}
const string InternalCoordinate::GetName() const {
    return name_;
}

string InternalCoordinate::GetTypeName() const {
    return type_.GetName();
}

InternalCoordinateTypeName InternalCoordinate::GetType() const{
    return type_.GetType();
};

vector<int> InternalCoordinate::GetTypeAtoms() const {
    return type_.GetAtoms();
}

InternalCoordinate::InternalCoordinate(
        int number,  const InternalCoordinateType& t, const string& name
){
    number_ = number;
    type_ = t;
    name_ = name;
}

InternalCoordinate::InternalCoordinate (int number,
                                        InternalCoordinateTypeName t_name,
                                        vector<Atom> atoms,
                                        string name){
    number_ = number;
    vector<int> atomic_numbers;
    if(name == ""){
        for(auto& atom : atoms){
            name_ += ToString(atom.type) + to_string(atom.number);
        }
    } else {
        name_ = name + to_string(number);
    }
    if(t_name == InternalCoordinateTypeName::Type1){
        name_ += "_r";
    } else if (t_name == InternalCoordinateTypeName::Type2){
        name_ += "_a";
    } else if (t_name == InternalCoordinateTypeName::Type3){
        name_ += "_th";    }
    else if (t_name == InternalCoordinateTypeName::Type4){
        name_ += "_ta";
    } else if (t_name == InternalCoordinateTypeName::Type5){
        name_ += "_pl";
    }
    for(auto& atom : atoms){
        atomic_numbers.push_back(atom.number);
    }
    type_ = InternalCoordinateType{t_name, atomic_numbers};
}