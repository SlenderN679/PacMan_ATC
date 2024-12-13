#include "Portal.h"
list<Portal> Portal::portals;
Portal::Portal(float width, float height, Size_TXY coords, ObjTypes type, Sides side) : StaticObject(width, height, coords, type), side(side) {
	portals.push_back(*this);
}