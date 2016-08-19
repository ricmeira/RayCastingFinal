#include "mysilo.h"
#include "solidcube.h"
#include "object.h"

MySilo::MySilo() : Object()
{

}

MySilo::MySilo(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Silver
    SolidCube *body = new SolidCube(
                new Material(   // Material
                    new Color(0.753, 0.753, 0.753),   // Reflectivity Ambience
                    new Color(0.753, 0.753, 0.753),   // Reflectivity Diffuse
                    new Color(0.753, 0.753, 0.753), // Reflectivity Specular
                    100.0   // M
                )
            );
    body->scale(25.0, 40.0, 25.0);

    // Color: WhiteSmoke
    SolidCube *top = new SolidCube(
                new Material(   // Material
                    new Color(0.961, 0.961, 0.961),   // Reflectivity Ambience
                    new Color(0.961, 0.961, 0.961),   // Reflectivity Diffuse
                    new Color(0.961, 0.961, 0.961), // Reflectivity Specular
                    100.0   // M
                )
            );
    top->scale(25.0, 8.0, 25.0);
    top->translate(0.0, 24.0, 0.0);

    // Color: WhiteSmoke
    SolidCube *tube = new SolidCube(
                new Material(   // Material
                    new Color(0.961, 0.961, 0.961),   // Reflectivity Ambience
                    new Color(0.961, 0.961, 0.961),   // Reflectivity Diffuse
                    new Color(0.961, 0.961, 0.961), // Reflectivity Specular
                    100.0   // M
                )
            );
    tube->scale(3.0, 48.0, 3.0);
    tube->translate(0.0, 4.0, 13.5);

    this->subObjects->push_back(body);
    this->subObjects->push_back(top);
    this->subObjects->push_back(tube);
}
