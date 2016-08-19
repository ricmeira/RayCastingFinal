#include "mydog.h"

MyDog::MyDog() : Object()
{

}

MyDog::MyDog(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Black
    SolidCube *body = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    body->scale(3.0, 2.0, 2.0);

    // Color: Black
    SolidCube *leg1 = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg1->scale(0.5, 1.5, 0.5);
    leg1->translate(-1.25, -1.75, -0.75);

    // Color: Black
    SolidCube *leg2 = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg2->scale(0.5, 1.5, 0.5);
    leg2->translate(1.25, -1.75, -0.75);

    // Color: Black
    SolidCube *leg3 = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg3->scale(0.5, 1.5, 0.5);
    leg3->translate(-1.25, -1.75, 0.75);

    // Color: Black
    SolidCube *leg4 = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg4->scale(0.5, 1.5, 0.5);
    leg4->translate(1.25, -1.75, 0.75);

    // Color: Black
    SolidCube *tail = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    tail->scale(2.0, 0.25, 0.25);
    tail->translate(-2.5, 0.875, 0.0);

    // Color: Black
    SolidCube *head = new SolidCube(
                new Material(   // Material
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 0.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 0.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    head->scale(1.5, 1.5, 1.5);
    head->translate(2.25, 0.75, 0.0);

    this->subObjects->push_back(body);
    this->subObjects->push_back(leg1);
    this->subObjects->push_back(leg2);
    this->subObjects->push_back(leg3);
    this->subObjects->push_back(leg4);
    this->subObjects->push_back(tail);
    this->subObjects->push_back(head);
}
