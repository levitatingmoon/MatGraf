#pragma once
#include "Vector.h"
#include "Line.h"

#include <vector>

class Sphere {
    Vector center;
    float radius;
public:
    Sphere(const Vector& center, float radius);

    std::vector<Vector> IntersectionPointWithLine(Line line);
};


