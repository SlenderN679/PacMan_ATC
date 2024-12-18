#include "Intersection.h"
list<Intersection> Intersection::intersections;
Intersection::Intersection(Size_TXY coords, list<Directions> ways) : StaticObject(coords,INTER_O) {
	outs = ways;
	intersections.push_back(*this);
	//Map::addInter(coords);
}
//list<Intersection> Intersection::GetIntersections() {
//	return intersections;
//}
void Intersection::CreateIntersections() {
	Intersection i1({ 6, 4 }, { RIGHT, LEFT, DOWN });
	Intersection i2({ 21, 4 }, { RIGHT, LEFT, DOWN });
	//---
	Intersection i3({ 1, 8 }, { RIGHT, UP, DOWN });
	Intersection i4({ 6, 8 }, { RIGHT, LEFT, UP, DOWN });
	Intersection i5({ 9, 8 }, { RIGHT, LEFT, DOWN });
	Intersection i6({ 12, 8 }, { RIGHT, LEFT, UP });
	Intersection i7({ 15, 8 }, { RIGHT, LEFT, UP });
	Intersection i8({ 18, 8 }, { RIGHT, LEFT, DOWN });
	Intersection i9({ 21, 8 }, { RIGHT, LEFT, UP, DOWN });
	Intersection i10({ 26, 8 }, { LEFT, UP, DOWN });
	//---
	Intersection i11({ 6, 11 }, { LEFT, UP, DOWN });
	Intersection i12({ 21, 11 }, { RIGHT, UP, DOWN });
	//---
	Intersection i13({ 12, 14 }, { RIGHT, LEFT, UP });
	Intersection i14({ 15, 14 }, { RIGHT, LEFT, UP });
	//---
	Intersection i15({ 6, 17 }, { RIGHT, LEFT, UP, DOWN });
	Intersection i16({ 9, 17 }, { LEFT, UP, DOWN });
	Intersection i17({ 18, 17 }, { RIGHT, UP, DOWN });
	Intersection i18({ 21, 17 }, { RIGHT, LEFT, UP, DOWN });
	//---
	Intersection i19({ 9, 20 }, { RIGHT, UP, DOWN });
	Intersection i20({ 18, 20 }, { LEFT, UP, DOWN });
	//---
	Intersection i21({ 6, 23 }, { RIGHT, LEFT, UP, DOWN });
	Intersection i22({ 9, 23 }, { RIGHT, LEFT, UP });
	Intersection i23({ 18, 23 }, { RIGHT, LEFT, UP });
	Intersection i24({ 21, 23 }, { RIGHT, LEFT, UP, DOWN });
	//---
	Intersection i25({ 6, 26 }, { RIGHT, LEFT, UP, DOWN });
	Intersection i26({ 9, 26 }, { RIGHT, LEFT, DOWN });
	Intersection i27({ 12, 26 }, { RIGHT, LEFT, UP });
	Intersection i28({ 15, 26 }, { RIGHT, LEFT, UP });
	Intersection i29({ 18, 26 }, { RIGHT, LEFT, DOWN });
	Intersection i30({ 21, 26 }, { RIGHT, LEFT, UP, DOWN });
	//---
	Intersection i31({ 3, 29 }, { RIGHT, LEFT, UP });
	Intersection i32({ 24, 29 }, { RIGHT, LEFT, UP });
	//---
	Intersection i33({ 12, 32 }, { RIGHT, LEFT, UP });
	Intersection i34({ 15, 32 }, { RIGHT, LEFT, UP });
}
list<Directions> Intersection::Outs() {
	return outs;
}
Size_TXY Intersection::Coords() {
	return StaticObject::Coords();
}
list<Directions> Intersection::isIntersection(Size_TXY coords) {
	for (auto i : intersections) {
		if (i.Coords() == coords) {
			return i.Outs();
		}
	}
	return {};
}
void Intersection::ClearIntersections() {
	/*for (Intersection i : intersections) {
		delete& i;
	}*/
	intersections.clear();
}