#include "Vector.h"

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

Vector Vector::dot(Vector v) {
	Vector result;
	result.x = this->x * v.x;
	result.y = this->y * v.y;
	result.z = this->z * v.z;
	return result;
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