#pragma once
#define _USE_MATH_DEFINES
#include "Vector.h"
#include <cstdio>
#include <cmath>
#include <math.h>

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
	void loadIdentity(void); //ok
	void setMatrixAsInverse(const Matrix& m); //idk
	Matrix getInverseOfMatrix(); //ok
	void invertMatrix(); //ok
	void setMatrixAsTranspose(const Matrix &m); //ok
	Matrix getTransposeOfMatrix(); //ok
	void SetTranslationPart(const Vector &translation); //ok
	void SetScale(const Vector& scaleFactor); //ok
	void SetUniformScale(const float scaleFactor); //ok
	void SetRotationAxis(const double angle, Vector &axis); //ok
	void SetRotationX(const double angle); //ok
	void SetRotationY(const double angle); //ok
	void SetRotationZ(const double angle); //ok

};

