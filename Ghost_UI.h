#pragma once
#include "Ghost.h"
#include "Drawing.h"

class Ghost_UI : public Ghost, public Drawing {
	static list<Ghost_UI*> ghosts;					// List of ghosts
public:
	Ghost_UI(Size_TXY coords, GstNames name);		// Constructor
	void Draw(Size_TXY coords);						// Draw the object
	void Update();									// Update the object
	static void CreateGhosts();						// Create the ghosts
	Size_TXY Start();								// Get the start position of the object
	static list<Ghost_UI*> GhostList();				// Get the list of ghosts
	EntTypes Type() override;						// Get the type of the object
	static void ClearGhosts();						// Clear the list of ghosts
};
	
