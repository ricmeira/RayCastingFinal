#include "object.h"

using namespace std;

Object::Object()
{

}

Object::Object(int id, Material *material, float objectPoints[], int arrayLength)
{
    this->subObjects = new vector<Object*>;
    this->points = new vector<Point*>();
    this->triangles = new vector<Triangle*>();

    this->id = id;
    this->material = material;

    for (int i = 0; i < arrayLength; i += 3)
    {
        double x = objectPoints[i];
        double y = objectPoints[i + 1];
        double z = objectPoints[i + 2];

        Point *point = new Point(x, y, z);

        this->points->push_back(point);
    }

    for (unsigned int i = 0; i < this->points->size(); i += 3)
    {
        Point *p1 = this->points->at(i);
        Point *p2 = this->points->at(i + 1);
        Point *p3 = this->points->at(i + 2);

        Triangle *face = new Triangle(p1, p2, p3);

        this->triangles->push_back(face);
    }
}

void Object::updatePointsToCamera(mat &matrixWorldToCamera)
{
    // Blender Model
    if (this->subObjects->size() == 0)
    {
        for (unsigned int i = 0; i < this->points->size(); i++)
        {
            Point *point = this->points->at(i);

            vec::fixed<4> vectorPoint;
            vectorPoint[0] = point->x;
            vectorPoint[1] = point->y;
            vectorPoint[2] = point->z;
            vectorPoint[3] = 1.0;

            mat::fixed<4, 1> matrixPoint;
            matrixPoint = matrixWorldToCamera * vectorPoint;

            point->x = matrixPoint.at(0, 0);
            point->y = matrixPoint.at(1, 0);
            point->z = matrixPoint.at(2, 0);
        }
    }

    // My Square Model
    else
    {
        for (unsigned int i = 0; i < this->subObjects->size(); i++)
        {
            Object *cube_i = this->subObjects->at(i);

            for (unsigned int j = 0; j < cube_i->points->size(); j++)
            {
                Point *point = cube_i->points->at(j);

                vec::fixed<4> vectorPoint;
                vectorPoint[0] = point->x;
                vectorPoint[1] = point->y;
                vectorPoint[2] = point->z;
                vectorPoint[3] = 1.0;

                mat::fixed<4, 1> matrixPoint;
                matrixPoint = matrixWorldToCamera * vectorPoint;

                point->x = matrixPoint.at(0, 0);
                point->y = matrixPoint.at(1, 0);
                point->z = matrixPoint.at(2, 0);
            }
        }
    }
}

void Object::scale(double scaleX, double scaleY, double scaleZ)
{
    mat::fixed<4, 4> matrixScale;
    matrixScale(0, 0) = scaleX;
    matrixScale(0, 1) = 0.0;
    matrixScale(0, 2) = 0.0;
    matrixScale(0, 3) = 0.0;

    matrixScale(1, 0) = 0.0;
    matrixScale(1, 1) = scaleY;
    matrixScale(1, 2) = 0.0;
    matrixScale(1, 3) = 0.0;

    matrixScale(2, 0) = 0.0;
    matrixScale(2, 1) = 0.0;
    matrixScale(2, 2) = scaleZ;
    matrixScale(2, 3) = 0.0;

    matrixScale(3, 0) = 0.0;
    matrixScale(3, 1) = 0.0;
    matrixScale(3, 2) = 0.0;
    matrixScale(3, 3) = 1.0;

    // Blender Model
    if (this->subObjects->size() == 0)
    {
        for (unsigned int i = 0; i < this->points->size(); i++)
        {
            Point *point = this->points->at(i);

            vec::fixed<4> vectorPoint;
            vectorPoint[0] = point->x;
            vectorPoint[1] = point->y;
            vectorPoint[2] = point->z;
            vectorPoint[3] = 1.0;

            mat::fixed<4, 1> matrixPoint;
            matrixPoint = matrixScale * vectorPoint;

            point->x = matrixPoint.at(0, 0);
            point->y = matrixPoint.at(1, 0);
            point->z = matrixPoint.at(2, 0);
        }
    }

    // My Square Model
    else
    {
        for (unsigned int i = 0; i < this->subObjects->size(); i++)
        {
            Object *cube_i = this->subObjects->at(i);

            for (unsigned int j = 0; j < cube_i->points->size(); j++)
            {
                Point *point = cube_i->points->at(j);

                vec::fixed<4> vectorPoint;
                vectorPoint[0] = point->x;
                vectorPoint[1] = point->y;
                vectorPoint[2] = point->z;
                vectorPoint[3] = 1.0;

                mat::fixed<4, 1> matrixPoint;
                matrixPoint = matrixScale * vectorPoint;

                point->x = matrixPoint.at(0, 0);
                point->y = matrixPoint.at(1, 0);
                point->z = matrixPoint.at(2, 0);
            }
        }
    }
}

