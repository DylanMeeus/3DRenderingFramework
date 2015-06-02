#include "AFace.h"
#include <iostream>


HitInfo AFace::intersection(const Ray & ray)
{
//	std::cout << "AFace intersection" << std::endl;
	Point point = getVertex(0);
	Vector m = getFacePlaneNormal();



	if ((m.dot(ray.getDir())) < 0.0000001)
	{
		return HitInfo();
	} else
	{

		double t = m.dot(Vector(ray.getStart(), point))
				/ m.dot(ray.getDir());

		if (t < 0)
		{
			return HitInfo();
		} else
		{

			bool ok = true;

			for (int i = 0; i < 3 && ok; i++)
			{
				Vector v1(getVertex(i % 3), getVertex((i + 1) % 3));
				Vector v2(getVertex(i % 3), ray.getPoint(t));
				Vector v3 = v1.cross(v2);
				ok = v3.dot(m) > 0;
			}

			if (ok)
			{
				Point origin = Point(0,0,0);
				Vector normal = Vector(ray.getPoint(t), origin);
//							Vector mb = T.getTranspose()*normal;

				//Vector mb = T.getTranspose()*normal;
				//return HitInfo(t, ray.getPoint(t),
					//	getHitNormal(ray.getPoint(t)), mtrl);
			} else
			{
				return HitInfo();
			}
		}
	}
}
