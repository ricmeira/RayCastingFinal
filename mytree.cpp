#include "mytree.h"
#include "solidcube.h"
#include "object.h"

MyTree::MyTree() : Object()
{

}

MyTree::MyTree(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: SaddleBrown
    SolidCube *body = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );

    body->scale(2.0, 10.0, 2.0);

    // Color: ForestGreen
    SolidCube *leaves = new SolidCube(
                new Material(   // Material
                    new Color(0.133, 0.545, 0.133),   // Reflectivity Ambience
                    new Color(0.133, 0.545, 0.133),   // Reflectivity Diffuse
                    new Color(0.133, 0.545, 0.133), // Reflectivity Specular
                    100.0   // M
                )
            );

    leaves->scale(9.0, 7.5, 6.0);
    leaves->translate(0.0, 7.0, 0.0);

    this->subObjects->push_back(body);
    this->subObjects->push_back(leaves);
}
