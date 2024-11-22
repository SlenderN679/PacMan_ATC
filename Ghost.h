#pragma once
#include "Entity.h"
#include "_Directions.h"
#include "list"
using namespace std;
enum GstTypes { BLINKY/*RED*/, PINKY/*PINK*/, INKY/*BLUE*/, CLYDE/*ORANGE*/ };
class Ghost : public Entity {
	Directions direction;
	const GstTypes type;
	static list<Ghost*> ghosts;
public:
	Ghost(Size_TXY coords, GstTypes type);
	void move();
	Directions getDirection();
	GstTypes getType();
	void wall();
	bool teleport();
};