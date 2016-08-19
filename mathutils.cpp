#include "mathutils.h"

MathUtils::MathUtils()
{
}

double MathUtils::degreeToRadians(double angle)
{
    return angle * ( PI / 180.0 );
}
