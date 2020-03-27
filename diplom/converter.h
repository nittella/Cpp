#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string_view>
#include <sstream>
#include <array>
#include <set>
#include <iomanip>
#include <map>

#include "cartesian_atomic_coordinates.h"
#include "internal_atomic_coordinates.h"
#include "atom.h"
#include "conditions.h"
#include "distances_manager.h"
InternalAtomsCoordinates ConvertToInternal(
        const CartesianAtomsCoordinates& c_cords);

template <typename T>
ostream& operator<< (ostream& os, set<T> s){
    for (const auto& item : s){
        os << item  << ", ";
    }
    os << "\n";
    return os;
}

template <typename Key, typename Value>
ostream& operator<< (ostream& os, map<Key, Value> m){
    for (auto& item : m){
        os << item.first << "\n" << item.second;
    }
    return os;
}