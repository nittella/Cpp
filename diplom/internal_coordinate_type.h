#pragma once

#include <string>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

enum class InternalCoordinateTypeName{
    Type1,
    Type2,
    Type3,
    Type4,
    Type5,
    Type6
};


class InternalCoordinateType{
public:

    InternalCoordinateType();

    InternalCoordinateType(InternalCoordinateTypeName type_name, vector<int> atoms);

    string GetName() const;

    InternalCoordinateTypeName GetType() const;

    vector<int> GetAtoms() const;

private:
    InternalCoordinateTypeName type_name_;
    vector<int> atoms_;
};

ostream& operator<<(ostream& os, vector<int> s);