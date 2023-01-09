#pragma once
#include "Vector.h"

class Section {
public:
    Vector startPoint;
    Vector endPoint;

    Section(const Vector& startPoint, const Vector& endPoint);

    Vector IntersectionWithSection(Section section);
};

std::ostream& operator<<(std::ostream& strm, const Section& section);