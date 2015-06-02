#include "util/Matrix.h"
#include <vector>
Matrix::Matrix() // Maakt eenheidsmatrix
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		m[i][i] = 1;
	}
}

Matrix::Matrix(const Matrix & a) // copies another matrix
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = a.m[i][j];
		}
	}
}

Matrix & Matrix::operator=(const Matrix & a)
{
	if (this == &a)
	{
		return *this;
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = a.m[i][j];
		}
	}
	return *this;
}

Point operator*(const Matrix & m, const Point & p)
{
	double x = m.m[0][0] * p.x + m.m[0][1] * p.y + m.m[0][2] * p.z + m.m[0][3];
	double y = m.m[1][0] * p.x + m.m[1][1] * p.y + m.m[1][2] * p.z + m.m[1][3];
	double z = m.m[2][0] * p.x + m.m[2][1] * p.y + m.m[2][2] * p.z + m.m[2][3];
	return Point(x, y, z);
}

Vector operator*(const Matrix & m, const Vector & v)
{
	//return Vector(tempvector[0],tempvector[1],tempvector[2]);

	double x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3];
	double y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3];
	double z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3];
	return Vector(x, y, z);
}

Matrix Matrix::getTranspose() const
{
	// All matrixes are square

	Matrix temp = Matrix();
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			temp.m[row][column] = m[column][row];
		}
	}
	return temp;
}

void Matrix::preMult(const Matrix & a)
{
	Matrix copy(*this);
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			double sum = 0;
			for (int i = 0; i < 4; i++)
			{
				sum += a.m[r][i] * copy.m[i][c];
			}
			m[r][c] = sum;
		}
	}
}

void Matrix::postMult(const Matrix & a)
{
	Matrix copy(*this);

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			double sum = 0;
			for (int i = 0; i < 4; i++)
			{
				sum += copy.m[r][i] * a.m[i][c];
			}
			m[r][c] = sum;
		}
	}
}
