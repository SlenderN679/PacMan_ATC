#pragma once
#include "_Size_TXY.h"
//#include "Drawing.h"
#include "chrono"
#include "thread"
#include <cstdlib>
#include <fstream>
#include <string>
#include <curses.h>
#include <stdio.h>
#include <list>
enum EntTypes {BIT_E, BYTE_E, GHOST_E, PACMAN_E, XX};

#define BRANCO 0
#define AZUL 1
#define AMARELO 2
#define VERDE 3
#define VERMELHO 4
#define MAGENTA 5
#define CIANO 6

using namespace std;

class DynamicEntity {
	Size_TXY coords;								// Coordinates of the object
	Size_TXY start;									// Start position of the object
	const EntTypes type;							// Type of the object
	static list<DynamicEntity*> entities;			// List of objects
protected:
	static bool rage;								// If the objects are in rage mode
	Size_TXY GStart();								// Start position of the ghost
	void PStart(Size_TXY c);						// Start position of the pacman
public:
	DynamicEntity(Size_TXY coords, EntTypes type);	// Constructor
	Size_TXY Move(IntXY dis);						// Move the object
	Size_TXY Position() const;						// Get the position of the object
	Size_TXY Start() const;							// Get the start position of the object
	EntTypes Type() const;							// Get the type of the object
	static bool Rage();								// Get the rage mode
	static void Calm();								// Calm the objects
	static EntTypes CheckPos(Size_TXY coords);		// Check the position of the object
	void rage_timer(int seconds);					// Rage timer *parallel*
	void StartRage();								// Start the rage mode
	static list<DynamicEntity*> EntityList();		// Get the list of objects
	static void RemoveEntity(DynamicEntity* e);		// Remove the object from the list
	static void ClearEntities();					// Clear the list of objects
};