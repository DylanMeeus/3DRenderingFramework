#include "Point.h"

void Point::set(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Point operator-(const Point& p1, const Point& p2)
{
	return Point(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}
