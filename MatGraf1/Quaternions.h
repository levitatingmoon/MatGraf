#pragma once
#include "Vector.h"
class Quaternions
{
public:
	float a,b,c,d;
	Quaternions();
	Quaternions(float a, float b, float c, float d);
	Quaternions(float a, Vector& v);

	void operator+=(const Quaternions& q);
	void operator-=(const Quaternions& q);
	void operator*(const Quaternions& q);
	void operator/(const Quaternions& q);

	void rotate();

};
