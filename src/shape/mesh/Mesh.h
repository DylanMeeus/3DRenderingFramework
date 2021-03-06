#ifndef MESH_H_
#define MESH_H_

#include <string>
#include <vector>
#include "shape/Shape.h"
#include "shape/mesh/IFace.h"

class Mesh: public Shape
{
	std::vector<Point> verts;
	std::vector<Vector> norms;
	std::vector<IFace*> faces;

public:
	Mesh(const std::string & filename);
	virtual HitInfo intersection(const Ray & ray);

private:
	void readFile(const std::string & filename);
};

#endif /* MESH_H_ */
