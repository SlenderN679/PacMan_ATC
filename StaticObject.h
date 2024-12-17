#pragma once
#include "list"
#include "_Size_TXY.h"
using namespace std;
enum ObjTypes{WALL_O, PORTAL_O, INTER_O};
class StaticObject{
	Size_TXY coords;
	const ObjTypes type;
	static list<StaticObject*> objects;
public:
	StaticObject(Size_TXY coords, ObjTypes type);
	Size_TXY getCoords();
	ObjTypes getType();
};

