#pragma once
#include "PacMan.h"
#include "Drawing.h"
class PacMan_UI : public PacMan, Drawing {
public:
	PacMan_UI();
	void Draw();
};