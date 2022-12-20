#include "Section.h"
#include "Line.h"

Section::Section(const Vector& startPoint, const Vector& endPoint)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
}

Vector Section::IntersectionPointWithSegment(Section segment) {
    Vector qMinusP = segment.startPoint;
    qMinusP -= startPoint;
    Vector s = segment.endPoint;
    s -= segment.startPoint;
    Vector r = endPoint;
    r -= startPoint;

    Vector result = startPoint;
    result += r;
    result.mult(qMinusP.cross(s).length() / r.cross(s).length());

    return result;
}