#include "myterrain.h"
#include "solidcube.h"
#include "object.h"

MyTerrain::MyTerrain() : Object()
{

}

MyTerrain::MyTerrain(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: LawnGreen
    SolidCube *terrain = new SolidCube(
                new Material(   // Material
                    new Color(0.486, 0.988, 0.0),   // Reflectivity Ambience
                    new Color(0.486, 0.988, 0.0),   // Reflectivity Diffuse
                    new Color(0.486, 0.988, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );

    this->subObjects->push_back(terrain);
}
