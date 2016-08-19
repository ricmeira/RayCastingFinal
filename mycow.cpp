#include "mycow.h"

MyCow::MyCow() : Object()
{

}

MyCow::MyCow(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Peru
    SolidCube *body = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    body->scale(3.0, 2.0, 2.0);

    // Color: Peru
    SolidCube *leg1 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg1->scale(0.5, 2.0, 0.5);
    leg1->translate(-1.25, -2.0, -0.75);

    // Color: Peru
    SolidCube *leg2 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg2->scale(0.5, 2.0, 0.5);
    leg2->translate(1.25, -2.0, -0.75);

    // Color: Peru
    SolidCube *leg3 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg3->scale(0.5, 2.0, 0.5);
    leg3->translate(-1.25, -2.0, 0.75);

    // Color: Peru
    SolidCube *leg4 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    leg4->scale(0.5, 2.0, 0.5);
    leg4->translate(1.25, -2.0, 0.75);

    // Color: Peru
    SolidCube *head = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    head->scale(1.5, 1.5, 1.5);
    head->translate(2.25, 0.75, 0.0);

    // Color: White
    SolidCube *horn1 = new SolidCube(
                new Material(   // Material
                    new Color(1.0, 1.0, 1.0),   // Reflectivity Ambience
                    new Color(1.0, 1.0, 1.0),   // Reflectivity Diffuse
                    new Color(1.0, 1.0, 1.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    horn1->scale(0.25, 0.5, 0.25);
    horn1->translate(2.25, 1.5, 0.875);

    // Color: White
    SolidCube *horn2 = new SolidCube(
                new Material(   // Material
                    new Color(1.0, 1.0, 1.0),   // Reflectivity Ambience
                    new Color(1.0, 1.0, 1.0),   // Reflectivity Diffuse
                    new Color(1.0, 1.0, 1.0), // Reflectivity Specular
                    100.0   // M
                )
            );
    horn2->scale(0.25, 0.5, 0.25);
    horn2->translate(2.25, 1.5, -0.875);

    this->subObjects->push_back(body);
    this->subObjects->push_back(leg1);
    this->subObjects->push_back(leg2);
    this->subObjects->push_back(leg3);
    this->subObjects->push_back(leg4);
    this->subObjects->push_back(head);
    this->subObjects->push_back(horn1);
    this->subObjects->push_back(horn2);
}
