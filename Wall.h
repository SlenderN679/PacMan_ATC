#pragma once
#include "StaticObject.h"
#include "Map.h"
#include "list"
using namespace std;
class Wall : public StaticObject{
	size_t width;
	size_t height;
	static list<Wall*> walls;
public:
	Wall(size_t width, size_t height, Size_TXY coords);
	Wall(Size_TXY coords);
	static void CreateWalls();
	static void CreateWall(Size_TXY coords);
};

