#include "Quaternion.h"
using namespace std;

Quaternion::Quaternion()
{
	a = 1;
	b = 1;
	c = 1;
	d = 1;
}

Quaternion::Quaternion(float a, float b, float c, float d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

Quaternion::Quaternion(float a, Vector& v)
{
	this->a = a;
	this->b = v.x;
	this->c = v.y;
	this->d = v.z;
}

Quaternion Quaternion::operator+(const Quaternion& q)
{
	float a = this->a + q.a;
	float b = this->b + q.b;
	float c = this->c + q.c;
	float d = this->d + q.d;
	return Quaternion(a, b, c, d);

}

Quaternion Quaternion::operator-(const Quaternion& q)
{
	float a = this->a - q.a;
	float b = this->b - q.b;
	float c = this->c - q.c;
	float d = this->d - q.d;
	return Quaternion(a, b, c, d);
}

Quaternion Quaternion::operator*(const Quaternion& q)
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

	return Quaternion(a,b,c,d);
}

Quaternion Quaternion::operator/(const Quaternion& q)
{
	float a, b, c, d;

	Vector v1(this->b, this->c, this->d);
	Vector v2(q.b, q.c, q.d);

	Vector t1(this->b, this->c, this->d);
	Vector t2(q.b, q.c, q.d);

	float dotv2v2 = v2.dotProduct(v2);
	float dotv1v2 = v1.dotProduct(v2);
	Vector cross = v1.cross(v2);


	a = ((this->a * q.a) + dotv1v2) / ((q.a * q.a) + dotv2v2); //ok

	float tmp1 = 1 / ((q.a * q.a) + dotv2v2);

	t2.mult(this->a);
	t2.mult(-1);

	t1.mult(q.a);
	t1 += t2;
	t1 -= cross;
	t1.mult(tmp1);

	b = t1.x;
	c = t1.y;
	d = t1.z;

	return Quaternion(a, b,c,d);
}

Quaternion Quaternion::conjugate()
{
	Quaternion q;
	q.a = a;
	q.b = -b;
	q.c = -c;
	q.d = -d;
	return q;
}

Vector Quaternion::rotate(float alfa, Vector n, Vector point)
{
	Quaternion p(0, point.x, point.y, point.z);
	n.mult(sin(alfa / 2));
	Quaternion q(cos(alfa / 2), n);
	Quaternion qc(q.conjugate());
	Quaternion p2 = q * p;
	p2 = p2 * qc;
	Vector result(p2.b, p2.c, p2.d);
	return result;
}

std::ostream& operator<<(std::ostream& strm, const Quaternion& q) {

	return strm << "(" << q.a << ", [" << q.b << ", " << q.c << ", " << q.d << "])";
}


