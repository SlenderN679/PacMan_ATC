#include "Portal.h"
list<Portal> Portal::portals;
Portal::Portal(Size_TXY coords, ObjTypes type, Sides side) : StaticObject(coords, type), side(side) {
	portals.push_back(*this);
}