#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "renderer/raytracer/ARayTracer.h"
#include "scene/Scene.h"
#include "util/Colour.h"
#include "renderer/Ray.h"
#include "renderer/HitInfo.h"

class RayTracer: public ARayTracer {

public:

	RayTracer(const Scene & scene):ARayTracer(scene){ }

	virtual ~RayTracer(){ }

	virtual Colour shadeHit(const Ray & ray, const HitInfo & hitInfo);
};

#endif /* RAYTRACER_H_ */
