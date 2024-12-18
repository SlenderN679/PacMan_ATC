#pragma once
#include "list"
#include "_Size_TXY.h"
using namespace std;
enum ObjTypes{WALL_O, PORTAL_O, INTER_O};
class StaticObject{
	Size_TXY coords;								// Coordinates of the object
	const ObjTypes type;							// Type of the object
	static list<StaticObject*> objects;				// List of objects
public:
	StaticObject(Size_TXY coords, ObjTypes type);	// Constructor
	Size_TXY Coords();								// Get the coordinates of the object
	ObjTypes Type();								// Get the type of the object
	static void ClearObjects();						// Clear the list of objects
};

