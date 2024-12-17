#pragma once
#include "_Directions.h"
#include "StaticObject.h"
#include "Map.h"
class Intersection : public StaticObject {
	static list<Intersection> intersections;
	list<Directions> outs;
public:
	Intersection(Size_TXY coords,list<Directions> ways);
	static void CreateIntersections();
	list<Directions> Outs();
	Size_TXY Coords();
	static list<Directions> isIntersection(Size_TXY coords);
};