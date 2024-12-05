#pragma once
#include "_Size_TXY.h"	
#include "Entity.h"
#define SPACE 32
#define PACMAN 184
#define GHOST 225
#define WALL_ 176
#define WALL 219
#define BYTE 157
#define BIT 155
#define PORTAL 245
#define INTER 206
class Map {
	static unsigned char maze[36][28];
public:
	Map();
	void drawMap();
	static bool add(Size_TXY pos, unsigned char type);
	static bool addPacman(Size_TXY pos);
	static bool addGhost(Size_TXY pos);
	static bool addWall(Size_TXY pos);
	static bool addByte(Size_TXY pos);
	static bool addBit(Size_TXY pos);
	static bool addPortal(Size_TXY pos);
	static bool addInter(Size_TXY pos);
	static bool clearCell(Size_TXY pos);
	static unsigned char getCell(Size_TXY pos);
};
/*
#define PACMAN 67
#define GHOST 71
#define WALL 178
#define BYTE 48
#define BIT 111
*/