#include "Wall.h"
list<Wall> Wall::walls;
Wall::Wall(float width, float height, Size_TXY coords, ObjTypes type) : Object(width, height, coords, type) {
	walls.push_back(*this);
}