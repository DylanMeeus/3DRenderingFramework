#ifndef CAMERA_H_
#define CAMERA_H_

#include "util/Point.h"
#include "util/Vector.h"
#include "app/AppConfigurationFileReader.h"

class Camera {
  Point eye;
  Point look;
  Vector upV;

  Vector u,v,n;

  double distance, width, height;

public:

    Camera(AppConfiguration & appCfg);

    const Point& getEye() const { return eye; }

  	void setEye(const Point& eye) { this->eye = eye; }

	const Point& getLook() const { return look; }

	void setLook(const Point& look) { this->look = look; }

	const Vector& getUpV() const { return upV; }

	void setUpV(const Vector& upV) { this->upV = upV; }

	const Vector& getU() const { return u; }

	void setU(const Vector& u) { this->u = u; }

	const Vector& getV() const { return v; }

	void setV(const Vector& v) { this->v = v; }

	const Vector& getN() const { return n; }

    void setN(const Vector& n) { this->n = n; }

	double getDistance() const { return distance; }

	void setDistance(double distance) { this->distance = distance; }

	double getHeight() const { return height; }

	void setHeight(double height) { this->height = height; }

	double getWidth() const { return width; }

	void setWidth(double width) { this->width = width; }

	void forward();

	void backward();

	void up();

	void down();

	void left();

	void right();
};

#endif /* CAMERA_H_ */
