#pragma once
#include "_Directions.h"
#include "Object.h"
#include "Map.h"
class Intersection : public Object {
	static list<Intersection> intersections;
	list<Directions> outs;
public:
	Intersection(Size_TXY coords,list<Directions> ways);
	//static list<Intersection> GetIntersections();
	static void CreateIntersections();
	list<Directions> Outs();
	Size_TXY Coords();
	static list<Directions> isIntersection(Size_TXY coords);
};