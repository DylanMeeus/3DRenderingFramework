#include "ARayTracer.h"
#include "shape/IRaytraceable.h"
#include "renderer/HitInfo.h"
#include <cfloat>

Colour ARayTracer::shade(const Ray & ray)
{
	HitInfo bestHitInfo(DBL_MAX);
	std::vector<IRaytraceable*> objects = scene.getObjects();
	for (std::vector<IRaytraceable*>::iterator it = objects.begin();
			it != objects.end(); ++it)
	{
		HitInfo hitInfo = (*it)->intersection(ray);
		if (hitInfo.getT() < bestHitInfo.getT()) // if new hitInfo is better.
		{
			bestHitInfo = hitInfo;
		}
	}
	//std::cout << "best hit info: " << bestHitInfo.getT() << std::endl;
	return (bestHitInfo.getT() == DBL_MAX) ? scene.getBackground() : shadeHit(ray, bestHitInfo);
}

