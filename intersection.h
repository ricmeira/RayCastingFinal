#ifndef INTERSECTION_H
#define INTERSECTION_H

#include<armadillo>

using namespace arma;

class Intersection
{
public:
    double t;
    double u;
    double v;

    Intersection();
    Intersection(double t, double u, double v);
};

#endif // INTERSECTION_H
