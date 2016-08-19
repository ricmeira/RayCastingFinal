#include "camera.h"

Camera::Camera()
{

}

Camera::Camera(Point *position, Point *lookAt, Point *viewUp)
{
    this->position = position;
    this->lookAt = lookAt;
    this->viewUp = viewUp;
    this->kc = this->calculateKc(this->position, this->lookAt);
    this->ic = this->calculateIc(this->viewUp, this->position, this->kc);
    this->jc = this->calculateJc(this->kc, this->ic);
    this->mWorldToCamera = this->calculateMatrixWorldToCamera(this->ic, this->jc, this->kc, this->position);
}

vec Camera::calculateIc(Point *viewUp, Point *position, vec &kc)
{
    vec::fixed<3> ob;
    ob[0] = viewUp->x - position->x;
    ob[1] = viewUp->y - position->y;
    ob[2] = viewUp->z - position->z;

    vec::fixed<3> ic = cross(ob, kc);

    return normalise(ic);
}

vec Camera::calculateJc(vec &kc, vec &ic)
{
    vec::fixed<3> jc = cross(kc, ic);

    return jc;
}

vec Camera::calculateKc(Point *position, Point *lookAt)
{
    vec::fixed<3> kc;
    kc[0] = position->x - lookAt->x;
    kc[1] = position->y - lookAt->y;
    kc[2] = position->z - lookAt->z;

    return normalise(kc);
}

mat Camera::calculateMatrixWorldToCamera(vec &ic, vec &jc, vec &kc, Point *position)
{
    vec::fixed<3> vecPosition;
    vecPosition[0] = position->x;
    vecPosition[1] = position->y;
    vecPosition[2] = position->z;

    mat::fixed<4, 4> mWorldToCamera;
    mWorldToCamera(0, 0) = ic.at(0);
    mWorldToCamera(1, 0) = jc.at(0);
    mWorldToCamera(2, 0) = kc.at(0);
    mWorldToCamera(3, 0) = 0.0;

    mWorldToCamera(0, 1) = ic.at(1);
    mWorldToCamera(1, 1) = jc.at(1);
    mWorldToCamera(2, 1) = kc.at(1);
    mWorldToCamera(3, 1) = 0.0;

    mWorldToCamera(0, 2) = ic.at(2);
    mWorldToCamera(1, 2) = jc.at(2);
    mWorldToCamera(2, 2) = kc.at(2);
    mWorldToCamera(3, 2) = 0.0;

    mWorldToCamera(0, 3) = -(dot(ic, vecPosition));
    mWorldToCamera(1, 3) = -(dot(jc, vecPosition));
    mWorldToCamera(2, 3) = -(dot(kc, vecPosition));
    mWorldToCamera(3, 3) = 1.0;

    return mWorldToCamera;
}
