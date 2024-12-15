#pragma once
#include "Ghost.h"
#include "Drawing.h"

class Ghost_UI : public Ghost, public Drawing {
	static list<Ghost_UI*> ghosts;
public:
	Ghost_UI(Size_TXY coords, GstNames name);
	void Draw(Size_TXY coords);
	void Update();
	static void CreateGhosts();
	Size_TXY Start();
	static list<Ghost_UI*> GhostList();
};
	
