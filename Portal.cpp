#include "Portal.h"
list<Portal> Portal::portals;
Portal::Portal(Size_TXY coords, ObjTypes type, Sides side) : StaticObject(coords, type), side(side) {
	portals.push_back(*this);
	Map::addPortal(coords);
}
void Portal::CreatePortals() {
	portals.push_back(Portal({ 0, 17 }, PORTAL_O, P_RIGHT));
	portals.push_back(Portal({ 27, 17 }, PORTAL_O, P_LEFT));
}
void Portal::ClearPortals() {
	/*for (Portal p : portals) {
		delete& p;
	}*/
	portals.clear();
}