#pragma once
#include "StaticObject.h"
#include "Map.h"
#include "list"
using namespace std;
enum Sides { P_RIGHT, P_LEFT };
class Portal : public StaticObject {
	Sides side;											// Side of the portal
	static list<Portal> portals;						// List of portals
public:
	Portal(Size_TXY coords, ObjTypes type, Sides side);	// Constructor
	static void CreatePortals();						// Create the portals
	static void ClearPortals();							// Clear the list of portals
};