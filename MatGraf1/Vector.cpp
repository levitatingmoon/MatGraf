#include "Vector.h"

Vector::Vector()
{
	x = 1;
	y = 1;
	z = 1;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(Vector p1, Vector p2)
{
	this->x = p1.x + p2.x;
	this->y = p1.y + p2.y;
	this->z = p1.z + p2.z;
	
}

Vector::Vector(const Vector& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

void Vector::operator+=(const Vector& v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector::operator-=(const Vector& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector::div(float f) {
	if (f != 0) {
		this->x /= f;
		this->y /= f;
		this->z /= f;
	}
	else {
		std::cout << "Can't divide by 0" << std::endl;
	}
}

void Vector::mult(float f) {
	this->x *= f;
	this->y *= f;
	this->z *= f;
}

float Vector::length() {
	return (float)sqrt(pow(this->x, 2) +
		pow(this->y, 2) +
		pow(this->z, 2));
}


void Vector::normalize() {
	float n = this->length();
	if (n != 0) {
		this->div(n);
	}
	else {
		std::cout << "Can't divide by 0" << std::endl;
	}
}

Vector Vector::getNormalized() {
	float n = this->length();
	if (n != 0) {
		this->div(n);
	}
	else {
		std::cout << "Can't divide by 0" << std::endl;
	}
	return *this;
}

float Vector::dotProduct(Vector v) {
	Vector result;
	result.x = this->x * v.x;
	result.y = this->y * v.y;
	result.z = this->z * v.z;
	return result.x + result.y + result.z;
}

Vector Vector::cross(Vector v) {
	return Vector(this->y * v.z - this->z * v.y,
		this->z * v.x - this->x * v.z,
		this->x * v.y - this->y * v.x);
}