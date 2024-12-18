#pragma once
#include "Dot.h"
#include "Drawing.h"

class Dot_UI : public Dot, public Drawing {
	static list<Dot_UI*> dots;				// List of dots
public:
	Dot_UI(Size_TXY pos, EntTypes type);	// Constructor
	void Draw(Size_TXY coords);				// Draw the object
	void Update();							// Update the object
	static bool CreateDots();				// Create the dots
	Size_TXY Start();						// Get the start position of the object
	static list<Dot_UI*> DotList();			// Get the list of dots
	void RemoveFromDerivedList() override;	// Remove the object from the list
	EntTypes Type();						// Get the type of the object
	static void ClearDots();				// Clear the list of dots
};