void Object::rotateAxisX(double angle)
{
    mat::fixed<4, 4> matrixRotation;
    matrixRotation(0, 0) = 1.0;
    matrixRotation(0, 1) = 0.0;
    matrixRotation(0, 2) = 0.0;
    matrixRotation(0, 3) = 0.0;

    matrixRotation(1, 0) = 0.0;
    matrixRotation(1, 1) = cos(MathUtils::degreeToRadians(angle));
    matrixRotation(1, 2) = -sin(MathUtils::degreeToRadians(angle));
    matrixRotation(1, 3) = 0.0;

    matrixRotation(2, 0) = 0.0;
    matrixRotation(2, 1) = sin(MathUtils::degreeToRadians(angle));
    matrixRotation(2, 2) = cos(MathUtils::degreeToRadians(angle));
    matrixRotation(2, 3) = 0.0;

    matrixRotation(3, 0) = 0.0;
    matrixRotation(3, 1) = 0.0;
    matrixRotation(3, 2) = 0.0;
    matrixRotation(3, 3) = 1.0;

    // Blender Model
    if (this->subObjects->size() == 0)
    {
        for (unsigned int i = 0; i < this->points->size(); i++)
        {
            Point *point = this->points->at(i);

            vec::fixed<4> vectorPoint;
            vectorPoint[0] = point->x;
            vectorPoint[1] = point->y;
            vectorPoint[2] = point->z;
            vectorPoint[3] = 1.0;

            mat::fixed<4, 1> matrixPoint;
            matrixPoint = matrixRotation * vectorPoint;

            point->x = matrixPoint.at(0, 0);
            point->y = matrixPoint.at(1, 0);
            point->z = matrixPoint.at(2, 0);
        }
    }

    // My Square Model
    else
    {
        for (unsigned int i = 0; i < this->subObjects->size(); i++)
        {
            Object *cube_i = this->subObjects->at(i);

            for (unsigned int j = 0; j < cube_i->points->size(); j++)
            {
                Point *point = cube_i->points->at(j);

                vec::fixed<4> vectorPoint;
                vectorPoint[0] = point->x;
                vectorPoint[1] = point->y;
                vectorPoint[2] = point->z;
                vectorPoint[3] = 1.0;

                mat::fixed<4, 1> matrixPoint;
                matrixPoint = matrixRotation * vectorPoint;

                point->x = matrixPoint.at(0, 0);
                point->y = matrixPoint.at(1, 0);
                point->z = matrixPoint.at(2, 0);
            }
        }
    }
}

void Object::rotateAxisY(double angle)
{
    mat::fixed<4, 4> matrixRotation;
    matrixRotation(0, 0) = cos(MathUtils::degreeToRadians(angle));
    matrixRotation(0, 1) = 0.0;
    matrixRotation(0, 2) = sin(MathUtils::degreeToRadians(angle));
    matrixRotation(0, 3) = 0.0;

    matrixRotation(1, 0) = 0.0;
    matrixRotation(1, 1) = 1.0;
    matrixRotation(1, 2) = 0.0;
    matrixRotation(1, 3) = 0.0;

    matrixRotation(2, 0) = -sin(MathUtils::degreeToRadians(angle));
    matrixRotation(2, 1) = 0.0;
    matrixRotation(2, 2) = cos(MathUtils::degreeToRadians(angle));
    matrixRotation(2, 3) = 0.0;

    matrixRotation(3, 0) = 0.0;
    matrixRotation(3, 1) = 0.0;
    matrixRotation(3, 2) = 0.0;
    matrixRotation(3, 3) = 1.0;

    // Blender Model
    if (this->subObjects->size() == 0)
    {
        for (unsigned int i = 0; i < this->points->size(); i++)
        {
            Point *point = this->points->at(i);

            vec::fixed<4> vectorPoint;
            vectorPoint[0] = point->x;
            vectorPoint[1] = point->y;
            vectorPoint[2] = point->z;
            vectorPoint[3] = 1.0;

            mat::fixed<4, 1> matrixPoint;
            matrixPoint = matrixRotation * vectorPoint;

            point->x = matrixPoint.at(0, 0);
            point->y = matrixPoint.at(1, 0);
            point->z = matrixPoint.at(2, 0);
        }
    }

    // My Square Model
    else
    {
        for (unsigned int i = 0; i < this->subObjects->size(); i++)
        {
            Object *cube_i = this->subObjects->at(i);

            for (unsigned int j = 0; j < cube_i->points->size(); j++)
            {
                Point *point = cube_i->points->at(j);

                vec::fixed<4> vectorPoint;
                vectorPoint[0] = point->x;
                vectorPoint[1] = point->y;
                vectorPoint[2] = point->z;
                vectorPoint[3] = 1.0;

                mat::fixed<4, 1> matrixPoint;
                matrixPoint = matrixRotation * vectorPoint;

                point->x = matrixPoint.at(0, 0);
                point->y = matrixPoint.at(1, 0);
                point->z = matrixPoint.at(2, 0);
            }
        }
    }
}

