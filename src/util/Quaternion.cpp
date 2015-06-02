/*
 * Quaternion.cpp
 *
 *  Created on: 13-nov.-2014
 *      Author: Dylan
 */

#include "Quaternion.h"

Quaternion operator*(Quaternion one, Quaternion two)
{

	// refactor code
double aOne = one.a;
double bOne = one.b;
double cOne = one.c;
double dOne = one.d;
double aTwo = two.a;
double bTwo = two.b;
double cTwo = two.c;
double dTwo = two.d;

double aNew = (aOne*aTwo - bOne*bTwo - cOne*cTwo - dOne*dTwo);
double bNew = (aOne*bTwo + bOne*aTwo + cOne * dTwo - dOne*cTwo);
double cNew = (aOne*cTwo - bOne*dTwo + cOne*aTwo + dOne*bTwo);
double dNew = (aOne*dTwo + bOne*cTwo - cOne*bTwo + dOne*aTwo);

return Quaternion(aNew,bNew,cNew,dNew);
}

Quaternion Quaternion::conjugate()
{

	return Quaternion(a,-b,-c,-d);
}


