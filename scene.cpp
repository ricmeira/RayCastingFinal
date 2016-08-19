#include "scene.h"

// Models
#include "Models/BlenderBarn.h"
#include "Models/BlenderCloud.h"
#include "Models/BlenderCow.h"
#include "Models/BlenderDog.h"
#include "Models/BlenderFarmer.h"
#include "Models/BlenderFence.h"
#include "Models/BlenderCube.h"
#include "Models/BlenderHay.h"
#include "Models/BlenderLamp.h"
#include "Models/BlenderMill.h"
#include "Models/BlenderSilo.h"
#include "Models/BlenderTerrain.h"
#include "Models/BlenderTree.h"

// My Models
#include "mybarn.h"
#include "mycloud.h"
#include "mycow.h"
#include "mydog.h"
#include "myfarmer.h"
#include "myfence.h"
#include "myhay.h"
#include "mylamp.h"
#include "mymill.h"
#include "mysilo.h"
#include "myterrain.h"
#include "mytree.h"
#include "mysun.h"

// Sombra Models
#include "Sombra/balcao.h"
#include "Sombra/base.h"
#include "Sombra/escritorio.h"
#include "Sombra/floor.h"
#include "Sombra/mesinha.h"
#include "Sombra/newwall.h"
#include "Sombra/roof.h"
#include "Sombra/sofa.h"
#include "Sombra/tv.h"
#include "Sombra/walls.h"

using namespace std;

Scene::Scene()
{
    this->objects = new vector<Object*>();
    this->lights = new vector<Light*>();
}

void Scene::addObject(Object *object)
{
    this->objects->push_back(object);
}

void Scene::addLight(Light *light)
{
    this->lights->push_back(light);
}

void Scene::setUpViewer()
{
    // Camera
    this->camera = new Camera(
//                new Point(0.0, 200.0, 350.0),  // Position
//                new Point(-175.0, 200.0, 350.0),  // Position
                new Point(0.0, 0.0, 350.0),  // Position
//                new Point(350.0, 1.0, 1.0),  // Position
//                new Point(0.0, 500.0, 1.0),  // Position
//                new Point(-125.0, 2.0, 1.0),  // Position
//                new Point(-400.0, 400.0, 1.0),  // Position
                new Point(0.0, 0.0, 0.0),   // Look At
                new Point(0.0, 1.0, 0.0)    // View Up
            );

    // Transform all objects from world to camera coordinates
    for (unsigned int i = 0; i < this->objects->size(); i++)
    {
        Object *object_i = this->objects->at(i);
        object_i->updatePointsToCamera(this->camera->mWorldToCamera);
    }

    // Window size
    int width = 15;
    int height = 15;

    // Frame size (in pixels)
    int n = 500;
    int m = 500;

    // Projection plane
    double projectionPlane = 35.0;

    // Deltas
    double deltaX = ( width * 1.0 ) / ( n * 1.0 );
    double deltaY = ( height * 1.0 ) / ( m * 1.0 );

    // Frame Buffer
    memset(frameBuffer, 0, sizeof(double) * n * m * 3);

    // Create a n x m mesh, centered at origin
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double xc = - ( width / 2.0 ) + ( deltaX / 2.0 ) + ( deltaX * i );
            double yc =  ( height / 2.0 ) - ( deltaY / 2.0 ) - ( deltaY * j );
            double zc = - projectionPlane;

            vec::fixed<3> direction;
            direction[0] = xc;
            direction[1] = yc;
            direction[2] = zc;

            Ray *ray = new Ray(
                        new Point(0.0, 0.0, 0.0), // Position
//                        this->camera->position, // Position
                        direction   // Direction
                    );

            Color *colorOfPixel = getColorOfPixel(ray);

            frameBuffer[i][j][0] = colorOfPixel->r;
            frameBuffer[i][j][1] = colorOfPixel->g;
            frameBuffer[i][j][2] = colorOfPixel->b;
        }
    }
}

