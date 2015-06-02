/*
 * RaytracerFactory.h
 *
 *  Created on: 19-dec.-2014
 *      Author: Dylan
 */

#ifndef SRC_RENDERER_RAYTRACER_RAYTRACERFACTORY_H_
#define SRC_RENDERER_RAYTRACER_RAYTRACERFACTORY_H_


#include "ARayTracer.h"
#include "app/AppConfigurationFileReader.h"

class RaytracerFactory
	{

public :
			static ARayTracer* createRayTracer(const Scene& scene,const AppConfiguration& afr);


	};


#endif /* SRC_RENDERER_RAYTRACER_RAYTRACERFACTORY_H_ */


