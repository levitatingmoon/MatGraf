#define _USE_MATH_DEFINES

#include "Vector.h"
#include "Matrix.h"
#include "Quaternions.h"
#include <cmath>
#include <math.h>

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
Quaternions q1(1,0,3,5);
Quaternions q2(1,1,0,2);

Quaternions q3 = q1 + q2;
cout << q3.a << q3.b << q3.c << q3.d << endl;
q3 = q1 - q2;
cout << q3.a << q3.b << q3.c << q3.d << endl;

Quaternions q4 = q1 * q2;
cout << q4.a << q4.b << q4.c << q4.d << endl;

}