#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

class Material
{
public:
    Color *reflectivityAmbience;
    Color *reflectivityDiffuse;
    Color *reflectivitySpecular;
    double m;

    Material();
    Material(Color *reflectivityAmbience, Color *reflectivityDiffuse, Color *reflectivitySpecular, double m);
};

#endif // MATERIAL_H
