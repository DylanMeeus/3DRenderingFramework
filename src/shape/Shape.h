#ifndef SHAPE_H_
#define SHAPE_H_

#include "shape/IRaytraceable.h"
#include "shading/Material.h"
#include "transfo/Transfo.h"

class Shape: public IRaytraceable {

protected:
	Transfo transfo;

public:

	Material mtrl;
public:

	Shape(){ }

	const Material& getMaterial() const { return mtrl; }
	const Transfo& getTransfo() const { return transfo; }
	void setMaterial(const Material& mtrl) { this->mtrl = mtrl; }
	void setTransfo(const Transfo& transformation){ this->transfo = transformation; }

};

#endif /* SHAPE_H_ */
