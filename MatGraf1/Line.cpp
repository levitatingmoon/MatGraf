#include "Line.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

Line::Line()
{
}

Line::Line(const Vector& point, const Vector& direction)
{
	this->point = point;
	this->direction = direction;
}

Vector Line::IntersectionWithLine(Line line)
{
	Vector delta = line.point;
	delta -= point;
	Vector cross = direction.cross(line.direction);

	if (std::abs(delta.dotProduct(cross)) > 0.001) {
		return { 0,0,0 };
	}

	float m2 = direction.cross(line.direction).length();
	m2 *= m2;

	Vector cross1 = delta.cross(line.direction);
	Vector cross2 = direction.cross(line.direction);
	float s = cross1.dotProduct(cross2) / m2;

	Vector result = point;
	result += direction;
	result.mult(s);
	return result;

}

Vector Line::IntersectionWithPlane(Plane plane)
{
	float ts = plane.a * (direction.x) + plane.b * (direction.y) + plane.c * (direction.z);
	float values = -plane.d - (plane.a * (point.x) + plane.b * (point.y) + plane.c * (point.z));
	float t = values / ts;

	return Vector(point.x + direction.x * t, point.y + direction.y * t, point.z + direction.z * t);
}

float Line::AngleLine(Line line)
{
	Vector v4(direction.x, direction.y, direction.z);
	Vector v5(line.direction.x, line.direction.y, line.direction.z);
	float dotProduct = v4.dotProduct(v5);
	float l4 = v4.length();
	float l5 = v5.length();
	float cos = dotProduct / (l4 * l5);
	float result = acos(cos) * 180 / M_PI;
	return result;
}

float Line::AnglePlane(Plane plane)
{
	Vector v4(plane.normal.x, plane.normal.y, plane.normal.z);
	Vector v5(direction.x, direction.y, direction.z);
	float dotProduct = v4.dotProduct(v5);
	float l4 = v4.length();
	float l5 = v5.length();
	float cos = dotProduct / (l4 * l5);
	float result = acos(cos) * 180 / M_PI;

	return M_PI / 2 - result;
}