Color* Scene::getColorOfPixel(Ray *ray)
{
    Object *object;
    Triangle *face;
    Point *interserctionPoint = this->getIntersection(ray, &object, &face);

    if (object != NULL && face != NULL && interserctionPoint != NULL)
    {
        // Ambience
        vec::fixed<3> intensityAmbience;
        intensityAmbience[0] = this->ambienceLight->intensity->r * object->material->reflectivityAmbience->r;
        intensityAmbience[1] = this->ambienceLight->intensity->g * object->material->reflectivityAmbience->g;
        intensityAmbience[2] = this->ambienceLight->intensity->b * object->material->reflectivityAmbience->b;

        // Diffuse
        vec::fixed<3> intensityDiffuse;
        intensityDiffuse[0] = 0.0;
        intensityDiffuse[1] = 0.0;
        intensityDiffuse[2] = 0.0;

        for (unsigned int i = 0; i < this->lights->size(); i++)
        {
            Light *light_i = this->lights->at(i);

            // Light source
            vec::fixed<3> f;
            f[0] = light_i->position->x;
            f[1] = light_i->position->y;
            f[2] = light_i->position->z;

            vec::fixed<3> vecIntersectionPoint;
            vecIntersectionPoint[0] = interserctionPoint->x;
            vecIntersectionPoint[1] = interserctionPoint->y;
            vecIntersectionPoint[2] = interserctionPoint->z;

            vec::fixed<3> l;
            l = normalise(f - vecIntersectionPoint);

            double ln;
            ln = max(dot(l, face->getNormal()), 0.0);

            intensityDiffuse[0] += light_i->intensity->r * object->material->reflectivityDiffuse->r * ln;
            intensityDiffuse[1] += light_i->intensity->g * object->material->reflectivityDiffuse->g * ln;
            intensityDiffuse[2] += light_i->intensity->b * object->material->reflectivityDiffuse->b * ln;
        }

        // Specular
        vec::fixed<3> intensitySpecular;
        intensitySpecular[0] = 0.0;
        intensitySpecular[1] = 0.0;
        intensitySpecular[2] = 0.0;

        for (unsigned int i = 0; i < this->lights->size(); i++)
        {
            Light *light_i = this->lights->at(i);

            // Light source
            vec::fixed<3> f;
            f[0] = light_i->position->x;
            f[1] = light_i->position->y;
            f[2] = light_i->position->z;

            vec::fixed<3> vecIntersectionPoint;
            vecIntersectionPoint[0] = interserctionPoint->x;
            vecIntersectionPoint[1] = interserctionPoint->y;
            vecIntersectionPoint[2] = interserctionPoint->z;

            vec::fixed<3> l;
            l = normalise(f - vecIntersectionPoint);

            vec::fixed<3> vecPosition;
            vecPosition[0] = ray->position->x;
            vecPosition[1] = ray->position->y;
            vecPosition[2] = ray->position->z;

            vec::fixed<3> v;
            v = normalise(vecPosition - vecIntersectionPoint);

            vec::fixed<3> r;
            r = ( ( 2 * dot(l, face->getNormal()) ) * face->getNormal() ) - l;

            double rv = max(dot(r, v), 0.0);

            intensitySpecular[0] += light_i->intensity->r * object->material->reflectivitySpecular->r * pow(rv, object->material->m);
            intensitySpecular[1] += light_i->intensity->g * object->material->reflectivitySpecular->g * pow(rv, object->material->m);
            intensitySpecular[2] += light_i->intensity->b * object->material->reflectivitySpecular->b * pow(rv, object->material->m);
        }

        vec::fixed<3> intensity;
        intensity = intensityAmbience + intensityDiffuse + intensitySpecular;
        intensity = round(intensity * 255.0);

        return new Color(min(intensity.at(0), 255.0), min(intensity.at(1), 255.0), min(intensity.at(2), 255.0));
    }

    // Sky blue
    return new Color(135.0, 206.0, 235.0);
}

