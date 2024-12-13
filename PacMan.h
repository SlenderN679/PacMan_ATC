#pragma once
#include "DynamicEntity.h"
#include "_Directions.h"
#include "Dot.h"
#include "Ghost.h"
#include "Wall.h"
#include "Portal.h"
#include "Map.h"
#include "Intersection.h"
#include "list"
using namespace std;
class PacMan : public DynamicEntity {
	Directions direction;
	Directions nextDirection;
	int lives;
	int score;
public:
	PacMan();
	Size_TXY Move();
	void Turn(Directions direction);
	void Hit();
	Directions getDirection() const;
	int getLives() const;
	int getScore() const;
	void UpdateStats();
};