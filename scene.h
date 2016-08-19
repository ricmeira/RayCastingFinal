#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <cmath>

#include "camera.h"
#include "object.h"
#include "solidcube.h"
#include "light.h"
#include "ray.h"
#include "triangle.h"
#include "intersection.h"

using namespace std;

class Scene
{
public:
    Camera *camera;
    Light *ambienceLight;
    vector<Object*> *objects;
    vector<Light*> *lights;
    double frameBuffer[501][501][3];

    Scene();

    void addObject(Object *object);
    void addLight(Light *light);
    void setUpViewer();
    Color* getColorOfPixel(Ray *ray);
    Point* getIntersection(Ray *ray, Object **object, Triangle **face);
    void draw();
};

#endif // SCENE_H
