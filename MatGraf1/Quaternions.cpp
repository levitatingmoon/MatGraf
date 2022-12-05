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
	Vector v1(this->b, this->c, this->d);
	Vector v2(q.b, q.c, q.d);

	Vector t1(this->b, this->c, this->d);
	Vector t2(q.b, q.c, q.d);

	float a = (this->a * q.a) - (v1.dotProduct(v2));

	t2.mult(this->a);
	t1.mult(q.a);
	t1 += t2;

	Vector cross = v1.cross(v2);
	t1 += cross;

	float b = t1.x;
	float c = t1.y;
	float d = t1.z;

	return Quaternions(a,b,c,d);
}

Quaternions Quaternions::operator/(const Quaternions& q)
{
	return Quaternions(1, 1, 1, 1);
}
