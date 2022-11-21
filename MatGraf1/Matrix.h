#pragma once
#include <iostream>

#include <string>

class Matrix
{
public:
	float MatrixData[16];
	Matrix();
	Matrix(float m0, float m1, float m2, float m3, 
		float m4, float m5, float m6, float m7, 
		float m8, float m9, float m10, float m11,
		float m12, float m13, float m14, float m15);
	Matrix(const float* f);
	Matrix(const Matrix &mat);
	Matrix operator+(const Matrix &mat);
	Matrix operator*(const float f);
	Matrix operator*(const Matrix &mat);
	float multiplyRowAndColumn(float row[], float column[]);
	void loadIdentity(void);
	void setMatrixAsInverse(const Matrix& m);
	Matrix getInverseOfMatrix();
	
};

std::ostream& operator<<(std::ostream& strm, const Matrix& mat);