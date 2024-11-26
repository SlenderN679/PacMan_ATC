#include "Dot.h"
list<Dot*> Dot::dots;
Dot::Dot(Size_TXY pos, EntTypes type) : Entity(pos, type) {
	dots.push_back(this);
}
bool Dot::Grid() {
	for (size_t y = 4; y < 33; y++) {
		for (size_t x = 1; x < 27; x++) {
			if (Map::getCell({x,y}) == SPACE) {
				if ((x==1||x==26)&&(y==6||y==26)) {
					Dot* dot = new Dot({ x, y }, BYTE_E);
					Map::addByte({ x, y });
					if (dot == nullptr) {
						return false;
					}
				}
				else {
					Dot* dot = new Dot({ x, y }, BIT_E);
					Map::addBit({ x, y });
					if (dot == nullptr) {
						return false;
					}
				}
			}
		}
	}
	return true;
}