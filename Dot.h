#pragma once
#include "DynamicEntity.h"
#include "Map.h"
#include "list"
using namespace std;
class Dot : public DynamicEntity {
	static list<Dot*> dots;
public:
	Dot(Size_TXY pos, EntTypes type);
	static bool CreateDots();
	static bool destroy(Size_TXY pos);
	static void CreateBit(Size_TXY pos);
	static void CreateByte(Size_TXY pos);
	static int DotReamining();
};