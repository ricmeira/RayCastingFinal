#ifndef LIGHT_H
#define LIGHT_H

#include "point.h"
#include "color.h"

class Light
{
public:
    Point *position;
    Color *intensity;

    Light(Point *position, Color *intensity);
};

#endif // LIGHT_H
