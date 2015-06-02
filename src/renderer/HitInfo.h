#ifndef HITINFO_H_
#define HITINFO_H_

#include "util/Point.h"
#include "util/Vector.h"
#include "shading/Material.h"
#include <cfloat>
#include <iostream>

class HitInfo {

	double t;
	Point hitPoint;
	Material hitMaterial;
	Vector hitNormal;
	void copy(const HitInfo & hitInfo);

public:


	HitInfo(double t=DBL_MAX):t(t){}

	//HitInfo(double t, const Point & p, const Material & m);

	HitInfo(double _t, const Point & _p) {t=_t; hitPoint = _p;}

	HitInfo(double t, const Point & p, const Material & m):t(t), hitPoint(p), hitMaterial(m) { }

	HitInfo(double t, const Point & p, const Material & m, const Vector & n):t(t), hitPoint(p), hitMaterial(m), hitNormal(n) {

	}



	HitInfo(const HitInfo & hitInfo);

	HitInfo& operator=(const HitInfo & hitInfo);

	double getT() const { return t; }

	void setT(double t) { this->t = t; }

	const Point& getHitPoint() const { return hitPoint; }

	const Vector& getHitNormal() const {
		return hitNormal; }

	void setHitPoint(const Point& hitPoint) { this->hitPoint = hitPoint; }

	void setHitNormal(const Vector& _hitNormal) { this->hitNormal = _hitNormal; }

	const Material& getHitMaterial() const { return hitMaterial; }

	void setHitMaterial(const Material& hitMaterial) { this->hitMaterial = hitMaterial; }

};

#endif /* HITINFO_H_ */
