#include "material.h"

Material::Material()
{

}

Material::Material(Color *reflectivityAmbience, Color *reflectivityDiffuse, Color *reflectivitySpecular, double m)
{
    this->reflectivityAmbience = reflectivityAmbience;
    this->reflectivityDiffuse = reflectivityDiffuse;
    this->reflectivitySpecular = reflectivitySpecular;
    this->m = m;
}

