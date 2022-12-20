#pragma once
#include "Vector.h"
#include "Line.h"

class Plane {
public:
    float a, b, c, d;
    Vector normal;
    Plane(float a, float b, float c, float d);

    Line IntersectionWithLine(Plane plane);
    float AnglePlane(Plane plane);

};

