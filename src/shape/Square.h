/*
 * Square.h
 *
 *  Created on: 8-nov.-2014
 *      Author: Dylan
 */

#ifndef SRC_SHAPE_SQUARE_H_
#define SRC_SHAPE_SQUARE_H_


#include "shape/Shape.h"

class Square: public Shape {

public:

	virtual HitInfo intersection(const Ray & ray);

};


#endif /* SRC_SHAPE_SQUARE_H_ */
