#include "Plane.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

Plane::Plane(float a, float b, float c, float d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    Vector vec{a,b,c};
    normal = vec;
}

Line Plane::IntersectionWithLine(Plane plane)
{
    Line line;
    line.direction = normal.cross(plane.normal);
    float dirLen = line.direction.length() * line.direction.length();
    if (dirLen == 0.0f) {
        return Line({0,0,0},{0,0,0});
    }
    
    float value = (plane.b * this->d - this->b * plane.d) / (this->b * plane.c - plane.b * this->c);
    line.point.x = 0;
    line.point.y = (-this->c * value - this->d) / this->b;
    line.point.z = value;

    return line;
}

float Plane::AnglePlane(Plane plane)
{
 
    Vector v4(normal.x,normal.y,normal.z);
    Vector v5(plane.normal.x,plane.normal.y,plane.normal.z);
    float dotProduct = v4.dotProduct(v5);
    float l4 = v4.length();
    float l5 = v5.length();
    float cos = dotProduct / (l4 * l5);
    float result = acos(cos) * 180 / M_PI;

    return result;
}
