#pragma once
#include "PacMan.h"
#include "Drawing.h"
class PacMan_UI : public PacMan, public Drawing {
public:
	PacMan_UI();					// Constructor
	Size_TXY pacmanStart;			// Start position of the pacmanPacMan_UI();					
	void Draw(Size_TXY coords);		// Draw the object
	void Update();					// Update the object
	Size_TXY Start();				// Get the start position of the object
	EntTypes Type();				// Get the type of the object
};