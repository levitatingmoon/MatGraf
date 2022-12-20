#pragma once
#include "Vector.h"

class Section {
    Vector startPoint;
    Vector endPoint;
public:
    Section(const Vector& startPoint, const Vector& endPoint);

    Vector IntersectionPointWithSegment(Section segment);
};

