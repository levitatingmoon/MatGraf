#pragma once
#include "Vector.h"
#include "Line.h"

class Line;

class Plane {
public:
    float a, b, c, d;
    Vector normal;
    Plane(float a, float b, float c, float d);

    Line IntersectionWithPlane(Plane plane);
    float AnglePlane(Plane plane);

};

std::ostream& operator<<(std::ostream& strm, const Plane& plane);
