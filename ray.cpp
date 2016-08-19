#include "ray.h"

Ray::Ray()
{

}

Ray::Ray(Point *position, vec &direction)
{
    this->position = position;
    this->direction = direction;
}
