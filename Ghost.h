#pragma once
#include "PacMan.h"
#include "DynamicEntity.h"
#include "_Directions.h"
#include "list"

class PacMan; // extern

using namespace std;
enum GstNames { BLINKY/*RED*/, PINKY/*PINK*/, INKY/*BLUE*/, CLYDE/*ORANGE*/ , X};
class Ghost : public DynamicEntity {
	Directions direction;						// Direction of the ghost
	const GstNames name;						// Name of the ghost
	static list<Ghost*> ghosts;					// List of ghosts
	Size_TXY target;							// Target of the ghost
	Size_TXY scatter;							// Scatter point of the ghost
	bool inHome;								// If the ghost is in the home
	int wallCount;								// Number of walls the ghost has hit consecutively
	bool attack;								// If the ghost is attacking
	static PacMan* p;							// PacMan object
	bool leave;									// If the ghost is leaving the home
protected:
	unsigned char prevSpot;						// Previous spot of the ghost
public:
	Ghost(Size_TXY coords, GstNames name);		// Constructor
	void Move();								// Move the ghost
	Directions Direction() const;				// Get the direction of the ghost
	GstNames getNames();						// Get the name of the ghost
	static GstNames getNames(Size_TXY pos);		// Get the name of the ghost in a position
	void Home();								// Move the ghost while inside the home
	void Roam();								// Move the ghost while outside the home
	void scatter_timer(int seconds);			// Scatter timer *parallel*
	static void start_ghosts(bool* gameRunning);// Start the ghosts *parallel*
	static void AddPacMan(PacMan& p);			// Add the PacMan object
	static void ClearGhosts();					// Clear the list of ghosts
};