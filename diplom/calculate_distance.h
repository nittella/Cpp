#pragma once

#include "cartesin_coordinate.h"

double CalculateDistance(
        const CartesianCoordinate& coord1,
        const CartesianCoordinate& coord2);

double CalculateDistance(
        const CartesianCoordinate& coord1,
        const CartesianCoordinate& delta_coord1,
        const CartesianCoordinate& coord2,
        const CartesianCoordinate& delta_coord2);
