#include "mycloud.h"
#include "solidcube.h"
#include "object.h"

MyCloud::MyCloud() : Object()
{

}

MyCloud::MyCloud(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Snow
    SolidCube *cloud = new SolidCube(
                new Material(   // Material
                    new Color(1.000, 0.980, 0.980),   // Reflectivity Ambience
                    new Color(1.000, 0.980, 0.980),   // Reflectivity Diffuse
                    new Color(1.000, 0.980, 0.980), // Reflectivity Specular
                    100.0   // M
                )
            );

    cloud->scale(2.0, 1.0, 1.0);

    this->subObjects->push_back(cloud);
}
