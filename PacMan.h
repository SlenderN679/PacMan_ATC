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
	Directions direction;				// Direction of the pacman
	Directions nextDirection;			// Next direction of the pacman
	int lives;							// Number of lives of the pacman
	int score;							// Score of the pacman
	bool hit;							// If the pacman is hit
public:
	Size_TXY pacmanStart;				// Start position of the pacman
	PacMan();							// Constructor
	Size_TXY Move();					// Move the pacman
	void Turn(Directions direction);	// Turn the pacman
	Size_TXY Hit();						// Hit the pacman
	Directions Direction() const;		// Get the direction of the pacman
	int Lives() const;					// Get the lives of the pacman
	int Score() const;					// Get the score of the pacman
};