#pragma once
#include "Vector.h"
class Quaternion
{
public:
	float a,b,c,d;
	Quaternion();
	Quaternion(float a, float b, float c, float d);
	Quaternion(float a, Vector& v);

	Quaternion operator+(const Quaternion& q);
	Quaternion operator-(const Quaternion& q);
	Quaternion operator*(const Quaternion& q);
	Quaternion operator/(const Quaternion& q);

	Quaternion conjugate();
	static Vector rotate(float alfa, Vector n, Vector point);

};

std::ostream& operator<<(std::ostream& strm, const Quaternion& q);