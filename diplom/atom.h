#pragma once

#include <string>
#include <iostream>

using namespace std;

enum struct AtomType{
    C,
    O,
    H,
    NoType
};

string ToString(const AtomType& atom_type);

istream& operator>> (istream& is, AtomType& atom_type);

ostream& operator<< (ostream& os, const AtomType& atom_type);

struct Atom{
    AtomType type;
    int number;
};

bool operator< (const Atom& rhs, const Atom& lhs);

bool operator== (const Atom& rhs, const Atom& lhs);

bool operator!= (const Atom& rhs, const Atom& lhs);

ostream& operator<< (ostream& os, const Atom& a);
