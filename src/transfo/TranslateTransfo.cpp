/*
 * TranslateTransfo.cpp
 *
 *  Created on: 21-nov.-2014
 *      Author: Dylan
 */



#include "TranslateTransfo.h"


TranslateTransfo::TranslateTransfo(double tx, double ty, double tz)
{
	//mat = Matrix();
	mat.m[0][0] = 1;
	mat.m[1][1] = 1;
	mat.m[2][2] = 1;
	mat.m[3][3] = 1;
	mat.m[0][3] = tx;
	mat.m[1][3] = ty;
	mat.m[2][3] = tz;

//	invMat = Matrix();
	invMat.m[0][0] = 1;
	invMat.m[1][1] = 1;
	invMat.m[2][2] = 1;
	invMat.m[3][3] = 1;
	invMat.m[0][3] = -tx;
	invMat.m[1][3] = -ty;
	invMat.m[2][3] = -tz;



}
