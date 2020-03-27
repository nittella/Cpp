#pragma once

#include <cmath>

#include "atom.h"

class CartesianCoordinate{
public:
    CartesianCoordinate(AtomType atom_type, int number, double x, double y, double z);

    double CalculateRadius() const;

    AtomType GetType() const;

    int GetNumber()const;

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    double CalculateDestination(const CartesianCoordinate& another_coord) const;

private:
    AtomType atom_type_ = AtomType::O;
    int number_;
    double x_ = 0;
    double y_ = 0;
    double z_ = 0;
};

bool operator==(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs);

bool operator!=(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs);
CartesianCoordinate operator-(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs);
CartesianCoordinate operator+(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs);
double operator*(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs);