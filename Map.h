#pragma once
#include "_Size_TXY.h"	
#define SPACE 32
#define PACMAN 184
#define GHOST 225
#define WALL 178
#define BYTE 157
#define BIT 155
#define PORTAL 245
class Map {
	static unsigned char maze[36][28];
public:
	Map();
	void drawMap();
	static bool addPacman(Size_TXY pos);
	bool addGhost(Size_TXY pos);
	bool addWall(Size_TXY pos);
	bool addByte(Size_TXY pos);
	bool addBit(Size_TXY pos);
	static bool addPortal(Size_TXY pos);
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