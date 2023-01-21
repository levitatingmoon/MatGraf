#include "Camera.h"

Camera::Camera(float x, float y, float z)
{
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;
}

Vector Camera::rotatePoint(Vector point, float roll, float pitch, float yaw)
{
	Quaternion p(0, point);
	float u = roll;
	float v = pitch;
	float w = yaw;
	Quaternion q;
	q.a = cos(u / 2)*cos(v/2)*cos(w/2) + sin(u / 2)*sin(v/2)*sin(w/2);
	q.b = sin(u/2)*cos(v/2)*cos(w / 2) - cos(u/2)*sin(v/2)*sin(w / 2);
	q.c = cos(u/2)*sin(v/2)*cos(w / 2) + sin(u/2)*cos(v/2)*sin(w / 2);
	q.d = cos(u/2)*cos(v/2)*sin(w / 2) - sin(u/2)*sin(v/2)*cos(w / 2);
	Quaternion qinverted = q.conjugate();
	Quaternion pnew = qinverted * p * q;
	Vector result;
	result.x = pnew.b;
	result.y = pnew.c;
	result.z = pnew.d;
	return result;
}

void Camera::rotate(float roll, float pitch, float yaw)
{
	position = rotatePoint(position, roll, pitch, yaw);
	//..obrót punktów
}