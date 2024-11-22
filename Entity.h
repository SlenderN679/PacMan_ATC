#pragma once
#include "_Size_TXY.h"
#include <list>
enum EntTypes {BIT_E, BYTE_E, CHERRY_E, GHOST_E, PACMAN_E};

using namespace std;

class Entity {
	Size_TXY coords;
	const EntTypes type;
	static list<Entity*> entities;
protected:
	static bool rage;
public:
	Entity(Size_TXY coords, EntTypes type);
	bool move(IntXY dis);
	Size_TXY Position() const;
	EntTypes Type() const;
	/*bool ECollision(Size_TXY coords);
	bool OCollision(Size_TXY coords);*/
};