﻿#define _USE_MATH_DEFINES

#include "Vector.h"
#include "Matrix.h"
#include "Quaternion.h"
#include "Line.h"
#include "Plane.h"
#include "Section.h"
#include "Sphere.h"
#include <cmath>
#include <math.h>
#include "Camera.h"
#include "Cube.h"
#include <conio.h>

using namespace std;

int main()
{
	/* ------------------ - wektory-----------------------
	cout << "Sprawdzanie przemiennosci:" << endl;
	Vector v1(1, 2, 3);
	Vector v2(4, 5, 6);
	v1 += v2;
	cout << v1.x << " " << v1.y << " " << v1.z << endl;
	Vector v3(1, 2, 3);
	v2 += v3;
	cout << v2.x << " " << v2.y << " " << v2.z << endl;

	cout << "Znalezienie kata miedzy wektorami [0,3,0] i [5,5,0]:" << endl;
	Vector v4(0, 3, 0);
	Vector v5(5, 5, 0);
	float dotProduct = v4.dotProduct(v5);
	float l4 = v4.length();
	float l5 = v5.length();
	float cos = dotProduct / (l4 * l5);
	cout << acos(cos) * 180 / M_PI << endl;

	cout << "Znajdz wektor prostopadly do wektorow [4,5,1] i [4,1,3]:" << endl;
	Vector v6(4, 5, 1);
	Vector v7(4, 1, 3);
	Vector v8 = v6.cross(v7);
	Vector v9 = v7.cross(v6);
	cout << v8.x << " " << v8.y << " " << v8.z << endl;
	cout << v9.x << " " << v9.y << " " << v9.z << endl;

	cout << "Normalizacja wektora:" << endl;
	Vector v10 = v8;
	v8.normalize();
	cout << v8.x << " " << v8.y << " " << v8.z << endl;
	cout << v8.length();
	------------------------------------------------------*/
	/*
	Matrix mat1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix mat2(1, 5, 6, 7, 8, 4, 3, 1, 6, 9, 6, 3, 2, 1, 3, 6);

	//dodawanie
	cout << "addition" << endl;
	cout << "mat1" << endl;
	cout << mat1 << endl;
	cout << endl;
	cout << "mat2" << endl;
	cout << mat2 << endl;
	cout << endl;

	Matrix mat8 = mat1 + mat2;
	cout << "mat1 + mat2" << endl;
	cout << mat8 << endl;
	cout << endl;

	//mnozenie
	cout << "multiplication matrix * matrix" << endl;
	cout << "mat1" << endl;
	cout << mat1 << endl;
	cout << endl;
	cout << "mat2" << endl;
	cout << mat2 << endl;
	cout << endl;

	Matrix mat3 = mat1 * mat2;

	cout << "mat1 * mat2" << endl;
	cout << mat3 << endl;
	cout << endl;

	mat3 = mat2 * mat1;

	cout << "mat2 * mat1" << endl;
	cout << mat3 << endl;
	cout << endl;

	cout << "multiplication matrix * float" << endl;

	Matrix mat9 = mat1 * 2.0f;
	cout << "mat1" << endl;
	cout << mat1 << endl;
	cout << endl;
	cout << "mat1 * 2.0" << endl;
	cout << mat9 << endl;
	cout << endl;

	//skalowanie
	cout << "skalowanie" << endl;
	Matrix mat12(1, 2, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Matrix matS;
	matS.SetScale(Vector(2,2,2));
	cout << "mat" << endl;
 	cout << mat12 << endl;
	cout << endl;
	cout << "matScale" << endl;
	cout << matS << endl;
	cout << endl;
	cout << "matScale * mat" << endl;
	cout << matS * mat12 << endl;
	cout << endl;

	//inversja
	Matrix mat10(-1,5,9,13,2,6,10,14,3,7,11,-15,-4,8,12,16);
	cout << "inverse" << endl;
	cout << "before inversion" << endl;
	cout << mat10 << endl;
	cout << endl;
	mat10.setMatrixAsInverse(mat10);
	cout << "after inversion" << endl;
	cout << mat10 << endl;
	cout << endl;

	//rotation
	cout << "rotation" << endl;
	Matrix mat4(1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Matrix mat7(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	cout << "before rotation" << endl;
	cout << mat4 << endl;
	Vector v(0.0f, 1.0f, 0.0f);
	mat7.SetRotationY(90.0f);
	cout << "after rotation" << endl;
	cout << mat7*mat4 << endl;
	cout << endl;

	//transpose
	cout << "transpose" << endl;
	Matrix mat6(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	cout << "before transpose" << endl;
	cout << mat6 << endl;
	cout << endl;
	cout << "after transpose" << endl;
	cout << mat6.getTransposeOfMatrix() << endl;
	*/
/*
Quaternion q1(1,2,3,4);
Quaternion q2(5,6,7,8);
cout << "quaternion 1" << endl;
cout << q1 << endl;
cout << "quaternion 2" << endl;
cout << q2 << endl;

Quaternion q3 = q1 + q2;
cout << "dodawanie: q1 + q2" << endl;
cout << q3 << endl;
cout << "odejmowanie: q1 - q2" << endl;
q3 = q1 - q2;
cout << q3 << endl;


Quaternion q4 = q1 * q2;
cout << "mnozenie: q1 * q2" << endl;
cout << q4 << endl;

Quaternion q5 = q2 * q1;
cout << "mnozenie: q2 * q1" << endl;
cout << q5 << endl;

Quaternion q6 = q1 / q2;
cout << "dzielenie: q1 / q2" << endl;
cout << q6 << endl;

cout << "Obrot punktu [-1, -1, -1] wokol osi x (wektor normalny [1, 0, 0] o 270 stopni" << endl;
Vector p(-1, -1, -1);
Vector n(1, 0, 0);
Vector v = Quaternion::rotate(270 * M_PI / 180, n, p);
cout << v;
*/
/*
Line line({ -2, 4, 0 }, { 3,1,5});
Line line2({ -2, 4, 0 }, { 1, -5, 3});
//1 ok
cout << line.IntersectionWithLine(line2) << endl;

//2 ok
cout << line.AngleLine(line2) << endl;

Line line3({ -2, 2, -1 }, { 3, -1, 2 });
Plane plane({ 2, 3, 3, -8 });
//3 ok
cout << line3.IntersectionWithPlane(plane) << endl;

Line line4({ -2, 2, -1 }, { 3, -1, 2 });
Plane plane1({ 2, 3, 3, -8 });
//4 ok
cout << line4.AnglePlane(plane1) << endl;

Plane plane2({ 2, -1, 1, -8 });
Plane plane3({ 4, 3, 1, 14 });
//5 ok
cout << plane2.IntersectionWithPlane(plane3) << endl;
//6 ok
cout << plane2.AnglePlane(plane3) << endl;

Section section({ 5, 5, 4 }, { 10, 10, 6 });
Section section2({ 5, 5, 5 }, { 10, 10, 3 });
//7 ok
cout << section.IntersectionWithSection(section2) << endl;

//8 ok
Sphere sphere({ 0, 0, 0 }, std::sqrt(26));
Line line5({ 3, -1, -2 }, { 5 - 3, 3 - (-1), -4 - (-2) });
std::vector<Vector> result = sphere.IntersectionWithLine(line5);
for (Vector v : result) {
	cout << v << endl;
}*/
/*
Cube cube(5);
Camera camera;

cout << camera.rayCasting(cube);

float rotationX, rotationY, rotationZ, zoom;
cout << "Podaj obrot wokół X stopniach: ";
cin >> rotationX;
cout << "Podaj obrot wokół Y stopniach: ";
cin >> rotationY;
cout << "Podaj obrot wokół Z stopniach: ";
cin >> rotationZ;

rotationX = M_PI * rotationX / 180;
rotationY = M_PI * rotationY / 180;
rotationZ = M_PI * rotationZ / 180;

cout << "Podaj zoom:";
cin >> zoom;


camera.rotate(rotationX, rotationY, rotationZ);
camera.zoom(zoom);

cout << camera.rayCasting(cube);
*/

	Cube cube(5);
	Camera camera;

	float fifteen = M_PI / 12;

	float roll =0, pitch=0, yaw=0, zoom=0;
	float rollR = 0, pitchR = 0, yawR = 0;

	for (;;)
	{
		system("CLS");
		cout << camera.rayCasting(cube);
		cout << endl << "rotX: " << roll << " rotY: " << pitch << " rotZ: " << yaw << endl;
		cout << endl << endl;
		cout << " |Z" << endl;
		cout << " |   /Y" << endl;
		cout << " |  / " << endl;
		cout << " | / " << endl;
		cout << " |/______ X   " << endl << endl;
		cout << "Podaj obrot wokol X w stopniach: ";
		cin >> roll;
		cout << "Podaj obrot wokol Y w stopniach: ";
		cin >> pitch;
		cout << "Podaj obrot wokol Z w stopniach: ";
		cin >> yaw;
		cout << "Podaj zoom:";
		cin >> zoom;

		rollR = M_PI * roll / 180;
		pitchR = M_PI * pitch / 180;
		yawR = M_PI * yaw / 180;
		camera.changeTransform(rollR, pitchR, yawR, zoom);
	
	}

}