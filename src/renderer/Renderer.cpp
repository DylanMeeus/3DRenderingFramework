#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif


#include "Ray.h"
#include "Renderer.h"
#include <string>
#include <iostream>
#include <cstdlib> // fix for atoi
#include "renderer/raytracer/RaytracerFactory.h"

Renderer::Renderer(const Camera * const camera, const Scene & scene, AppConfiguration & appCfg) :	scene(scene), camera(camera)
{
	nCols = std::atoi(appCfg["image.nCols"].c_str());
	nRows = std::atoi(appCfg["image.nRows"].c_str());
	//rayTracer = new RayTracer(scene); pre-factory way
	//RaytracerFactory rf = RaytracerFactory();
	rayTracer = RaytracerFactory::createRayTracer(scene, appCfg);
}

void Renderer::render()
{
	double width = camera->getWidth()/nCols;
	double height = camera->getHeight()/nRows;
	//std::cout << width << " " << height << std::endl;

	Vector v1 = (-1*(camera->getWidth()/2.))*camera->getU() + ((camera->getHeight()/2.)*camera->getV());
	Vector v3 = -camera->getDistance()*camera->getN() + v1;
	for(int r = 0; r < nRows ; r++)
	{
		for(int c=0; c < nCols; c++)
		{

			Vector v2 = ((c*width)*camera->getU()) - ((r*height)*camera->getV());
			//std::cout << v2.x << " " << v2.y << " " << v2.z << std::endl;
			Vector dir = v3 + v2;
//			std::cout << dir.x << " " << dir.y << " " << dir.z << std::endl;
		//	std::cout << camera->getEye().x << " " << camera->getEye().y << " " << camera->getEye().z << std::endl;

			Ray ray =  Ray(camera->getEye(),dir);
			Colour col = rayTracer->shade(ray);
			//if(col.r == 1)
			//std::cout << c << " " << r << " " << col.r << " " << col.g << " " << col.b << std::endl;
			glColor3d(col.r,col.g,col.b);
			glRecti(c,nRows-r,c+1,nRows-r-1);
		}
	}

}

Renderer::~Renderer()
{
	delete rayTracer;
	rayTracer = 0;
}


