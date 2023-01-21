#pragma once
#include "Vector.h"
#include "Quaternion.h"

class Camera
{
public:
	Vector position;
	Camera(float x, float y, float z);
	Vector rotatePoint(Vector point, float roll, float pitch, float yaw);
	void rotate(float roll, float pitch, float yaw);
	Vector viewPoints[60][60];
	Vector viewLines[60][60];
};

