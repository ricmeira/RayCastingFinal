#include "myhay.h"
#include "solidcube.h"
#include "object.h"

MyHay::MyHay() : Object()
{

}

MyHay::MyHay(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Khaki
    SolidCube *hay = new SolidCube(
                new Material(   // Material
                    new Color(0.941, 0.902, 0.549),   // Reflectivity Ambience
                    new Color(0.941, 0.902, 0.549),   // Reflectivity Diffuse
                    new Color(0.941, 0.902, 0.549), // Reflectivity Specular
                    100.0   // M
                )
            );

    this->subObjects->push_back(hay);
}
