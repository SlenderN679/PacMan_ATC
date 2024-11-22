#pragma once
#include "Object.h"
#include "list"
using namespace std;
enum Sides { P_RIGHT, P_LEFT };
class Portal : public Object {
	Sides side;
	static list<Portal> portals;
public:
	Portal(float width, float height, Size_TXY coords, ObjTypes type, Sides side);
};