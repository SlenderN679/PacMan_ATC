#pragma once
#include "StaticObject.h"
#include "Map.h"
#include "list"
using namespace std;
class Wall : public StaticObject{
	size_t width;											// Width of the wall
	size_t height;											// Height of the wall
	static list<Wall*> walls;								// List of walls
public:
	Wall(size_t width, size_t height, Size_TXY coords);		// Constructor of a block of walls
	Wall(Size_TXY coords);									// Constructor of a single wall
	static void CreateWalls();								// Create the walls
	static void CreateWall(Size_TXY coords);				// Create a wall
	static void ClearWalls();								// Clear the list of walls
};

