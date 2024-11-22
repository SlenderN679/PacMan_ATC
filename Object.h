#pragma once
#include "list"
#include "_Size_TXY.h"
using namespace std;
enum ObjTypes{WALL_O, PORTAL_O};
class Object{
	float width;
	float height;
	Size_TXY coords;
	const ObjTypes type;
	static list<Object*> objects;
public:
	Object(float width, float height, Size_TXY coords, ObjTypes type);
	Size_TXY getCoords();
	ObjTypes getType();
};

