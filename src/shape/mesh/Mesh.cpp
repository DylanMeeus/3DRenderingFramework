#include "Mesh.h"
#include "shape/mesh/FlatFace.h"
#include "shape/mesh/IFace.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "util/Vector.h"
#include <cstdlib>

Mesh::Mesh(const std::string & filename)
{
	readFile(filename);
}

void Mesh::readFile(const std::string & filename)
{

	std::ifstream inf(filename.c_str());
	if (!inf)
	{
		std::cout << "Mesh file " << filename << " could not be opened!\n";
		exit(1);
	}
	int vertices, normals, flatfaces;
	inf >> vertices >> normals >> flatfaces;
	std::cout << "verts:" << vertices << " normals:" << normals << " faces " << flatfaces << std::endl;

	// loop over the vertices

	for(int i = 0; i < vertices ; i++)
	{
		double x,y,z;
		inf >> x >> y >> z;
		Point newPoint = Point(x,y,z);
//		std::cout << "vertice coordinate:" << newPoint.x << " " << newPoint.y << " " << newPoint.z << std::endl;
		verts.push_back(newPoint);
	}
	for(int j = 0; j < normals; j++)
	{
		double x, y, z;
		inf >> x >> y >> z;
		Vector normalVector = Vector(x,y,z);
//		std::cout << "normal vector: " << normalVector.x << " " << normalVector.y << " " << normalVector.z << std::endl;
		norms.push_back(normalVector);
	}
	for(int i = 0; i < flatfaces; i++)
	{
		// Point krijgt informatie uit de verts list.
		int amount, loc1, loc2, loc3, n1, n2, n3;
		inf >> amount >> loc1 >> loc2 >> loc3 >> n1 >> n2 >> n3;

		Point p1 = verts.at(loc1);
		Point p2 = verts.at(loc2);
		Point p3 = verts.at(loc3);
		Vector& v1 = norms.at(n1);
		Vector& v2 = norms.at(n2);
		Vector& v3 = norms.at(n3);
		//std::cout << "amount: " << amount << loc1 << loc2 << loc3 << n1 << n2 << n3 << std::endl;;

		FlatFace * face = new FlatFace(&p1,&p2,&p3,v1);
		std::cout << "face created" << std::endl;
		faces.push_back(face);

	}

}

HitInfo Mesh::intersection(const Ray & ray)
{
	HitInfo bestHitInfo(DBL_MAX);
	for (std::vector<IFace*>::iterator it = faces.begin(); it != faces.end(); ++it)
	{
		HitInfo hitInfo = (*it)->intersection(ray); // crash

		if (hitInfo.getT() < bestHitInfo.getT())
		{
			bestHitInfo = hitInfo;
		}
	}
	bestHitInfo.setHitMaterial(Material(mtrl));
	return bestHitInfo;
}
