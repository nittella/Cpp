#pragma once

#include <set>
#include <vector>
#include "internal_coordinate_type.h"
#include "atom.h"

class InternalCoordinate{
public:

    InternalCoordinate(int number, const InternalCoordinateType& type, const string& name);

    InternalCoordinate(int number, InternalCoordinateTypeName t_name, vector<Atom> atoms, string name = "");

    int GetNumber() const;

    const string GetName() const;

    string GetTypeName() const;

    InternalCoordinateTypeName GetType() const;

    vector<int> GetTypeAtoms() const;

private:
    int number_;
    string name_;
    InternalCoordinateType type_;
};