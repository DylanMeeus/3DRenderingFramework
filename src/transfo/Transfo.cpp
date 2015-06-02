#include "Transfo.h"

#include <iostream>
Transfo & Transfo::operator=(const Transfo & transfo){
	if(this == &transfo)
		return *this;
	mat = transfo.mat;
	invMat = transfo.invMat;
	return *this;
}

void Transfo::transform(Transfo transfo)
{
	mat.postMult(transfo.mat);
	invMat.preMult(transfo.getInvMat());
}


