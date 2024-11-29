#pragma once
#include "list"
#include "_Size_TXY.h"
using namespace std;
enum ObjTypes{WALL_O, PORTAL_O, INTER_O};
class Object{
	size_t width;
	size_t height;
	Size_TXY coords;
	const ObjTypes type;
	static list<Object*> objects;
public:
	Object(size_t width, size_t height, Size_TXY coords, ObjTypes type);
	Size_TXY getCoords();
	ObjTypes getType();
};

