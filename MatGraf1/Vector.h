
#pragma once
#include <string>
#include <iostream>

class Vector
{
public:
	float x, y, z;
	Vector();
	Vector(float x, float y, float z);
	Vector(Vector p1, Vector p2);
	Vector(const Vector &v);
	
	void operator+=(const Vector& v);
	void operator-=(const Vector& v);
	void div(float f);
	void mult(float f);
	float length();
	void normalize();
	Vector getNormalized();
	float dotProduct(Vector v);
	Vector cross(Vector v);
};
