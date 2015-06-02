#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "Point.h"
#include "Vector.h"
#include <Math.h>

class Quaternion
{

	// refactor constructors - less superfluous code for .h file
public:
	// quaternion = a - bi - cj + dk
	double a, b, c, d;
	Quaternion(double aa, double bb, double cc, double dd)
	{
		a = aa;
		b = bb;
		c = cc;
		d = dd;
	}

	Quaternion(Point point)
	{
		// Create a pure imaginary quaternion
		// Pure quaternion; a = 0
		// pure quaternion of point ' p = xi + yj + zk;
		a = 0;
		b = point.x;
		c = point.y;
		d = point.z;
	}

	friend Quaternion operator*(Quaternion one, Quaternion two);

	Quaternion(double angle, Vector r)
	{
		angle *= (M_PI/180);
		a = cos(angle/2);
		b = sin(angle/2)*r.x;
		c = sin(angle/2)*r.y;
		d = sin(angle/2)*r.z;
	}

	Quaternion conjugate();
};

#endif /* QUATERNION_H_ */
