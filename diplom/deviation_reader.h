#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include "cartesian_atomic_coordinates.h"
#include "calculate_distance.h"


using namespace std;

using Bond = pair<Atom, Atom>;

double CalculateDistance(const CartesianCoordinate& coord1, const CartesianCoordinate& coord2);
double CalculateDistance(const CartesianCoordinate& coord1, const CartesianCoordinate& delta_coord1,
                         const CartesianCoordinate& coord2, const CartesianCoordinate& delta_coord2);

double CalculateAngle(double a, double b, double c);

double CalculateAngle(const CartesianCoordinate& cord1, const CartesianCoordinate& cord2);

class Deviation{
public:
    void Add(double freq, const CartesianCoordinate& coord);
    map<double, map<double, vector<Atom>>> CalculateBestType2(const CartesianAtomsCoordinates& coordinates);
    map<double, vector<pair<double, Bond>>> CalculateBestType1(const CartesianAtomsCoordinates& coordinates);
    map<double, map<double, vector<Atom>>> CalculateBestType3(const CartesianAtomsCoordinates& coordinates);
    vector<double> GetFreq() const;
private:
    map<double, CartesianAtomsCoordinates> freq_to_deviations_;
    map<Atom, vector<CartesianCoordinate>> atom_to_deviations_;
    map<double, int> freq_to_id_;

};

Deviation DeviationReader(const string& file_name);
