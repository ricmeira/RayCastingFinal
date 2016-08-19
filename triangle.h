#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<armadillo>

#include "point.h"
#include "intersection.h"
#include "ray.h"

using namespace arma;

class Triangle
{
public:
    Point *p1;
    Point *p2;
    Point *p3;
    vec normal;

    Triangle();
    Triangle(Point *p1, Point *p2, Point *p3);
    vec getNormal();
    Intersection* getTriangleIntersection(Ray *ray);
    double calculateDeterminant(vec &v1, vec &v2, vec &v3);
};

#endif // TRIANGLE_H
