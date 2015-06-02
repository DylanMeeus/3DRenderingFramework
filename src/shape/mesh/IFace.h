#ifndef IFACE_H_
#define IFACE_H_

#include "shape/IRaytraceable.h"
#include "util/Point.h"
#include "util/Vector.h"
#include "shape/Shape.h"

class IFace: public IRaytraceable {

public:
	virtual const Point & getVertex(unsigned int i) const = 0;
	virtual const Vector & getNormal(unsigned int i) const = 0;
	virtual const Vector & getFacePlaneNormal() const = 0;

	virtual ~IFace(){ };
};

#endif /* IFACE_H_ */
