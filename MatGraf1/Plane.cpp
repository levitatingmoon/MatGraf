#include "Plane.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

Plane::Plane()
{
}

Plane::Plane(Vector A, Vector B, Vector C, Vector D) {
    Vector v1 = B;
    v1 -= A;
    Vector v2 = C;
    v2 -= B;
    normal = v1.cross(v2);
    normal.mult( - 1);
    Vector negativeNormal = normal;
    negativeNormal.mult(-1);
    a = normal.x;
    b = normal.y;
    c = normal.z;
    d = negativeNormal.dotProduct(A);

}

Plane::Plane(float a, float b, float c, float d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    Vector vec{a,b,c};
    normal = vec;
}


Line Plane::IntersectionWithPlane(Plane plane)
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

std::ostream& operator<<(std::ostream& strm, const Plane& plane) {

    return strm << plane.a << " " <<plane.b << " " << plane.c << " " << plane.d;
}