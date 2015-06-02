#ifndef POINT_H_
#define POINT_H_

class Point {

public:

	double x;
	double y;
	double z;

	Point(double x=0, double y=0, double z=0): x(x), y(y), z(z){ }

	void set(double x, double y, double z);

	friend Point operator-(const Point & p1, const Point & p2);

};

#endif /* POINT_H_ */
