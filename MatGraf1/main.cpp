#define _USE_MATH_DEFINES

#include "Vector.h"
#include "Matrix.h"
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
	v8.normalize();
	cout << v8.x << " " << v8.y << " " << v8.z << endl;
	cout << v8.length();
	------------------------------------------------------*/
	Matrix mat1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix mat2(1, 5, 6, 7, 8, 4, 3, 1, 6, 9, 6, 3, 2, 1, 3, 6);
	Matrix mat3 = mat1 * mat2;
	cout << mat3;

}