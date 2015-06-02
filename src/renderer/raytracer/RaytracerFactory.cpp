/*
 * RaytracerFactory.cpp
 *
 *  Created on: 19-dec.-2014
 *      Author: Dylan
 */

#include "RaytracerFactory.h"

#include "RayTracer.h"
ARayTracer* RaytracerFactory::createRayTracer(const Scene& scene,const AppConfiguration& appCfg)
{
	return new RayTracer(scene);
}

