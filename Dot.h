#pragma once
#include "Entity.h"
#include "list"
using namespace std;
class Dot : public Entity {
	static list<Dot> dots;
public:
	Dot(Size_TXY pos, EntTypes type);
	static bool Grid();
};