Point* Scene::getIntersection(Ray *ray, Object **object, Triangle **face)
{
    *object = NULL;
    *face = NULL;

    Point *interserctionPoint = NULL;
    double minDistance = 1000000000;

    for (unsigned int i = 0; i < this->objects->size(); i++)
    {
        Object *object_i = this->objects->at(i);

        // Blender Model
        if (object_i->subObjects->size() == 0)
        {
            for (unsigned int j = 0; j < object_i->triangles->size(); j++)
            {
                Triangle *triangle_ij = object_i->triangles->at(j);
                Intersection *intersection = triangle_ij->getTriangleIntersection(ray);

                if ( ( intersection->u > -0.0001 ) &&
                     ( intersection->v > -0.0001 ) &&
                     ( ( 1.0 - ( intersection->u + intersection->v ) ) > -0.0001 && ( ( 1.0 - ( intersection->u + intersection->v ) ) < 1.0 ) ) )
                {
                    vec::fixed<3> pInt;
                    pInt[0] = ray->position->x + intersection->t * ( ray->direction.at(0) - ray->position->x );
                    pInt[1] = ray->position->y + intersection->t * ( ray->direction.at(1) - ray->position->y );
                    pInt[2] = ray->position->z + intersection->t * ( ray->direction.at(2) - ray->position->z );

                    vec::fixed<3> vecU;
                    vecU[0] = ray->direction.at(0) - pInt.at(0);
                    vecU[1] = ray->direction.at(1) - pInt.at(1);
                    vecU[2] = ray->direction.at(2) - pInt.at(2);

                    vec::fixed<3> pT;
                    pT = pInt + ( intersection->t * vecU );

                    if ( ( sqrt(pow(pT.at(0), 2.0) + pow(pT.at(1), 2.0) + pow(pT.at(2), 2.0)) ) > abs(minDistance) )
                    {
                        continue;
                    }
                    else
                    {
                        minDistance = sqrt(pow(pT.at(0), 2.0) + pow(pT.at(1), 2.0) + pow(pT.at(2), 2.0));
                        interserctionPoint = new Point(pInt.at(0), pInt.at(1), pInt.at(2));
                        *object = object_i;
                        *face = triangle_ij;
                    }
                }
            }
        }

        // My Square Model
        else
        {
            for (unsigned int j = 0; j < object_i->subObjects->size(); j++)
            {
                Object *cube_ij = object_i->subObjects->at(j);

                for (unsigned int k = 0; k < cube_ij->triangles->size(); k++)
                {
                    Triangle *triangle_ijk = cube_ij->triangles->at(k);
                    Intersection *intersection = triangle_ijk->getTriangleIntersection(ray);

                    if ( ( intersection->u > -0.0001 ) &&
                         ( intersection->v > -0.0001 ) &&
                         ( ( 1.0 - ( intersection->u + intersection->v ) ) > -0.0001 && ( ( 1.0 - ( intersection->u + intersection->v ) ) < 1.0 ) ) )
                    {
                        vec::fixed<3> pInt;
                        pInt[0] = ray->position->x + intersection->t * ( ray->direction.at(0) - ray->position->x );
                        pInt[1] = ray->position->y + intersection->t * ( ray->direction.at(1) - ray->position->y );
                        pInt[2] = ray->position->z + intersection->t * ( ray->direction.at(2) - ray->position->z );

                        vec::fixed<3> vecU;
                        vecU[0] = ray->direction.at(0) - pInt.at(0);
                        vecU[1] = ray->direction.at(1) - pInt.at(1);
                        vecU[2] = ray->direction.at(2) - pInt.at(2);

                        vec::fixed<3> pT;
                        pT = pInt + ( intersection->t * vecU );

                        if ( ( sqrt(pow(pT.at(0), 2.0) + pow(pT.at(1), 2.0) + pow(pT.at(2), 2.0)) ) > abs(minDistance) )
                        {
                            continue;
                        }
                        else
                        {
                            minDistance = sqrt(pow(pT.at(0), 2.0) + pow(pT.at(1), 2.0) + pow(pT.at(2), 2.0));
                            interserctionPoint = new Point(pInt.at(0), pInt.at(1), pInt.at(2));
                            *object = cube_ij;
                            *face = triangle_ijk;
                        }
                    }
                }
            }
        }
    }

    return interserctionPoint;
}

