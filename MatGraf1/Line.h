#pragma once
#include "Vector.h"
#include "Plane.h"

class Line {
public:
    Vector direction;
    Vector point;

    Line();
    Line(const Vector& point, const Vector& direction);

    Vector IntersectionWithLine(Line line);
    Vector IntersectionWithPlane(Plane plane);

    float AngleLine(Line line);
    float AnglePlane(Plane plane);

};

