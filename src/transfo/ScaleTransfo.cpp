/*
 * ScaleTransfo.cpp
 *
 *  Created on: 19-nov.-2014
 *      Author: Dylan
 */

#include "ScaleTransfo.h"

ScaleTransfo::ScaleTransfo(double sx, double sy, double sz)
{
//mat = Matrix();
mat.m[0][0] = sx;
mat.m[1][1] = sy;
mat.m[2][2] = sz;
mat.m[3][3] = 1;

//invMat = Matrix();
invMat.m[0][0] = 1/sx;
invMat.m[1][1] = 1/sy;
invMat.m[2][2] = 1/sz;
invMat.m[3][3] = 1;
}
