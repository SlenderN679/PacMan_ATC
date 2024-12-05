#pragma once
#include "Object.h"
#include "Map.h"
#include "list"
using namespace std;
class Wall : public Object{
	static list<Wall*> walls;
public:
	Wall(size_t width, size_t height, Size_TXY coords);
	static void CreateWalls();
};

