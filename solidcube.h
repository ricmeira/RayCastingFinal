#ifndef SOLIDCUBE_H
#define SOLIDCUBE_H

#include "object.h"

class SolidCube : public Object
{
public:
    Point *p1;
    Point *p2;
    Point *p3;
    Point *p4;
    Point *p5;
    Point *p6;
    Point *p7;
    Point *p8;

    Triangle *t1;
    Triangle *t2;
    Triangle *t3;
    Triangle *t4;
    Triangle *t5;
    Triangle *t6;
    Triangle *t7;
    Triangle *t8;
    Triangle *t9;
    Triangle *t10;
    Triangle *t11;
    Triangle *t12;

    SolidCube();
    SolidCube(Material *material);
};

#endif // SOLIDCUBE_H
