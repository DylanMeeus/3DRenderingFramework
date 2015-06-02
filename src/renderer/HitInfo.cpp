#include "HitInfo.h"

void HitInfo::copy(const HitInfo & hitInfo){
	t = hitInfo.t;
	hitPoint = Point(hitInfo.hitPoint);
	hitMaterial = Material(hitInfo.hitMaterial);
	hitNormal = Vector(hitInfo.hitNormal);
}

HitInfo::HitInfo(const HitInfo & hitInfo){
	copy(hitInfo);
}

HitInfo& HitInfo::operator=(const HitInfo & hitInfo){
	if(this == &hitInfo){
		return *this;
	}
	copy(hitInfo);
	return *this;
}






