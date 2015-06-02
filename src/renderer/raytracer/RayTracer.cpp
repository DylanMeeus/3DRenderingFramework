#include "RayTracer.h"

/*
Colour RayTracer::shadeHit(const Ray & ray, const HitInfo & hitInfo)
{
	return hitInfo.getHitMaterial().getDiffuse();
}
*/

Colour RayTracer::shadeHit(const Ray & ray, const HitInfo & hitInfo)
{
	Colour ambient = hitInfo.getHitMaterial().getAmbient();
	Colour diffuse = hitInfo.getHitMaterial().getDiffuse();
	double Is = 1; // white light, 0 = no light

	std::vector<Light*> lights = scene.getLights();
	Light* oneLight = lights.at(0);

	Vector S = Vector(oneLight->getPosition(), hitInfo.getHitPoint());
	Vector M = hitInfo.getHitNormal();
//	std::cout << "S:" << S.x << " " << S.y << " " << S.z << " " << std::endl;
	//std::cout << "hitinfo: " << hitInfo.getHitNormal().x << std::endl;
	//std::cout << "M:" << M.x << " " << M.y << " " << M.z << " " << std::endl;
	double Ir, Ig, Ib;
//	std::cout << oneLight->getPosition().x << " " << oneLight->getPosition().y << " " << oneLight->getPosition().z <<std::endl;
	if(S.dot(M) > 0)
	{
		double cosinusalpha = S.dot(M) / S.length()*M.length();

		Ir = diffuse.r*Is * cosinusalpha + ambient.r * Is;
		Ig = diffuse.g*Is * cosinusalpha + ambient.g * Is;
		Ib = diffuse.b*Is * cosinusalpha + ambient.b * Is;
	}
	else
	{
		//std::cout << "second" << std::endl;
		Ir = ambient.r * Is;
		Ig = ambient.g * Is,
		Ib = ambient.b * Is;
	}
	return Colour(Ir,Ig,Ib);
	//return Colour(0,0,1);
}
