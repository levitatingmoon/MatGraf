#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
{
	MatrixData[0] = m0;
	MatrixData[1] = m1;
	MatrixData[2] = m2;
	MatrixData[3] = m3;
	MatrixData[4] = m4;
	MatrixData[5] = m5;
	MatrixData[6] = m6;
	MatrixData[7] = m7;
	MatrixData[8] = m8;
	MatrixData[9] = m9;
	MatrixData[10] = m10;
	MatrixData[11] = m11;
	MatrixData[12] = m12;
	MatrixData[13] = m13;
	MatrixData[14] = m14;
	MatrixData[15] = m15;

}

Matrix::Matrix(const float* f)
{
	//std::memcpy(MatrixData, f, 16*sizeof(float));
}

Matrix::Matrix(const Matrix& mat)
{
	//std::memcpy(MatrixData, mat.MatrixData, 16*sizeof(float));
}

Matrix Matrix::operator+(const Matrix& mat)
{
	return Matrix(MatrixData[0]+mat.MatrixData[0],
		MatrixData[1] + mat.MatrixData[1],
		MatrixData[2] + mat.MatrixData[2],
		MatrixData[3] + mat.MatrixData[3],
		MatrixData[4] + mat.MatrixData[4],
		MatrixData[5] + mat.MatrixData[5],
		MatrixData[6] + mat.MatrixData[6],
		MatrixData[7] + mat.MatrixData[7],
		MatrixData[8] + mat.MatrixData[8],
		MatrixData[9] + mat.MatrixData[9],
		MatrixData[10] + mat.MatrixData[10],
		MatrixData[11] + mat.MatrixData[11],
		MatrixData[12] + mat.MatrixData[12],
		MatrixData[13] + mat.MatrixData[13],
		MatrixData[14] + mat.MatrixData[14],
		MatrixData[15] + mat.MatrixData[15]
		);
}

Matrix Matrix::operator*(const float f)
{
	return Matrix(
		MatrixData[0] *f,
		MatrixData[1] *f,
		MatrixData[2] *f,
		MatrixData[3] *f,
		MatrixData[4] *f,
		MatrixData[5] *f,
		MatrixData[6] *f,
		MatrixData[7] *f,
		MatrixData[8] *f,
		MatrixData[9] *f,
		MatrixData[10] *f,
		MatrixData[11] *f,
		MatrixData[12] *f,
		MatrixData[13] *f,
		MatrixData[14] *f,
		MatrixData[15] *f);
}

Matrix Matrix::operator*(const Matrix& mat)
{
	if (MatrixData[3] == 0.0f && MatrixData[7] == 0.0f && MatrixData[11] == 0.0f && MatrixData[15] == 1.0f &&
		mat.MatrixData[3] == 0.0f && mat.MatrixData[7] == 0.0f && mat.MatrixData[11] == 0.0f && mat.MatrixData[15] == 1.0f) {
		return Matrix(
			MatrixData[0] * mat.MatrixData[0] + MatrixData[4] * mat.MatrixData[1] + MatrixData[8] * mat.MatrixData[2],
			MatrixData[1] * mat.MatrixData[0] + MatrixData[5] * mat.MatrixData[1] + MatrixData[9] * mat.MatrixData[2], 
			MatrixData[2] * mat.MatrixData[0] + MatrixData[6] * mat.MatrixData[1] + MatrixData[10] * mat.MatrixData[2], 
			0.0f,
			MatrixData[0] * mat.MatrixData[4] + MatrixData[4] * mat.MatrixData[5] + MatrixData[8] * mat.MatrixData[6], 
			MatrixData[1] * mat.MatrixData[4] + MatrixData[5] * mat.MatrixData[5] + MatrixData[9] * mat.MatrixData[6], 
			MatrixData[2] * mat.MatrixData[4] + MatrixData[6] * mat.MatrixData[5] + MatrixData[10] * mat.MatrixData[6], 
			0.0f,
			MatrixData[0] * mat.MatrixData[8] + MatrixData[4] * mat.MatrixData[9] + MatrixData[8]  * mat.MatrixData[10], 
			MatrixData[1] * mat.MatrixData[8] + MatrixData[5] * mat.MatrixData[9] + MatrixData[9]  * mat.MatrixData[10], 
			MatrixData[2] * mat.MatrixData[8] + MatrixData[6] * mat.MatrixData[9] + MatrixData[10] * mat.MatrixData[10], 
			0.0f,
			MatrixData[0] * mat.MatrixData[12] + MatrixData[4] * mat.MatrixData[13] + MatrixData[8]  * mat.MatrixData[14] + MatrixData[12],
			MatrixData[1] * mat.MatrixData[12] + MatrixData[5] * mat.MatrixData[13] + MatrixData[9]  * mat.MatrixData[14] + MatrixData[13],
			MatrixData[2] * mat.MatrixData[12] + MatrixData[6] * mat.MatrixData[13] + MatrixData[10] * mat.MatrixData[14] + MatrixData[14],
			1.0f);
	}
}

void Matrix::loadIdentity(void)
{
	memset(MatrixData, 0, 16 * sizeof(float));
	MatrixData[0] = 1.0f;
	MatrixData[5] = 1.0f;
	MatrixData[10] = 1.0f;
	MatrixData[15] = 1.0f;
}

void Matrix::setMatrixAsInverse(const Matrix& m)
{
}

Matrix Matrix::getInverseOfMatrix()
{
	return Matrix();
}


