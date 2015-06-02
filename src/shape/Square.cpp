/*
 * Square.cpp
 *
 *  Created on: 8-nov.-2014
 *      Author: Dylan
 */

#include "Square.h"
#include <iostream>
#include <cmath>

HitInfo Square::intersection(const Ray & ray)
{
	Ray invRay = ray . getInvTransfoRay ( transfo . getInvMat ());
	if ( std :: abs ( invRay . getDir (). z ) <0.00001){
	return HitInfo ();
	}
	double t = - invRay . getStart (). z / invRay . getDir (). z ;
	if (t <=0.0){
	return HitInfo ();
	}
	Point hitPoint = invRay . getPoint ( t );
	if ( hitPoint . x > 1.0 || hitPoint . x < -1.0 ||
	hitPoint . y > 1.0 || hitPoint . y < -1.0){
	return HitInfo ();
	}
	Vector normal = transfo . getInvMat (). getTranspose ()* Vector (0 ,0 ,1);
	normal . normalize ();
	return HitInfo(t , ray . getPoint ( t ) ,mtrl, normal );
}

	/*
	Vector dir = ray.getDir();
	//std::cout << dir.x << " " << dir.y << " " << dir.z << std::endl;
	Point start = ray.getStart();
	if (dir.z != 0)
	{
		//	std::cout << "Reaching this code with: " << dir.z << std::endl;
		double t = (-start.z) / dir.z;
		if (t <= 0.0)
		{
			return HitInfo();
		}

		const Point hitPoint = ray.getPoint(t);

		if (hitPoint.x > 1.0 || hitPoint.x < -1.0 || hitPoint.y > 1.0
				|| hitPoint.y < -1.0)
		{
			return HitInfo();
		}


		Vector normal = transfo.getInvMat().getTranspose() * Vector(0, 0, 1);
		normal.normalize();

		return HitInfo(t, ray.getPoint(t), mtrl, normal);
	}

	return HitInfo();*/
