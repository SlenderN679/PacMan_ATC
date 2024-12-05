#pragma once
#include "PacMan.h"
#include "Entity.h"
#include "_Directions.h"
#include "list"
class PacMan;
using namespace std;
enum GstNames { BLINKY/*RED*/, PINKY/*PINK*/, INKY/*BLUE*/, CLYDE/*ORANGE*/ };
class Ghost : public Entity {
	Directions direction;
	const GstNames name;
	static list<Ghost*> ghosts;
	Size_TXY target;
	Size_TXY scatter;
	unsigned char prevSpot;
	bool inHome;
	int wallCount;
	bool attack;
public:
	Ghost(Size_TXY coords, GstNames name);
	void move(const PacMan& p);
	Directions getDirection() const;
	GstNames getNames();
	void Home();
	void Roam(const PacMan& p);
	static void CreateGhosts();
	static void MoveGhosts(const PacMan& p);
	void scatter_timer(int seconds);
};