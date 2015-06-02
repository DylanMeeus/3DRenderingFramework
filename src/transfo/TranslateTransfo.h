/*
 * TranslateTransfo.h
 *
 *  Created on: 21-nov.-2014
 *      Author: Dylan
 */

#ifndef SRC_TRANSFO_TRANSLATETRANSFO_H_
#define SRC_TRANSFO_TRANSLATETRANSFO_H_

#include "Transfo.h"

class TranslateTransfo : public Transfo
{
public:
	TranslateTransfo(double tx, double ty, double tz);
};

#endif /* SRC_TRANSFO_TRANSLATETRANSFO_H_ */
