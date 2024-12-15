#pragma once
#include "Dot.h"
#include "Drawing.h"

class Dot_UI : public Dot, public Drawing {
	static list<Dot_UI*> dots;
public:
	Dot_UI(Size_TXY pos, EntTypes type);
	void Draw(Size_TXY coords);
	void Update();
	static bool CreateDots();
	Size_TXY Start();
	static list<Dot_UI*> DotList();
	void removeFromDerivedList() override;
};