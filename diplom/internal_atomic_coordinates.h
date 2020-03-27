#pragma once

#include <string>
#include <set>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "atom.h"
#include "internal_coordinate_type.h"
#include "internal_coordinate.h"
using namespace std;

class InternalAtomsCoordinates{
public:

    void Add(const InternalCoordinate& i_cord);

    size_t Size () const;

    const InternalCoordinate& operator[] (int number) const;

    InternalCoordinate& operator[] (int number);

    void Sort();

    auto begin();

    auto end();

    const auto begin() const;

    const auto end() const;

private:
    vector<InternalCoordinate> coordinates_;
};

ostream& operator<< (ostream& os, InternalAtomsCoordinates coords);