void Object::rotateAxisZ(double angle)
{
    mat::fixed<4, 4> matrixRotation;
    matrixRotation(0, 0) = cos(MathUtils::degreeToRadians(angle));
    matrixRotation(0, 1) = -sin(MathUtils::degreeToRadians(angle));
    matrixRotation(0, 2) = 0.0;
    matrixRotation(0, 3) = 0.0;

    matrixRotation(1, 0) = sin(MathUtils::degreeToRadians(angle));
    matrixRotation(1, 1) = cos(MathUtils::degreeToRadians(angle));
    matrixRotation(1, 2) = 0.0;
    matrixRotation(1, 3) = 0.0;

    matrixRotation(2, 0) = 0.0;
    matrixRotation(2, 1) = 0.0;
    matrixRotation(2, 2) = 1.0;
    matrixRotation(2, 3) = 0.0;

    matrixRotation(3, 0) = 0.0;
    matrixRotation(3, 1) = 0.0;
    matrixRotation(3, 2) = 0.0;
    matrixRotation(3, 3) = 1.0;

    // Blender Model
    if (this->subObjects->size() == 0)
    {
        for (unsigned int i = 0; i < this->points->size(); i++)
        {
            Point *point = this->points->at(i);

            vec::fixed<4> vectorPoint;
            vectorPoint[0] = point->x;
            vectorPoint[1] = point->y;
            vectorPoint[2] = point->z;
            vectorPoint[3] = 1.0;

            mat::fixed<4, 1> matrixPoint;
            matrixPoint = matrixRotation * vectorPoint;

            point->x = matrixPoint.at(0, 0);
            point->y = matrixPoint.at(1, 0);
            point->z = matrixPoint.at(2, 0);
        }
    }

    // My Square Model
    else
    {
        for (unsigned int i = 0; i < this->subObjects->size(); i++)
        {
            Object *cube_i = this->subObjects->at(i);

            for (unsigned int j = 0; j < cube_i->points->size(); j++)
            {
                Point *point = cube_i->points->at(j);

                vec::fixed<4> vectorPoint;
                vectorPoint[0] = point->x;
                vectorPoint[1] = point->y;
                vectorPoint[2] = point->z;
                vectorPoint[3] = 1.0;

                mat::fixed<4, 1> matrixPoint;
                matrixPoint = matrixRotation * vectorPoint;

                point->x = matrixPoint.at(0, 0);
                point->y = matrixPoint.at(1, 0);
                point->z = matrixPoint.at(2, 0);
            }
        }
    }
}

void Object::translate(double translateX, double translateY, double translateZ)
{
    mat::fixed<4, 4> matrixTranslation;
    matrixTranslation(0, 0) = 1.0;
    matrixTranslation(0, 1) = 0.0;
    matrixTranslation(0, 2) = 0.0;
    matrixTranslation(0, 3) = translateX;

    matrixTranslation(1, 0) = 0.0;
    matrixTranslation(1, 1) = 1.0;
    matrixTranslation(1, 2) = 0.0;
    matrixTranslation(1, 3) = translateY;

    matrixTranslation(2, 0) = 0.0;
    matrixTranslation(2, 1) = 0.0;
    matrixTranslation(2, 2) = 1.0;
    matrixTranslation(2, 3) = translateZ;

    matrixTranslation(3, 0) = 0.0;
    matrixTranslation(3, 1) = 0.0;
    matrixTranslation(3, 2) = 0.0;
    matrixTranslation(3, 3) = 1.0;

    // Blender Model
    if (this->subObjects->size() == 0)
    {
        for (unsigned int i = 0; i < this->points->size(); i++)
        {
            Point *point = this->points->at(i);

            vec::fixed<4> vectorPoint;
            vectorPoint[0] = point->x;
            vectorPoint[1] = point->y;
            vectorPoint[2] = point->z;
            vectorPoint[3] = 1.0;

            mat::fixed<4, 1> matrixPoint;
            matrixPoint = matrixTranslation * vectorPoint;

            point->x = matrixPoint.at(0, 0);
            point->y = matrixPoint.at(1, 0);
            point->z = matrixPoint.at(2, 0);
        }
    }

    // My Square Model
    else
    {
        for (unsigned int i = 0; i < this->subObjects->size(); i++)
        {
            Object *cube_i = this->subObjects->at(i);

            for (unsigned int j = 0; j < cube_i->points->size(); j++)
            {
                Point *point = cube_i->points->at(j);

                vec::fixed<4> vectorPoint;
                vectorPoint[0] = point->x;
                vectorPoint[1] = point->y;
                vectorPoint[2] = point->z;
                vectorPoint[3] = 1.0;

                mat::fixed<4, 1> matrixPoint;
                matrixPoint = matrixTranslation * vectorPoint;

                point->x = matrixPoint.at(0, 0);
                point->y = matrixPoint.at(1, 0);
                point->z = matrixPoint.at(2, 0);
            }
        }
    }
}
