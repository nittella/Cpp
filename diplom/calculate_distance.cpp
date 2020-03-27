
#include "calculate_distance.h"

double CalculateDistance(const CartesianCoordinate& coord1, const CartesianCoordinate& coord2){
    return coord1.CalculateDestination(coord2);
}

double CalculateDistance(const CartesianCoordinate& coord1, const CartesianCoordinate& delta_coord1,
                         const CartesianCoordinate& coord2, const CartesianCoordinate& delta_coord2){
    double result = sqrt(
            pow(coord1.GetX() + delta_coord1.GetX() - coord2.GetX() - delta_coord2.GetX(), 2)
            + pow(coord1.GetY() + delta_coord1.GetY() - coord2.GetY() - delta_coord2.GetY(), 2)
            + pow(coord1.GetZ() + delta_coord1.GetZ() - coord2.GetZ() - delta_coord2.GetZ(), 2)
    );
    return result;
}