#include "mybarn.h"
#include "solidcube.h"
#include "object.h"

MyBarn::MyBarn() : Object()
{

}

MyBarn::MyBarn(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: FireBrick
    SolidCube *houseBase = new SolidCube(
                new Material(   // Material
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Ambience
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Diffuse
                    new Color(0.698, 0.133, 0.133), // Reflectivity Specular
                    100.0   // M
                )
            );
    houseBase->scale(45.0, 35.0, 45.0);

    // Color: FireBrick
    SolidCube *houseBaseRoof = new SolidCube(
                new Material(   // Material
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Ambience
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Diffuse
                    new Color(0.698, 0.133, 0.133), // Reflectivity Specular
                    100.0   // M
                )
            );
    houseBaseRoof->scale(35.0, 35.0, 45.0);
    houseBaseRoof->rotateAxisZ(45.0);
    houseBaseRoof->translate(0.0, 15.0, 0.0);

    // Color: FireBrick
    SolidCube *houseTop = new SolidCube(
                new Material(   // Material
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Ambience
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Diffuse
                    new Color(0.698, 0.133, 0.133), // Reflectivity Specular
                    100.0   // M
                )
            );
    houseTop->scale(10.0, 10.0, 10.0);
    houseTop->translate(0.0, 42.5, 0.0);

    // Color: FireBrick
    SolidCube *houseTopRoof = new SolidCube(
                new Material(   // Material
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Ambience
                    new Color(0.698, 0.133, 0.133),   // Reflectivity Diffuse
                    new Color(0.698, 0.133, 0.133), // Reflectivity Specular
                    100.0   // M
                )
            );
    houseTopRoof->scale(8.0, 8.0, 10.0);
    houseTopRoof->rotateAxisZ(45.0);
    houseTopRoof->translate(0.0, 47.5, 0.0);

    // Color: Moccasin
    SolidCube *door = new SolidCube(
                new Material(   // Material
                    new Color(1.000, 0.894, 0.710),   // Reflectivity Ambience
                    new Color(1.000, 0.894, 0.710),   // Reflectivity Diffuse
                    new Color(1.000, 0.894, 0.710), // Reflectivity Specular
                    100.0   // M
                )
            );
    door->scale(25.0, 15.0, 1.0);
    door->translate(0.0, -10.0, 22.5);

    // Color: Moccasin
    SolidCube *window = new SolidCube(
                new Material(   // Material
                    new Color(1.000, 0.894, 0.710),   // Reflectivity Ambience
                    new Color(1.000, 0.894, 0.710),   // Reflectivity Diffuse
                    new Color(1.000, 0.894, 0.710), // Reflectivity Specular
                    100.0   // M
                )
            );
    window->scale(12.5, 10.0, 1.0);
    window->translate(0.0, 22.5, 22.5);

    this->subObjects->push_back(houseBase);
    this->subObjects->push_back(houseBaseRoof);
    this->subObjects->push_back(houseTop);
    this->subObjects->push_back(houseTopRoof);
    this->subObjects->push_back(door);
    this->subObjects->push_back(window);
}
