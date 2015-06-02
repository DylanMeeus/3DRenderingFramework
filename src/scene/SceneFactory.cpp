#include "scene/SceneFactory.h"
#include "util/Point.h"
#include "util/Colour.h"
#include "shape/Sphere.h"
#include "shape/Square.h"
#include "shape/mesh/Mesh.h"
#include <iostream>
#include <cstdlib>

Scene SceneFactory::createScene(const std::string & filename)
{

	Scene scene;
	Material currMtrl;

	//Transfo currTransfo;
	TransfoStack transfoStack = TransfoStack();

	std::ifstream inf(filename.c_str());
	if (!inf)
	{
		std::cout << "SDL file " << filename << " could not be opened!\n";
		exit(1);
	}

	while (inf)
	{
		std::string key;
		inf >> key;
		if (key.empty())
		{
			continue;
		}
		if (key.compare("background") == 0)
		{
			double r, g, b;
			inf >> r >> g >> b;
			scene.setBackground(Colour(r, g, b));
			std::cout << "set background" << std::endl;
		}
		else if(key.compare("light")==0)
		{
			double x,y,z,r,g,b;
			inf >> x >> y >> z >> r >> g >> b;
			Point lightPos = Point(x,y,z);
			Colour colour = Colour(r,g,b);
			Light * light;
			light = new Light(lightPos,colour);
			scene.addLight(light);
		}
		else if (!processMaterial(inf, key, currMtrl))
		{
			if(!processTransfo(inf, key, transfoStack))
			{
				scene.addObject(createShape(inf, key, currMtrl, transfoStack.top()));
			}
		}

	}
	return scene;
}

bool SceneFactory::processTransfo(std::ifstream & inf, const std::string & key, TransfoStack & transfoStack)
{
	if(key.compare("scale")==0)
	{
		double sx,sy,sz;
		inf >> sx >> sy >> sz;
		//currTransfo = ScaleTransfo(sx,sy,sz);
		transfoStack.transform(ScaleTransfo(sx,sy,sz));
		return true;
	}
	if(key.compare("translate")==0)
	{
		double tx,ty,tz;
		inf >> tx >> ty >> tz;
		transfoStack.transform(TranslateTransfo(tx,ty,tz));
		//currTransfo.transform(TranslateTransfo(tx,ty,tz));
		return true;
	}
	if(key.compare("rotate")==0)
	{
		double angle, x, y ,z;
		inf >> angle >> x >> y >> z;
		std::cout << "rotate!" << angle << " " << x << " " << y << " " << z  << std::endl;
		transfoStack.transform(RotateTransfo(angle,x,y,z));
		return true;
	}
	if(key.compare("push")==0)
	{
		transfoStack.push();
		return true;
	}
	if(key.compare("pop")==0)
	{
		transfoStack.pop();
		return true;
	}

	return false;
}

bool SceneFactory::processMaterial(std::ifstream & inf, const std::string & key,
		Material & currMtrl)
{
	if (key.compare("diffuse") == 0)
	{
		double r, g, b;
		inf >> r >> g >> b;
		currMtrl.setDiffuse(Colour(r, g, b));
		return true;
	}
	if(key.compare("ambient")==0)
	{
		double r, g, b;
		inf >> r >> g >> b;
		currMtrl.setAmbient(Colour(r, g, b));
		return true;
	}

	return false;
}

Shape * SceneFactory::createShape(std::ifstream & inf, const std::string & key,	const Material & currMtrl,
		 Transfo & currTransfo)
{
	Shape * shape;
	if (key.compare("sphere") == 0)
	{
		shape = new Sphere;
	}
	else if (key.compare("square")==0)
	{
		shape = new Square;
	}
	else if (key.compare("mesh")==0)
	{
		std::string resource = "";
		inf >> resource;
		shape = new Mesh(resource);
		std::cout << "mesh added, resource: "<< resource << std::endl;
	}


	else
	{
		std::cout << "Token " << key << " in SDL file is not supported!\n";
		exit(1);
	}
	shape->setMaterial(Material(currMtrl));
	shape->setTransfo(Transfo(currTransfo));
	return shape;
}
