/*
 * RotateTransfo.cpp
 *
 *  Created on: 21-nov.-2014
 *      Author: Dylan
 */



#include "RotateTransfo.h"
#include <math.h>

#include <iostream>
RotateTransfo::RotateTransfo(double angle, double x, double y, double z)
{

	 	Vector ra = Vector(x, y, z);
	    ra.normalize();

	    double rad = angle * (M_PI / 180);

	    mat.m[0][0] = cos(rad) + pow(ra.x, 2) * (1 - cos(rad));
	    mat.m[0][1] = ra.x * ra.y * (1 - cos(rad)) - ra.z * sin(rad);
	    mat.m[0][2] = ra.x * ra.z * (1 - cos(rad)) + ra.y * sin(rad);
	    mat.m[1][0] = ra.x * ra.y * (1 - cos(rad)) + ra.z * sin(rad);
	    mat.m[1][1] = cos(rad) + pow(ra.y, 2) * (1 - cos(rad));
	    mat.m[1][2] = ra.y * ra.z * (1 - cos(rad)) - ra.x * sin(rad);
	    mat.m[2][0] = ra.x * ra.z * (1 - cos(rad)) - ra.y * sin(rad);
	    mat.m[2][1] = ra.y * ra.z * (1 - cos(rad)) + ra.x * sin(rad);
	    mat.m[2][2] = cos(rad) + pow(ra.z, 2) * (1 - cos(rad));

	    invMat.m[0][0] = cos(rad) + pow(ra.x, 2) * (1 - cos(rad));
	    invMat.m[0][1] = ra.x * ra.y * (1 - cos(rad)) + ra.z * sin(rad);
	    invMat.m[0][2] = ra.x * ra.z * (1 - cos(rad)) - ra.y * sin(rad);
	    invMat.m[1][0] = ra.x * ra.y * (1 - cos(rad)) - ra.z * sin(rad);
	    invMat.m[1][1] = cos(rad) + pow(ra.y, 2) * (1 - cos(rad));
	    invMat.m[1][2] = ra.y * ra.z * (1 - cos(rad)) + ra.x * sin(rad);
	    invMat.m[2][0] = ra.x * ra.z * (1 - cos(rad)) + ra.y * sin(rad);
	    invMat.m[2][1] = ra.y * ra.z * (1 - cos(rad)) - ra.x * sin(rad);
	    invMat.m[2][2] = cos(rad) + pow(ra.z, 2) * (1 - cos(rad));


	/*
	Vector r = Vector(x,y,z);
	r.normalize();
	angle = angle *(M_PI/180);
	//mat = Matrix();
	fillMatrix(mat,angle,r);
	//invMat = Matrix();
	fillMatrix(invMat,-angle,r);
	*/
}

void RotateTransfo::fillMatrix(Matrix matrix, double theta, Vector& r)
{
		matrix.m[0][0] = cos(theta) + pow(r.x,2)*(1-cos(theta));
		matrix.m[0][1] = r.x*r.y*(1-cos(theta)) - r.z*sin(theta);
		matrix.m[0][2] = r.x*r.z*(1-cos(theta)) + r.y*sin(theta);
		matrix.m[1][0] = r.x*r.z*(1-cos(theta))+r.z*sin(theta);
		matrix.m[1][1] = cos(theta) + pow(r.y,2)*(1-cos(theta));
		matrix.m[1][2] = r.y*r.z*(1-cos(theta)) - r.x*sin(theta);
		matrix.m[2][0] = r.x*r.z*(1-cos(theta)) - r.y * sin(theta);
		matrix.m[2][1] = r.y*r.z*(1-cos(theta)) + r.x*sin(theta);
		matrix.m[2][2] = cos(theta) + pow(r.z,2)*(1-cos(theta));
		matrix.m[3][3] = 1;

}
