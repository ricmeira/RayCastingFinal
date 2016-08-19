#include "mysun.h"
#include "solidcube.h"
#include "object.h"

MySun::MySun() : Object()
{

}

MySun::MySun(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Yellow
    SolidCube *sun = new SolidCube(
                new Material(   // Material
                    new Color(1.0, 1.0, 0.0),   // Reflectivity Ambience
                    new Color(1.0, 1.0, 0.0),   // Reflectivity Diffuse
                    new Color(1.0, 1.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );

    this->subObjects->push_back(sun);
}
