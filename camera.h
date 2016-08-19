#ifndef CAMERA_H
#define CAMERA_H

#include<vector>
#include<armadillo>

#include "point.h"
#include "ray.h"

using namespace arma;

class Camera
{
public:
    Point *position;
    Point *lookAt;
    Point *viewUp;
    vec ic;
    vec jc;
    vec kc;
    mat mWorldToCamera;

    Camera();
    Camera(Point *position, Point *lookAt, Point *viewUp);
    vec calculateIc(Point *viewUp, Point *position, vec &kc);
    vec calculateJc(vec &kc, vec &ic);
    vec calculateKc(Point *position, Point *lookAt);
    mat calculateMatrixWorldToCamera(vec &ic, vec &jc, vec &kc, Point *position);
};

#endif // CAMERA_H
