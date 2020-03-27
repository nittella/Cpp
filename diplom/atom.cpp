#include "atom.h"

string ToString(const AtomType& atom_type){
    string result = "NoType";
    if(atom_type == AtomType::C){
        result = "C";
    } else if(atom_type == AtomType::O){
        result = "O";
    }else if(atom_type == AtomType::H){
        result = "H";
    }
    return result;
}

istream& operator>> (istream& is, AtomType& atom_type){
    string tmp;
    getline(is, tmp);
    if(tmp == "C" || tmp == "CARBON" || tmp == "6"){
        atom_type = AtomType ::C;
    } else if (tmp == "H" || tmp == "HYDROGEN" || tmp == "1"){
        atom_type = AtomType ::H;
    } else if (tmp == "O" || tmp == "OXYGEN" || tmp == "8"){
        atom_type = AtomType ::O;
    }
    return is;
}

ostream& operator<< (ostream& os, const AtomType& atom_type){
    os << ToString(atom_type);
    return os;
}

bool operator< (const Atom& rhs, const Atom& lhs){
    return rhs.number < lhs.number;
//    if(rhs.type == lhs.type){
//        return rhs.number < lhs.number;
//    } else{
//        return rhs.type < lhs.type;
//    }
}

bool operator== (const Atom& rhs, const Atom& lhs){
    return rhs.type == lhs.type && rhs.number == lhs.number;
}

bool operator!= (const Atom& rhs, const Atom& lhs){
    bool result = rhs.number != lhs.number;
    return result;
}

ostream& operator<< (ostream& os, const Atom& a){
    os << a.type << a.number;
    return os;
}