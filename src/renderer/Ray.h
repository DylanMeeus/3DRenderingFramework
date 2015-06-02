#ifndef RAY_H_
#define RAY_H_

#include "util/Point.h"
#include "util/Vector.h"
#include "util/Matrix.h"
#include <iostream>

class Ray {

	Point start;
	Vector dir;

public:

	Ray(const Point & start, const Vector & dir=0):start(start), dir(dir){ }

	const Vector& getDir() const { return dir; }

	void setDir(const Vector& dir) { this->dir = dir; }

	const Point& getStart() const { return start; }

	void setStart(const Point& start) { this->start = start; }

	Point getPoint(const double& t) const
	{
		Vector temp = Vector(dir.x*t, dir.y*t,dir.z*t);
		return Point(start.x+temp.x, start.y+temp.y, start.z+temp.z);
	}

	Ray getInvTransfoRay(const Matrix & invMat) const
	{
		 //start* = T-1(start) & dir* = T-1(dir)
		Point invStart = invMat * start;
		Vector invDir = invMat * dir;
		return Ray(invStart,invDir);
	}
};

#endif /* RAY_H_ */
