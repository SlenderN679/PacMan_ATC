#pragma once
#include "_Size_TXY.h"	
#include "DynamicEntity.h"
#include "StaticObject.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Dot.h"
#include "Wall.h"
#include <curses.h>
#define SPACE 32
#define PACMAN 184
#define GHOST 225
#define WALL_ 176
#define WALL 219
#define BYTE 157
#define BIT 155
#define PORTAL 245
#define INTER 206

#define COLS 28
#define ROWS 36
class PacMan;
class Map {
	static unsigned char maze[ROWS][COLS];				// The map
public:
	Map();												// Constructor
	void drawMap();										// Draw the map
	static bool add(Size_TXY pos, unsigned char type);	// Add an object to the map
	static bool addWall(Size_TXY pos);					// Add a wall to the map
	static bool addPortal(Size_TXY pos);				// Add a portal to the map
	static bool clearCell(Size_TXY pos);				// Clear a cell
	static unsigned char getCell(Size_TXY pos);			// Get the object in a cell
};
