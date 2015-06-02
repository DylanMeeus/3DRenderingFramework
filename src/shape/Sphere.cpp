#include "Sphere.h"
#include <iostream>
#include <cmath>



HitInfo Sphere::intersection(const Ray & ray)
{
	Matrix T = transfo.getInvMat();

	Ray invRay = ray.getInvTransfoRay(T); // inverse ray



	Vector dir = invRay.getDir();
				//std::cout << dir.x << " " << dir.y << " " << dir.z << std::endl;
	Point start = invRay.getStart();

	double tt = dir.dot(dir); //t²
	double startdir = (dir.x*start.x+dir.y*start.y+dir.z*start.z)*2;
	double startstart = (start.x*start.x)+(start.y*start.y)+(start.z*start.z) - 1;

	// t²+t-x
	double discr = startdir*startdir-4*tt*startstart;
	//std::cout << discr << std::endl;
	if(discr>=0)
	{
		//std::cout << discr << std::endl;
		double t1 = (-startdir - sqrt(discr))/(2*tt); // one of the two possible t values
		double t2 = (-startdir + sqrt(discr))/(2*tt); // the other possible t value

		// dirdir toont welk getal groter is door het teken. splits -b+-(d^(1/2))/2a


		Point origin = Point(0,0,0);
		if(t1 > 0) // first is groter dan 0, en altijd kleiner dan second
		{
			// vind de normaalvector. Deze is altijd een vector vanuit de oorsprong tot het huidige punt.
			Vector normal = Vector(ray.getPoint(t1), origin);

			Vector mb = T.getTranspose()*normal;
			mb.normalize();
			return HitInfo(t1,ray.getPoint(t1),mtrl, mb);
		}
		if(t2 > 0)
		{
			Vector normal = Vector(ray.getPoint(t2), origin);
			Vector mb = T.getTranspose()*normal;
			mb.normalize();
			return HitInfo(t2, ray.getPoint(t2),mtrl, mb);
		}
	}

	return HitInfo();
}

bool Sphere::hit(const Ray & ray)
{

	Matrix T = transfo.getInvMat();
	Ray invRay = ray.getInvTransfoRay(T); // inverse ray1
	Vector dir = invRay.getDir();
				//std::cout << dir.x << " " << dir.y << " " << dir.z << std::endl;
	Point start = invRay.getStart();
	double tt = dir.dot(dir); //t²
	double startdir = (dir.x*start.x+dir.y*start.y+dir.z*start.z)*2;
	double startstart = (start.x*start.x)+(start.y*start.y)+(start.z*start.z) - 1;
	double discr = startdir*startdir-4*tt*startstart;
	if(discr>=0)
	{
		double t1 = (-startdir - sqrt(discr))/(2*tt); // one of the two possible t values
		double t2 = (-startdir + sqrt(discr))/(2*tt); // the other possible t value
		Point origin = Point(0,0,0);
		if(t1 > 0) // first is groter dan 0, en altijd kleiner dan second
		{

		}
		if(t2 > 0)
		{

		}
	}



	return false;
}
