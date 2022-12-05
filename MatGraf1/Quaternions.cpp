#include "Quaternions.h"

Quaternions::Quaternions()
{
	a = 1;
	b = 1;
	c = 1;
	d = 1;
}

Quaternions::Quaternions(float a, float b, float c, float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

Quaternions::Quaternions(float a, Vector& v)
{
	this->a = a;
	this->b = v.x;
	this->c = v.y;
	this->d = v.z;
}

Quaternions Quaternions::operator+(const Quaternions& q)
{
	float a = this->a + q.a;
	float b = this->b + q.b;
	float c = this->c + q.c;
	float d = this->d + q.d;
	return Quaternions(a, b, c, d);

}

Quaternions Quaternions::operator-(const Quaternions& q)
{
	float a = this->a - q.a;
	float b = this->b - q.b;
	float c = this->c - q.c;
	float d = this->d - q.d;
	return Quaternions(a, b, c, d);
}

Quaternions Quaternions::operator*(const Quaternions& q)
{
	return Quaternions(1,1,1,1);
}

Quaternions Quaternions::operator/(const Quaternions& q)
{
	return Quaternions(1, 1, 1, 1);
}
