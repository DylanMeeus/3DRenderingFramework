#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "util/Colour.h"

class Material {

	Colour diffuse;
	Colour ambient = Colour(0.2,0,0);
public:

	Material();

	Material(const Material & mtrl);

	Material& operator=(const Material & mtrl);

	const Colour & getDiffuse() const { return diffuse; }
	const Colour & getAmbient() const { return ambient; }
	void setDiffuse(const Colour & _diffuse) { this->diffuse = _diffuse; }
	void setAmbient(const Colour & _ambient) { this->ambient = _ambient;}
};

#endif /* MATERIAL_H_ */
