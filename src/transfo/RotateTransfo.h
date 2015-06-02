/*
 * RotateTransfo.h
 *
 *  Created on: 21-nov.-2014
 *      Author: Dylan
 */

#ifndef SRC_TRANSFO_ROTATETRANSFO_H_
#define SRC_TRANSFO_ROTATETRANSFO_H_

#include "Transfo.h"

class RotateTransfo : public Transfo
{

	public:
		RotateTransfo(double angle, double x, double y, double z);
		void fillMatrix(Matrix matrix, double theta, Vector& r);
	private:
};


#endif /* SRC_TRANSFO_ROTATETRANSFO_H_ */
