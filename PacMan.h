#pragma once
#include "Entity.h"
#include "_Directions.h"
#include "Dot.h"
#include "Ghost.h"
#include "Wall.h"
#include "Portal.h"
#include "Map.h"
#include "Intersection.h"
#include "list"
using namespace std;
class PacMan : public Entity {
	Directions direction;
	Directions nextDirection;
	int lives;
	int score;
public:
	PacMan();
	void move();
	void turn(Directions direction);
	void hit();
	Directions getDirection() const;
	int getLives() const;
	int getScore() const;
};