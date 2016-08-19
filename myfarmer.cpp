#include "myfarmer.h"

MyFarmer::MyFarmer() : Object()
{

}

MyFarmer::MyFarmer(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Navy
    SolidCube *pants = new SolidCube(
                new Material(   // Material
                    new Color(0.000, 0.000, 0.502),   // Reflectivity Ambience
                    new Color(0.000, 0.000, 0.502),   // Reflectivity Diffuse
                    new Color(0.000, 0.000, 0.502), // Reflectivity Specular
                    100.0   // M
                )
            );
    pants->scale(3.0, 5.0, 3.0);

    // Color: Crimson
    SolidCube *shirt = new SolidCube(
                new Material(   // Material
                    new Color(0.863, 0.078, 0.235),   // Reflectivity Ambience
                    new Color(0.863, 0.078, 0.235),   // Reflectivity Diffuse
                    new Color(0.863, 0.078, 0.235), // Reflectivity Specular
                    100.0   // M
                )
            );
    shirt->scale(3.0, 5.0, 3.0);
    shirt->translate(0.0, 5.0, 0.0);

    // Color: Crimson
    SolidCube *leftArm = new SolidCube(
                new Material(   // Material
                    new Color(0.863, 0.078, 0.235),   // Reflectivity Ambience
                    new Color(0.863, 0.078, 0.235),   // Reflectivity Diffuse
                    new Color(0.863, 0.078, 0.235), // Reflectivity Specular
                    100.0   // M
                )
            );
    leftArm->scale(1.0, 6.0, 1.0);
    leftArm->rotateAxisX(90.0);
    leftArm->translate(2.0, 6.0, 3.0);

    // Color: Crimson
    SolidCube *rightArm = new SolidCube(
                new Material(   // Material
                    new Color(0.863, 0.078, 0.235),   // Reflectivity Ambience
                    new Color(0.863, 0.078, 0.235),   // Reflectivity Diffuse
                    new Color(0.863, 0.078, 0.235), // Reflectivity Specular
                    100.0   // M
                )
            );
    rightArm->scale(1.0, 6.0, 1.0);
    rightArm->rotateAxisX(90.0);
    rightArm->translate(-2.0, 6.0, 3.0);

    // Color: Cornsilk
    SolidCube *head = new SolidCube(
                new Material(   // Material
                    new Color(1.000, 0.973, 0.863),   // Reflectivity Ambience
                    new Color(1.000, 0.973, 0.863),   // Reflectivity Diffuse
                    new Color(1.000, 0.973, 0.863), // Reflectivity Specular
                    100.0   // M
                )
            );
    head->scale(3.0, 2.5, 3.0);
    head->translate(0.0, 8.75, 0.0);

    // Color: Chocolate
    SolidCube *hatBase = new SolidCube(
                new Material(   // Material
                    new Color(0.824, 0.412, 0.118),   // Reflectivity Ambience
                    new Color(0.824, 0.412, 0.118),   // Reflectivity Diffuse
                    new Color(0.824, 0.412, 0.118), // Reflectivity Specular
                    100.0   // M
                )
            );
    hatBase->scale(7.0, 0.5, 7.0);
    hatBase->translate(0.0, 10.25, 0.0);

    // Color: Chocolate
    SolidCube *hatTop = new SolidCube(
                new Material(   // Material
                    new Color(0.824, 0.412, 0.118),   // Reflectivity Ambience
                    new Color(0.824, 0.412, 0.118),   // Reflectivity Diffuse
                    new Color(0.824, 0.412, 0.118), // Reflectivity Specular
                    100.0   // M
                )
            );
    hatTop->scale(3.5, 2.0, 3.5);
    hatTop->translate(0.0, 11.25, 0.0);

    this->subObjects->push_back(pants);
    this->subObjects->push_back(shirt);
    this->subObjects->push_back(leftArm);
    this->subObjects->push_back(rightArm);
    this->subObjects->push_back(head);
    this->subObjects->push_back(hatBase);
    this->subObjects->push_back(hatTop);
}
