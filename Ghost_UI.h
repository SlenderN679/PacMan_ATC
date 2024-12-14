#pragma once
#include "Ghost.h"
#include "Drawing.h"

class Ghost_UI : public Ghost, Drawing {
public:
	Ghost_UI(Size_TXY coords, GstNames name);
	void Draw();
};
	
