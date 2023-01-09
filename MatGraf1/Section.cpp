#include "Section.h"
#include "Line.h"

Section::Section(const Vector& startPoint, const Vector& endPoint)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
}

Vector Section::IntersectionWithSection(Section section) {
    Vector qMinusP = section.startPoint;
    qMinusP -= startPoint;
    Vector s = section.endPoint;
    s -= section.startPoint;
    Vector r = endPoint;
    r -= startPoint;

    Vector result = startPoint;
    result += r;
    result.mult(qMinusP.cross(s).length() / r.cross(s).length());

    return result;
}
/*
std::ostream& operator<<(std::ostream& strm, const Section& section) {
    return strm << section.startPoint.x << " " << section.endPoint;
}
*/