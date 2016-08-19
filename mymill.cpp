#include "mymill.h"
#include "solidcube.h"
#include "object.h"

MyMill::MyMill() : Object()
{

}

MyMill::MyMill(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Sienna
    SolidCube *house = new SolidCube(
                new Material(   // Material
                    new Color(0.627, 0.322, 0.176),   // Reflectivity Ambience
                    new Color(0.627, 0.322, 0.176),   // Reflectivity Diffuse
                    new Color(0.627, 0.322, 0.176), // Reflectivity Specular
                    100.0   // M
                )
            );
    house->scale(35.0, 25.0, 30.0);

    // Color: Sienna
    SolidCube *roof = new SolidCube(
                new Material(   // Material
                    new Color(0.627, 0.322, 0.176),   // Reflectivity Ambience
                    new Color(0.627, 0.322, 0.176),   // Reflectivity Diffuse
                    new Color(0.627, 0.322, 0.176), // Reflectivity Specular
                    100.0   // M
                )
            );
    roof->scale(30.0, 30.0, 30.0);
    roof->rotateAxisZ(45.0);
    roof->translate(0.0, 10.0, 0.0);

    // Color: Moccasin
    SolidCube *door = new SolidCube(
                new Material(   // Material
                    new Color(1.000, 0.894, 0.710),   // Reflectivity Ambience
                    new Color(1.000, 0.894, 0.710),   // Reflectivity Diffuse
                    new Color(1.000, 0.894, 0.710), // Reflectivity Specular
                    100.0   // M
                )
            );
    door->scale(10.0, 15.0, 1.0);
    door->translate(0.0, -5.0, -15.0);

    // Color: Black
    SolidCube *engine = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    engine->scale(8.0, 8.0, 8.0);
    engine->translate(0.0, 22.5, 18.0);

    // Color: SlateGray
    SolidCube *helix1 = new SolidCube(
                new Material(   // Material
                    new Color(0.467, 0.533, 0.600),   // Reflectivity Ambience
                    new Color(0.467, 0.533, 0.600),   // Reflectivity Diffuse
                    new Color(0.467, 0.533, 0.600), // Reflectivity Specular
                    100.0   // M
                )
            );
    helix1->scale(3.0, 50.0, 3.0);
    helix1->rotateAxisZ(45.0);
    helix1->translate(0.0, 22.5, 23.5);

    // Color: SlateGray
    SolidCube *helix2 = new SolidCube(
                new Material(   // Material
                    new Color(0.467, 0.533, 0.600),   // Reflectivity Ambience
                    new Color(0.467, 0.533, 0.600),   // Reflectivity Diffuse
                    new Color(0.467, 0.533, 0.600), // Reflectivity Specular
                    100.0   // M
                )
            );
    helix2->scale(3.0, 50.0, 3.0);
    helix2->rotateAxisZ(315.0);
    helix2->translate(0.0, 22.5, 23.5);

    this->subObjects->push_back(house);
    this->subObjects->push_back(roof);
    this->subObjects->push_back(door);
    this->subObjects->push_back(engine);
    this->subObjects->push_back(helix1);
    this->subObjects->push_back(helix2);
}
