#pragma once
#include "Object.h"
#include "list"
using namespace std;
class Wall : public Object{
	static list<Wall> walls;
public:
	Wall(float width, float height, Size_TXY coords, ObjTypes type);
};

