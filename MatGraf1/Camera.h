#pragma once
#include "Vector.h"
#include "Quaternion.h"
#include "Cube.h"

class Camera
{
	const float POINTS_CAM_DIST = 5;
	const float POINTS_WIDTH = 10;
	const Vector START_POS = Vector(0, -10, 0);
public:
	Vector position;
	Camera();
	Vector rotatePoint(Vector point, float roll, float pitch, float yaw);
	void rotate(float roll, float pitch, float yaw);
	void zoom(float distance);
	Vector viewPoints[60][60];
	std::string rayCasting(Cube cube);
};

