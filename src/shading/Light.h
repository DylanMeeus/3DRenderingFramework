/*
 * Light.h
 *
 *  Created on: 10-nov.-2014
 *      Author: Dylan
 */

#ifndef SRC_SHADING_LIGHT_H_
#define SRC_SHADING_LIGHT_H_


class Light
{
	Point position;
	Colour colour;

public:

	Light(const Point _position, const Colour _colour)
	{
		position = _position;
		colour = _colour;
	}


	const Colour & getColour() const { return colour; }
	const Point & getPosition() const { return position; }

	void setColour(const Colour & _colour) { this->colour = _colour; }
	void setPosition(const Point & _position) { this->position = _position; }



};


#endif /* SRC_SHADING_LIGHT_H_ */
