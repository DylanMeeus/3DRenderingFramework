/*
 * TransfoStack.h
 *
 *  Created on: 26-nov.-2014
 *      Author: Dylan
 */

#ifndef SRC_TRANSFO_TRANSFOSTACK_H_
#define SRC_TRANSFO_TRANSFOSTACK_H_

#include <stack>
#include "Transfo.h"

class TransfoStack
{

public:
	std::stack<Transfo> transfoStack;

	TransfoStack();

	Transfo& top() { return transfoStack.top();}

	void push();

	void pop();

	void transform(const Transfo& transfo);
};

#endif /* SRC_TRANSFO_TRANSFOSTACK_H_ */
