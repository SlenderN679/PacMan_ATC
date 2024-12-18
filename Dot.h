#pragma once
#include "DynamicEntity.h"
#include "Map.h"
#include "list"
using namespace std;
class Dot : public DynamicEntity {
	static list<Dot*> dots;					// List of dots
public:
	Dot(Size_TXY pos, EntTypes type);		// Constructor
	static bool CreateDots();				// Create the dots
	static bool Destroy(Size_TXY pos);		// Destroy a dot
	static int DotReamining();				// Get the number of dots remaining
	virtual ~Dot() = default;				// Destructor
	virtual void RemoveFromDerivedList();	// Remove the object from the list
	static bool CheckDot(Size_TXY pos);		// Check if there is a dot in a position
	static void ClearDots();				// Clear the list of dots
};