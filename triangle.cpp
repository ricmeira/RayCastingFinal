#include "triangle.h"

using namespace std;

Triangle::Triangle()
{

}

Triangle::Triangle(Point *p1, Point *p2, Point *p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

vec Triangle::getNormal()
{
    vec::fixed<3> p1;
    p1[0] = this->p1->x;
    p1[1] = this->p1->y;
    p1[2] = this->p1->z;

    vec::fixed<3> p2;
    p2[0] = this->p2->x;
    p2[1] = this->p2->y;
    p2[2] = this->p2->z;

    vec::fixed<3> p3;
    p3[0] = this->p3->x;
    p3[1] = this->p3->y;
    p3[2] = this->p3->z;

    vec::fixed<3> normal;
    normal = cross((p2 - p1), (p3 - p1));

    return normalise(normal);
}

Intersection* Triangle::getTriangleIntersection(Ray *ray)
{
    vec::fixed<3> x;
    x[0] = ray->direction[0] - ray->position->x;
    x[1] = ray->direction[1] - ray->position->y;
    x[2] = ray->direction[2] - ray->position->z;

//    cout << "x: " << x << endl;

    vec::fixed<3> a1;
    a1[0] = - ( this->p2->x - this->p1->x );
    a1[1] = - ( this->p2->y - this->p1->y );
    a1[2] = - ( this->p2->z - this->p1->z );

//    cout << "a1: " << a1 << endl;

    vec::fixed<3> a2;
    a2[0] = - ( this->p3->x - this->p1->x );
    a2[1] = - ( this->p3->y - this->p1->y );
    a2[2] = - ( this->p3->z - this->p1->z );

//    cout << "a2: " << a2 << endl;

    vec::fixed<3> p;
    p[0] = this->p1->x - ray->position->x;
    p[1] = this->p1->y - ray->position->y;
    p[2] = this->p1->z - ray->position->z;

//    cout << "p: " << p << endl;

    double mainDeterminant = this->calculateDeterminant(x, a1, a2);
    double tDeterminant = this->calculateDeterminant(p, a1, a2);
    double uDeterminant = this->calculateDeterminant(x, p, a2);
    double vDeterminant = this->calculateDeterminant(x, a1, p);

//    cout << "mainDet: " << mainDeterminant << endl;
//    cout << "tDet: " << tDeterminant << endl;
//    cout << "uDet: " << uDeterminant << endl;
//    cout << "vDet: " << vDeterminant << endl;

    double t = tDeterminant / mainDeterminant;
    double u = uDeterminant / mainDeterminant;
    double v = vDeterminant / mainDeterminant;

//    cout << "t: " << t << endl;
//    cout << "u: " << u << endl;
//    cout << "v: " << v << endl;

    Intersection intersection = Intersection(t, u, v);

    return &intersection;
}

double Triangle::calculateDeterminant(vec &v1, vec &v2, vec &v3)
{
    mat::fixed<3, 3> matrix;
    matrix(0, 0) = v1.at(0);
    matrix(1, 0) = v1.at(1);
    matrix(2, 0) = v1.at(2);

    matrix(0, 1) = v2.at(0);
    matrix(1, 1) = v2.at(1);
    matrix(2, 1) = v2.at(2);

    matrix(0, 2) = v3.at(0);
    matrix(1, 2) = v3.at(1);
    matrix(2, 2) = v3.at(2);

    return det(matrix);
}
