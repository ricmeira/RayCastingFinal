#include "solidcube.h"

SolidCube::SolidCube() : Object()
{

}

SolidCube::SolidCube(Material *material) : Object()
{
    this->material = material;
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    this->p1 = new Point(-0.5, -0.5, -0.5);
    this->p2 = new Point(-0.5, 0.5, -0.5);
    this->p3 = new Point(0.5, 0.5, -0.5);
    this->p4 = new Point(0.5, -0.5, -0.5);
    this->p5 = new Point(-0.5, -0.5, 0.5);
    this->p6 = new Point(-0.5, 0.5, 0.5);
    this->p7 = new Point(0.5, 0.5, 0.5);
    this->p8 = new Point(0.5, -0.5, 0.5);

    this->points->push_back(this->p1);
    this->points->push_back(this->p2);
    this->points->push_back(this->p3);
    this->points->push_back(this->p4);
    this->points->push_back(this->p5);
    this->points->push_back(this->p6);
    this->points->push_back(this->p7);
    this->points->push_back(this->p8);

    this->t1 = new Triangle(p1, p2, p3);
    this->t2 = new Triangle(p3, p4, p1);
    this->t3 = new Triangle(p8, p4, p3);
    this->t4 = new Triangle(p3, p7, p8);
    this->t5 = new Triangle(p5, p8, p7);
    this->t6 = new Triangle(p7, p6, p5);
    this->t7 = new Triangle(p1, p5, p6);
    this->t8 = new Triangle(p6, p2, p1);
    this->t9 = new Triangle(p6, p7, p3);
    this->t10 = new Triangle(p3, p2, p6);
    this->t11 = new Triangle(p1, p4, p8);
    this->t12 = new Triangle(p8, p5, p1);

    this->triangles->push_back(this->t1);
    this->triangles->push_back(this->t2);
    this->triangles->push_back(this->t3);
    this->triangles->push_back(this->t4);
    this->triangles->push_back(this->t5);
    this->triangles->push_back(this->t6);
    this->triangles->push_back(this->t7);
    this->triangles->push_back(this->t8);
    this->triangles->push_back(this->t9);
    this->triangles->push_back(this->t10);
    this->triangles->push_back(this->t11);
    this->triangles->push_back(this->t12);
}
