#include "Vector.h"
#include <cmath>

Vector::Vector(const Point& from, const Point& to)
{
	x = to.x - from.x;
	y = to.y - from.y;
	z = to.z - from.z;
}

Vector operator*(const Vector & v, double a)
{
	return Vector(v.x * a, v.y * a, v.z * a);
}

Vector operator*(double a, const Vector & v)
{
	return v * a;
}

Point operator+(const Point & p, const Vector & v)
{
	return Point(p.x + v.x, p.y + v.y, p.z + v.z);
}

Point operator+(const Vector & v, const Point & p)
{
	return p + v;
}

Vector operator+(const Vector & v1, const Vector & v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector operator-(const Vector & v1, const Vector & v2)
{
	return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

// Dot, Cross and Length to implement
double Vector::dot(const Vector& v)
{
	return v.x*x + v.y*y + v.z*z;
}

Vector Vector::cross(const Vector& v)
{
	double xComp = (y * v.z)-(z * v.y);
	double yComp = (z * v.x)-(x * v.z);
	double zComp = (x * v.y)-(y * v.x);
	return Vector(xComp,yComp,zComp);
}

double Vector::length()
{
	long double xPow = std::pow(x,2);
	long double yPow = std::pow(y,2);
	long double zPow = std::pow(z,2);
	return std::sqrt(xPow+yPow+zPow);
}

void Vector::normalize()
{
	x /= length();
	y /= length();
	z /= length();
}
