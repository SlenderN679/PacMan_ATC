#pragma once
#include "PacMan.h"
#include "DynamicEntity.h"
#include "_Directions.h"
#include "list"

class PacMan; // extern

using namespace std;
enum GstNames { BLINKY/*RED*/, PINKY/*PINK*/, INKY/*BLUE*/, CLYDE/*ORANGE*/ , X};
class Ghost : public DynamicEntity {
	Directions direction;
	const GstNames name;
	static list<Ghost*> ghosts;
	Size_TXY target;
	Size_TXY scatter;
	unsigned char prevSpot;
	bool inHome;
	int wallCount;
	bool attack;
	static PacMan* p;
public:
	Ghost(Size_TXY coords, GstNames name);
	void Move();
	Directions getDirection() const;
	GstNames getNames();
	static GstNames getNames(Size_TXY pos);
	void Home();
	void Roam();
	static void CreateGhosts();
	/*static void MoveGhosts();*/
	void scatter_timer(int seconds);
	void start_timer(int seconds);
	static void Start();
	static void AddPacMan(PacMan& p);
};