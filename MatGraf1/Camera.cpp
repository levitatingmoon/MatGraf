#include "Camera.h"

Camera::Camera()
{
	this->position = START_POS;

	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			viewPoints[i][j].x = (j - 30) * POINTS_WIDTH / 60;
			viewPoints[i][j].y = START_POS.y + POINTS_CAM_DIST;
			viewPoints[i][j].z = (i - 30) * POINTS_WIDTH / 60;
		}
	}
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
	rotation += Vector(roll, pitch, yaw);
	position = rotatePoint(position, roll, pitch, yaw);

	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			viewPoints[i][j] = rotatePoint(viewPoints[i][j], roll, pitch, yaw);
		}
	}
}

void Camera::zoom(float distance)
{
	currentZoom += distance;
	Vector v(0, 0, 0);
	v -= position;
	float length = v.length();
	v.div(length);
	v.mult(distance);
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			viewPoints[i][j] += v;
		}
	}

}

std::string Camera::rayCasting(Cube cube)
{
	std::string result = "";
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			Vector v = viewPoints[i][j];
			v -= position;
			Line line(viewPoints[i][j], v);
			if (cube.checkIntersection(line))
			{
				result += '0';
			}
			else {
				result += '.';
			}
		}
		result += "\n";
	}
	return result;
}

std::string Camera::info()
{
	std::stringstream ss;
	ss << "rotation: " << rotation << " zoom: " << currentZoom;
	return ss.str();
}
