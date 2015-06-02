/*
 * TransfoStack.cpp
 *
 *  Created on: 26-nov.-2014
 *      Author: Dylan
 */

#include "TransfoStack.h"

#include <iostream>
TransfoStack::TransfoStack()
{
	transfoStack.push(Transfo());
}

void TransfoStack::pop()
{
	transfoStack.pop();
}

void TransfoStack::push()
{
    transfoStack.push(top());
}

void TransfoStack::transform(const Transfo& transfo)
{
	std::cout << "here" << std::endl;
	top().transform(transfo);
}
