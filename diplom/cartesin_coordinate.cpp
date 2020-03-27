#include "cartesin_coordinate.h"


CartesianCoordinate::CartesianCoordinate(AtomType atom_type,
int number,
double x, double y, double z)
: number_(number),
x_(x),
y_(y),
z_(z){
    atom_type_ = atom_type;
}

double CartesianCoordinate::CalculateRadius() const {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

AtomType CartesianCoordinate::GetType() const{
    return atom_type_;
};

int CartesianCoordinate::GetNumber()const{
    return number_;
};

double CartesianCoordinate::GetX() const{
    return x_;
};
double CartesianCoordinate::GetY() const{
    return y_;
};
double CartesianCoordinate::GetZ() const{
    return z_;
};

double CartesianCoordinate::CalculateDestination(const CartesianCoordinate& another_coord) const{

    double result = sqrt(
            pow((x_ - another_coord.GetX()), 2)
            + pow((y_ - another_coord.GetY()), 2)
            + pow(z_ - another_coord.GetZ(), 2)
    );
    return result;
}


bool operator==(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs){
    return lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY() && lhs.GetZ() == rhs.GetZ();
}

bool operator!=(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs) {
    return !(lhs == rhs);
}

CartesianCoordinate operator-(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs){
    double x = lhs.GetX() - rhs.GetX();
    double y = lhs.GetY() - rhs.GetY();
    double z = lhs.GetZ() - rhs.GetZ();
    return CartesianCoordinate{lhs.GetType(), lhs.GetNumber(), x, y, z};
};
CartesianCoordinate operator+(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs){
    double x = lhs.GetX() + rhs.GetX();
    double y = lhs.GetY() + rhs.GetY();
    double z = lhs.GetZ() + rhs.GetZ();
    return CartesianCoordinate{lhs.GetType(), lhs.GetNumber(), x, y, z};
};
double operator*(const CartesianCoordinate& lhs, const CartesianCoordinate& rhs){
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
};