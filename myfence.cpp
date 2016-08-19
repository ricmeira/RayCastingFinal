#include "myfence.h"
#include "solidcube.h"
#include "object.h"

MyFence::MyFence() : Object()
{

}

MyFence::MyFence(int id) : Object()
{
    this->id = id;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    // Color: Peru
    SolidCube *horizontalWood1 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood1->scale(40.0, 2.0, 2.0);

    // Color: Peru
    SolidCube *horizontalWood2 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood2->scale(40.0, 2.0, 2.0);
    horizontalWood2->translate(0.0, 4.0, 0.0);

    // Color: Peru
    SolidCube *horizontalWood3 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood3->scale(40.0, 2.0, 2.0);
    horizontalWood3->rotateAxisY(90.0);
    horizontalWood3->translate(20.0, 0.0, 20.0);

    // Color: Peru
    SolidCube *horizontalWood4 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood4->scale(40.0, 2.0, 2.0);
    horizontalWood4->rotateAxisY(90.0);
    horizontalWood4->translate(20.0, 4.0, 20.0);

    // Color: Peru
    SolidCube *horizontalWood5 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood5->scale(40.0, 2.0, 2.0);
    horizontalWood5->translate(0.0, 0.0, 40.0);

    // Color: Peru
    SolidCube *horizontalWood6 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood6->scale(40.0, 2.0, 2.0);
    horizontalWood6->translate(0.0, 4.0, 40.0);

    // Color: Peru
    SolidCube *horizontalWood7 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood7->scale(40.0, 2.0, 2.0);
    horizontalWood7->rotateAxisY(90.0);
    horizontalWood7->translate(-20.0, 0.0, 20.0);

    // Color: Peru
    SolidCube *horizontalWood8 = new SolidCube(
                new Material(   // Material
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Ambience
                    new Color(0.804, 0.522, 0.247),   // Reflectivity Diffuse
                    new Color(0.804, 0.522, 0.247), // Reflectivity Specular
                    100.0   // M
                )
            );
    horizontalWood8->scale(40.0, 2.0, 2.0);
    horizontalWood8->rotateAxisY(90.0);
    horizontalWood8->translate(-20.0, 4.0, 20.0);

    // Color: SaddleBrown
    SolidCube *verticalWood1 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood1->scale(4.0, 10.0, 4.0);
    verticalWood1->translate(-20.0, 2.0, 0.0);

    // Color: SaddleBrown
    SolidCube *verticalWood2 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood2->scale(4.0, 10.0, 4.0);
    verticalWood2->translate(0.0, 2.0, 0.0);

    // Color: SaddleBrown
    SolidCube *verticalWood3 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood3->scale(4.0, 10.0, 4.0);
    verticalWood3->translate(20.0, 2.0, 0.0);

    // Color: SaddleBrown
    SolidCube *verticalWood4 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood4->scale(4.0, 10.0, 4.0);
    verticalWood4->translate(20.0, 2.0, 20.0);

    // Color: SaddleBrown
    SolidCube *verticalWood5 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood5->scale(4.0, 10.0, 4.0);
    verticalWood5->translate(20.0, 2.0, 40.0);

    // Color: SaddleBrown
    SolidCube *verticalWood6 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood6->scale(4.0, 10.0, 4.0);
    verticalWood6->translate(0.0, 2.0, 40.0);

    // Color: SaddleBrown
    SolidCube *verticalWood7 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood7->scale(4.0, 10.0, 4.0);
    verticalWood7->translate(-20.0, 2.0, 40.0);

    // Color: SaddleBrown
    SolidCube *verticalWood8 = new SolidCube(
                new Material(   // Material
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Ambience
                    new Color(0.545, 0.271, 0.075),   // Reflectivity Diffuse
                    new Color(0.545, 0.271, 0.075), // Reflectivity Specular
                    100.0   // M
                )
            );
    verticalWood8->scale(4.0, 10.0, 4.0);
    verticalWood8->translate(-20.0, 2.0, 20.0);

    this->subObjects->push_back(horizontalWood1);
    this->subObjects->push_back(horizontalWood2);
    this->subObjects->push_back(horizontalWood3);
    this->subObjects->push_back(horizontalWood4);
    this->subObjects->push_back(horizontalWood5);
    this->subObjects->push_back(horizontalWood6);
    this->subObjects->push_back(horizontalWood7);
    this->subObjects->push_back(horizontalWood8);
    this->subObjects->push_back(verticalWood1);
    this->subObjects->push_back(verticalWood2);
    this->subObjects->push_back(verticalWood3);
    this->subObjects->push_back(verticalWood4);
    this->subObjects->push_back(verticalWood5);
    this->subObjects->push_back(verticalWood6);
    this->subObjects->push_back(verticalWood7);
    this->subObjects->push_back(verticalWood8);
}
