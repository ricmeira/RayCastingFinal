#include "mylamp.h"
#include "solidcube.h"
#include "object.h"

MyLamp::MyLamp() : Object()
{

}

MyLamp::MyLamp(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Black
    SolidCube *bar = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    bar->scale(1.0, 8.0, 1.0);

    // Color: Black
    SolidCube *boxBase = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    boxBase->scale(3.0, 0.25, 3.0);
    boxBase->translate(0.0, 4.125, 0.0);

    // Color: White
    SolidCube *lamp = new SolidCube(
                new Material(   // Material
                    new Color(1.0, 1.0, 1.0),   // Reflectivity Ambience
                    new Color(1.0, 1.0, 1.0),   // Reflectivity Diffuse
                    new Color(1.0, 1.0, 1.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    lamp->scale(1.5, 1.5, 1.5);
    lamp->translate(0.0, 4.9, 0.0);

    // Color: Black
    SolidCube *boxTop = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    boxTop->scale(3.0, 0.25, 3.0);
    boxTop->translate(0.0, 5.65, 0.0);

    this->subObjects->push_back(bar);
    this->subObjects->push_back(boxBase);
    this->subObjects->push_back(lamp);
    this->subObjects->push_back(boxTop);
}
