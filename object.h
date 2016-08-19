#ifndef OBJECT_H
#define OBJECT_H

#include "triangle.h"
#include "material.h"
#include "intersection.h"
#include "mathutils.h"

#include <vector>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

class Object
{
public:
    int id;
    vector<Object*> *subObjects;
    vector<Point*> *points;
    vector<Triangle*> *triangles;
    Material *material;

    Object();
    Object(Material *material);
    Object(int id, Material *material, float objectPoints[], int arrayLength);

    void updatePointsToCamera(mat &matrixWorldToCamera);
    void scale(double scaleX, double scaleY, double scaleZ);
    void rotateAxisX(double angle);
    void rotateAxisY(double angle);
    void rotateAxisZ(double angle);
    void translate(double translateX, double translateY, double translateZ);
};

#endif // OBJECT_H
