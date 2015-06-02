#ifndef SCENEFACTORY_H_
#define SCENEFACTORY_H_

#include <string>
#include <fstream>
#include "shading/Material.h"
#include "shape/Shape.h"
#include "scene/Scene.h"
#include "transfo/ScaleTransfo.h"
#include "transfo/TranslateTransfo.h"
#include "transfo/RotateTransfo.h"
#include "transfo/TransfoStack.h"
class SceneFactory {

	static bool processTransfo(std::ifstream & inf, const std::string & key, TransfoStack & transfoStack);
	static bool processMaterial(std::ifstream & inf, const std::string & key, Material & currMtrl);

	static Shape * createShape(std::ifstream & inf, const std::string & key, const Material & currMtrl, Transfo & currTransfo );

public:

	static Scene createScene(const std::string & filename);

};

#endif /* SCENEFACTORY_H_ */
