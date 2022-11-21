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
	std::memcpy(MatrixData, f, 16*sizeof(float));
}

Matrix::Matrix(const Matrix& mat)
{
	std::memcpy(MatrixData, mat.MatrixData, 16*sizeof(float));
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
	float rows[4][4] = { {MatrixData[0], MatrixData[4], MatrixData[8], MatrixData[12]},
						{MatrixData[1], MatrixData[5], MatrixData[9], MatrixData[13]},
						{MatrixData[2], MatrixData[6], MatrixData[10], MatrixData[14]},
						{MatrixData[3], MatrixData[7], MatrixData[11], MatrixData[15]} };
	float columns[4][4] = { {mat.MatrixData[0], mat.MatrixData[1], mat.MatrixData[2], mat.MatrixData[3]},
						{mat.MatrixData[4], mat.MatrixData[5], mat.MatrixData[6], mat.MatrixData[7]},
						{mat.MatrixData[8], mat.MatrixData[9], mat.MatrixData[10], mat.MatrixData[11]},
						{mat.MatrixData[12], mat.MatrixData[13], mat.MatrixData[14], mat.MatrixData[15]} };
	return Matrix(multiplyRowAndColumn(rows[0], columns[0]), multiplyRowAndColumn(rows[1], columns[0]), multiplyRowAndColumn(rows[2], columns[0]), multiplyRowAndColumn(rows[3], columns[0]),
		multiplyRowAndColumn(rows[0], columns[1]), multiplyRowAndColumn(rows[1], columns[1]), multiplyRowAndColumn(rows[2], columns[1]), multiplyRowAndColumn(rows[3], columns[1]),
		multiplyRowAndColumn(rows[0], columns[2]), multiplyRowAndColumn(rows[1], columns[2]), multiplyRowAndColumn(rows[2], columns[2]), multiplyRowAndColumn(rows[3], columns[2]),
		multiplyRowAndColumn(rows[0], columns[3]), multiplyRowAndColumn(rows[1], columns[3]), multiplyRowAndColumn(rows[2], columns[3]), multiplyRowAndColumn(rows[3], columns[3]));
}



	/*
		return Matrix(
		MatrixData[0] * mat.MatrixData[0] + MatrixData[4] * mat.MatrixData[1] + MatrixData[8] * mat.MatrixData[2] + MatrixData[12] * mat.MatrixData[3],
		MatrixData[1] * mat.MatrixData[0] + MatrixData[5] * mat.MatrixData[1] + MatrixData[9] * mat.MatrixData[2] + MatrixData[13] * mat.MatrixData[3],
		MatrixData[2] * mat.MatrixData[0] + MatrixData[6] * mat.MatrixData[1] + MatrixData[10] * mat.MatrixData[2] + MatrixData[14] * mat.MatrixData[3],
		MatrixData[3] * mat.MatrixData[0] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[],

		MatrixData[0] * mat.MatrixData[4] + MatrixData[4] * mat.MatrixData[5] + MatrixData[8] * mat.MatrixData[6] + MatrixData[] * mat.MatrixData[],
		MatrixData[1] * mat.MatrixData[4] + MatrixData[5] * mat.MatrixData[5] + MatrixData[9] * mat.MatrixData[6] + MatrixData[] * mat.MatrixData[],
		MatrixData[2] * mat.MatrixData[4] + MatrixData[6] * mat.MatrixData[5] + MatrixData[10] * mat.MatrixData[6] + MatrixData[] * mat.MatrixData[],
			MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[],

		MatrixData[0] * mat.MatrixData[8] + MatrixData[4] * mat.MatrixData[9] + MatrixData[8]  * mat.MatrixData[10] + MatrixData[] * mat.MatrixData[],
		MatrixData[1] * mat.MatrixData[8] + MatrixData[5] * mat.MatrixData[9] + MatrixData[9]  * mat.MatrixData[10] + MatrixData[] * mat.MatrixData[],
		MatrixData[2] * mat.MatrixData[8] + MatrixData[6] * mat.MatrixData[9] + MatrixData[10] * mat.MatrixData[10] + MatrixData[] * mat.MatrixData[],
			MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[],

		MatrixData[0] * mat.MatrixData[12] + MatrixData[4] * mat.MatrixData[13] + MatrixData[8]  * mat.MatrixData[14] + MatrixData[12] + MatrixData[] * mat.MatrixData[],
		MatrixData[1] * mat.MatrixData[12] + MatrixData[5] * mat.MatrixData[13] + MatrixData[9]  * mat.MatrixData[14] + MatrixData[13] + MatrixData[] * mat.MatrixData[],
		MatrixData[2] * mat.MatrixData[12] + MatrixData[6] * mat.MatrixData[13] + MatrixData[10] * mat.MatrixData[14] + MatrixData[14] + MatrixData[] * mat.MatrixData[],
		MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[] + MatrixData[] * mat.MatrixData[]);
	*/


float Matrix::multiplyRowAndColumn(float row[], float column[])
{
	return row[0] * column[0] + row[1] * column[1] + row[2] * column[2] + row[3] * column[3];
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
	Matrix result;
	result.setMatrixAsInverse(*this);
	return result;
}

