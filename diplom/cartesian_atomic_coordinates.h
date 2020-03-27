#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <algorithm>

#include "string_parser.h"
#include "atom.h"
#include "cartesin_coordinate.h"

using namespace std;

class CartesianAtomsCoordinates{
public:
    CartesianAtomsCoordinates();

    CartesianAtomsCoordinates(const vector<CartesianCoordinate>& coordinates);

    void Add(CartesianCoordinate cord);

    CartesianCoordinate GetCoordinate(int atom_number)const;

    size_t Size() const;

    map<Atom, vector<pair<double, Atom>>> CalculateDestinations() const;

    vector<CartesianCoordinate>::iterator begin();

    vector<CartesianCoordinate>::iterator end();

    vector<CartesianCoordinate>::const_iterator begin() const;

    vector<CartesianCoordinate>::const_iterator end() const;

private:
    vector<CartesianCoordinate> coordinates_;
};

CartesianAtomsCoordinates ReadCoordinates(const string& file_name);