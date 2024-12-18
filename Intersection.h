#pragma once
#include "_Directions.h"
#include "StaticObject.h"
#include "Map.h"
class Intersection : public StaticObject {
	static list<Intersection> intersections;					// List of intersections
	list<Directions> outs;										// List of directions
public:
	Intersection(Size_TXY coords, list<Directions> ways);		// Constructor
	static void CreateIntersections();							// Create the intersections
	list<Directions> Outs();									// Get the list of directions
	Size_TXY Coords();											// Get the coordinates of the intersection
	static list<Directions> isIntersection(Size_TXY coords);	// Check if the position is an intersection
	static void ClearIntersections();							// Clear the list of intersections
};