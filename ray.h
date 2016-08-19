#ifndef RAY_H
#define RAY_H

#include "point.h"

#include <armadillo>

using namespace arma;

class Ray
{
public:
    Point *position;
    vec direction;

    Ray();
    Ray(Point *position, vec &direction);
};

#endif // RAY_H
