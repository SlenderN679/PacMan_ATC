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
	static unsigned char maze[ROWS][COLS];
public:
	Map();
	void drawMap();
	static bool add(Size_TXY pos, unsigned char type);
	static bool addWall(Size_TXY pos);
	static bool addPortal(Size_TXY pos);
	static bool clearCell(Size_TXY pos);
	static unsigned char getCell(Size_TXY pos);
};