void Matrix::invertMatrix()
{
	setMatrixAsInverse(*this);
}

void Matrix::setMatrixAsTranspose(const Matrix& m)
{
	/*4x4
	* 0 4 8  12
	* 1 5 9  13
	* 2 6 10 14
	* 3 7 11 15
	* 
	* 0 1 2 3
	* 4 5 6 7
	* 8 9 10 11
	* 12 13 14 15
	* 
	*/

	MatrixData[0] = m.MatrixData[0];
	MatrixData[4] = m.MatrixData[1];
	MatrixData[8] = m.MatrixData[2];
	MatrixData[12] = m.MatrixData[3];

	MatrixData[1] = m.MatrixData[4];
	MatrixData[5] = m.MatrixData[5];
	MatrixData[9] = m.MatrixData[6];
	MatrixData[13] = m.MatrixData[7];

	MatrixData[2] = m.MatrixData[8];
	MatrixData[6] = m.MatrixData[9];
	MatrixData[10] = m.MatrixData[10];
	MatrixData[14] = m.MatrixData[11];

	MatrixData[3] = m.MatrixData[12];
	MatrixData[7] = m.MatrixData[13];
	MatrixData[11] = m.MatrixData[14];
	MatrixData[15] = m.MatrixData[15];
}

Matrix Matrix::getTransposeOfMatrix()
{
	Matrix result;
	result.setMatrixAsTranspose(*this);
	return result;
}

void Matrix::SetTranslationPart(const Vector & translation)
{
	MatrixData[12] = translation.x;
	MatrixData[13] = translation.y;
	MatrixData[14] = translation.z;
}

void Matrix::SetScale(const Vector& scaleFactor)
{
	loadIdentity();
	MatrixData[0] = scaleFactor.x;
	MatrixData[5] = scaleFactor.y;
	MatrixData[10] = scaleFactor.z;
}

void Matrix::SetUniformScale(const float scaleFactor)
{
	loadIdentity();
	MatrixData[0] = MatrixData[5] = MatrixData[10] = scaleFactor;
}

void Matrix::SetRotationAxis(const double angle, Vector& axis)
{
	Vector u = axis.getNormalized();

	float sinAngle = (float)sin(M_PI * angle / 180);
	float cosAngle = (float)cos(M_PI * angle / 180);
	float oneMinusCosAngle = 1.0f - cosAngle;

	loadIdentity();
	MatrixData[0] = (u.x) * (u.x) + cosAngle * (1 - (u.x) * (u.x));
	MatrixData[4] = (u.x) * (u.y) * (oneMinusCosAngle)-sinAngle * u.z;
	MatrixData[8] = (u.x) * (u.z) * (oneMinusCosAngle)+sinAngle * u.y;

	MatrixData[1] = (u.x) * (u.y) * (oneMinusCosAngle)+sinAngle * u.z;
	MatrixData[5] = (u.y) * (u.y) + cosAngle * (1 - (u.y) * (u.y));
	MatrixData[9] = (u.y) * (u.z) * (oneMinusCosAngle)+sinAngle * u.x;

	MatrixData[2] = (u.x) * (u.z) * (oneMinusCosAngle)-sinAngle * u.y;
	MatrixData[6] = (u.y) * (u.z) * (oneMinusCosAngle)+sinAngle * u.x;
	MatrixData[10] = (u.z) * (u.z) + cosAngle * (1 - (u.z) * (u.z));
}

void Matrix::SetRotationX(const double angle)
{
	loadIdentity();
	MatrixData[5] = (float)cos(M_PI*angle/180);
	MatrixData[6] = (float)sin(M_PI * angle / 180);

	MatrixData[9] = -MatrixData[6];
	MatrixData[10] = MatrixData[5];
}

void Matrix::SetRotationY(const double angle)
{
	loadIdentity();
	MatrixData[0] = (float)cos(M_PI * angle / 180);
	MatrixData[2] = (float)sin(M_PI * angle / 180);

	MatrixData[8] = -MatrixData[2];
	MatrixData[10] = MatrixData[0];
}

void Matrix::SetRotationZ(const double angle)
{
	loadIdentity();
	MatrixData[0] = (float)cos(M_PI * angle / 180);
	MatrixData[1] = (float)sin(M_PI * angle / 180);

	MatrixData[4] = -MatrixData[1];
	MatrixData[5] = MatrixData[0];
}


std::ostream& operator<<(std::ostream& strm, const Matrix& mat) {

	return strm << mat.MatrixData[0] << " " << mat.MatrixData[4] << " " << mat.MatrixData[8] << " " << mat.MatrixData[12] << std::endl
		<< mat.MatrixData[1] << " " << mat.MatrixData[5] << " " << mat.MatrixData[9] << " " << mat.MatrixData[13] << std::endl
		<< mat.MatrixData[2] << " " << mat.MatrixData[6] << " " << mat.MatrixData[10] << " " << mat.MatrixData[14] << std::endl
		<< mat.MatrixData[3] << " " << mat.MatrixData[7] << " " << mat.MatrixData[11] << " " << mat.MatrixData[15];
}


