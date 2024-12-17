#pragma once
#include "PacMan.h"
#include "Drawing.h"
class PacMan_UI : public PacMan, public Drawing {
public:
	PacMan_UI();
	void Draw(Size_TXY coords);
	void Update();
	Size_TXY Start();
};