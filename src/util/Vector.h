#ifndef VECTOR_H_
#define VECTOR_H_

#include "util/Point.h"

class Vector {

public:

	double x, y, z;

	Vector(double x=0, double y=0, double z=0):x(x), y(y), z(z){ }

	Vector(const Point& from, const Point & to);

	Vector(const Point& p):x(p.x),y(p.y), z(p.z){ }

	friend Vector operator*(const Vector & v, double a);

	friend Vector operator*(double a, const Vector & v);

	friend Point operator+(const Point & p, const Vector & v);

	friend Point operator+(const Vector & v, const Point & p);

	friend Vector operator+(const Vector & v1, const Vector & v2);

	friend Vector operator-(const Vector & v1, const Vector & v2);

	double dot(const Vector& v);

	Vector cross(const Vector & v);

	double length();

	void normalize();

};

#endif /* VECTOR_H_ */