void Scene::draw()
{
    this->objects->clear();
    this->lights->clear();

    // ----- OBJECTS -----

    // Test Blender Model
    Object *blender = new Object(
                1,
                new Material(   // Material
                    new Color(0.0, 0.0, 1.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 1.0),   // Reflectivity Diffuse
                    new Color(1.0, 1.0, 0.0), // Reflectivity Specular
                    100.0   // M
                ),
                BlenderCubeVerts,    // Object points
                sizeof(BlenderCubeVerts)/sizeof(BlenderCubeVerts[0]) // Number of points
            );
    blender->translate(0.0, 0.0, 0.0);
    blender->scale(150.0, 2.0, 150.0);

    // Terrain
    Object *terrain = new MyTerrain(1);
    terrain->scale(150.0, 2.0, 150.0);

    // Fence
    Object *fence = new MyFence(2);
    fence->translate(-45.0, 3.0, -65.0);

    // Cow 1
    Object *cow1 = new MyCow(3);
    cow1->scale(2.0, 2.0, 2.0);
    cow1->rotateAxisY(90.0);
    cow1->translate(-55.0, 7.0, -55.0);

    // Cow 2
    Object *cow2 = new MyCow(4);
    cow2->scale(2.0, 2.0, 2.0);
    cow2->rotateAxisY(90.0);
    cow2->translate(-45.0, 7.0, -50.0);

    // Cow 3
    Object *cow3 = new MyCow(5);
    cow3->scale(2.0, 2.0, 2.0);
    cow3->rotateAxisY(135.0);
    cow3->translate(-32.5, 7.0, -40.0);

    // Cow 4
    Object *cow4 = new MyCow(6);
    cow4->scale(2.0, 2.0, 2.0);
    cow4->rotateAxisY(45.0);
    cow4->translate(-52.5, 7.0, -32.5);

    // Hay 1
    Object *hay1 = new MyHay(7);
    hay1->scale(10.0, 5.0, 10.0);
    hay1->translate(-60, 3.5, -15.0);

    // Hay 2
    Object *hay2 = new MyHay(8);
    hay2->scale(10.0, 5.0, 10.0);
    hay2->translate(-55.0, 3.5, -4.0);

    // Hay 3
    Object *hay3 = new MyHay(9);
    hay3->scale(10.0, 5.0, 10.0);
    hay3->translate(-49.0, 3.5, -15.0);

    // Hay 4
    Object *hay4 = new MyHay(10);
    hay4->scale(10.0, 5.0, 10.0);
    hay4->rotateAxisY(45.0);
    hay4->translate(-55.5, 5.0, -9.5);

    // Hay 5
    Object *hay5 = new MyHay(11);
    hay5->scale(10.0, 5.0, 10.0);
    hay5->rotateAxisY(22.5);
    hay5->translate(-32.5, 3.5, -9.5);

    // Tree 1
    Object *tree1 = new MyTree(12);
    tree1->scale(2.0, 2.0, 2.0);
    tree1->rotateAxisY(135.0);
    tree1->translate(-20.0, 11.0, -55.0);

    // Tree 2
    Object *tree2 = new MyTree(13);
    tree2->scale(2.0, 2.0, 2.0);
    tree2->rotateAxisY(22.5);
    tree2->translate(5.0, 11.0, -47.5);

    // Tree 3
    Object *tree3 = new MyTree(14);
    tree3->scale(2.0, 2.0, 2.0);
    tree3->translate(-25.0, 11.0, -15.0);

    // Mill
    Object *mill = new MyMill(15);
    mill->rotateAxisY(135.0);
    mill->translate(42.5, 13.5, -40.0);

    // Barn
    Object *barn = new MyBarn(16);
    barn->scale(0.9, 0.9, 0.9);
    barn->rotateAxisY(215.0);
    barn->translate(35.0, 16.75, 30.0);

    // Silo
    Object *silo = new MySilo(17);
    silo->scale(0.7, 1.0, 0.7);
    silo->rotateAxisY(215.0);
    silo->translate(5.0, 21.0, 50.0);

    // Lamp 1
    Object *lamp1 = new MyLamp(18);
    lamp1->scale(2.0, 2.0, 2.0);
    lamp1->translate(-15.0, 9.0, -30.0);

    // Lamp 2
    Object *lamp2 = new MyLamp(19);
    lamp2->scale(2.0, 2.0, 2.0);
    lamp2->translate(20.0, 10.0, -60.0);

    // Lamp 3
    Object *lamp3 = new MyLamp(20);
    lamp3->scale(2.0, 2.0, 2.0);
    lamp3->translate(35.0, 10.0, -5.0);

    // Lamp 4
    Object *lamp4 = new MyLamp(21);
    lamp4->scale(2.0, 2.0, 2.0);
    lamp4->translate(-15.0, 10.0, 35.0);

    // Lamp 5
    Object *lamp5 = new MyLamp(22);
    lamp5->scale(2.0, 2.0, 2.0);
    lamp5->translate(-60.0, 10.0, 10.0);

    // Farmer
    Object *farmer = new MyFarmer(23);
    farmer->rotateAxisY(135.0);
    farmer->translate(-45.0, 3.5, 40.0);

    // Dog 1
    Object *dog1 = new MyDog(24);
    dog1->scale(2.0, 2.0, 2.0);
    dog1->rotateAxisY(45.0);
    dog1->translate(-40.0, 6.0, 50.0);

    // Dog 2
    Object *dog2 = new MyDog(25);
    dog2->scale(2.0, 2.0, 2.0);
    dog2->rotateAxisY(135.0);
    dog2->translate(0.0, 6.0, 0.0);

    // Cloud
    Object *cloud1 = new MyCloud(26);
    cloud1->scale(25.0, 5.0, 5.0);
    cloud1->translate(-35.0, 75.0, -55.0);

    // Cloud
    Object *cloud2 = new MyCloud(27);
    cloud2->scale(20.0, 4.0, 4.0);
    cloud2->translate(37.5, 73.0, -40.0);

    // Cloud
    Object *cloud3 = new MyCloud(28);
    cloud3->scale(32.5, 3.0, 3.0);
    cloud3->translate(-20.0, 74.0, 47.5);

    // Sun
    Object *sun = new MySun(29);
    sun->scale(5.0, 5.0, 5.0);
    sun->translate(60.0, 80.0, -60.0);

    // Test Sombra Models
    Object *balcao = new Object(
                1,
                new Material(   // Material
                    new Color(0.0, 0.0, 1.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 1.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 1.0), // Reflectivity Specular
                    100.0   // M
                ),
                balcaoVerts,    // Object points
                sizeof(balcaoVerts)/sizeof(balcaoVerts[0]) // Number of points
            );
    balcao->translate(0.0, 0.0, 0.0);
    balcao->scale(5.0, 5.0, 5.0);
    balcao->translate(0.0, 10.0, 0.0);

    Object *base = new Object(
                1,
                new Material(   // Material
                    new Color(0.0, 0.0, 1.0),   // Reflectivity Ambience
                    new Color(0.0, 0.0, 1.0),   // Reflectivity Diffuse
                    new Color(0.0, 0.0, 1.0), // Reflectivity Specular
                    100.0   // M
                ),
                baseVerts,    // Object points
                sizeof(baseVerts)/sizeof(baseVerts[0]) // Number of points
            );
    base->translate(0.0, 0.0, 0.0);
    base->scale(5.0, 5.0, 5.0);

//    this->addObject(blender);
//    this->addObject(terrain);
//    this->addObject(fence);
//    this->addObject(cow1);
//    this->addObject(cow2);
//    this->addObject(cow3);
//    this->addObject(cow4);
//    this->addObject(hay1);
//    this->addObject(hay2);
//    this->addObject(hay3);
//    this->addObject(hay4);
//    this->addObject(hay5);
//    this->addObject(tree1);
//    this->addObject(tree2);
//    this->addObject(tree3);
//    this->addObject(mill);
//    this->addObject(barn);
//    this->addObject(silo);
//    this->addObject(lamp1);
//    this->addObject(lamp2);
//    this->addObject(lamp3);
//    this->addObject(lamp4);
//    this->addObject(lamp5);
//    this->addObject(farmer);
//    this->addObject(dog1);
//    this->addObject(dog2);
//    this->addObject(cloud1);
//    this->addObject(cloud2);
//    this->addObject(cloud3);
//    this->addObject(sun);
    this->addObject(balcao);
    this->addObject(base);

    // ----- LIGHTS -----

    // Ambience light
    this->ambienceLight = new Light( // White
                new Point(0.0, 300.0, 0.0), // Position
                new Color(1.0, 1.0, 1.0)    // Intensity
            );

    // External lights
    Light *light1 = new Light( // LightYellow
                new Point(60.0, 80.0, -60.0),   // Position
                new Color(1.0, 1.0, 0.878)  // Intensity
            );

    Light *light2 = new Light( // White
                new Point(80.0, 20.0, 40.0),    // Position
                new Color(1.0, 1.0, 1.0)    // Intensity
            );

    this->addLight(light1);
//    this->addLight(light2);

    this->setUpViewer();
}

