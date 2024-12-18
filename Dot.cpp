#include "Dot.h"
list<Dot*> Dot::dots;
Dot::Dot(Size_TXY pos, EntTypes type) : DynamicEntity(pos, type) {
	dots.push_back(this);
}
bool Dot::CreateDots() {
	for (size_t y = 4; y < 33; y++) {
		for (size_t x = 1; x < 27; x++) {
            if ((Map::getCell({x,y}) == SPACE)&&((!(0 <= x && x < 5 && 12 < y && y < 16)) && (!(0 <= x && x < 5 && 18 < y && y < 22)) && (!(22 < x && x <= 27 && 12 < y && y < 16)) && (!(22 < x && x <= 27 && 18 < y && y < 22)) && (!(10 < x && x < 17 && 14 < y && y < 19)))) {
				if ((x==1||x==26)&&(y==6||y==26)) {
					Dot* dot = new Dot({ x, y }, BYTE_E);
					if (dot == nullptr) {
						return false;
					}
				}
				else {
					Dot* dot = new Dot({ x, y }, BIT_E);
					if (dot == nullptr) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
bool Dot::Destroy(Size_TXY pos) {
	for (auto it = dots.begin(); it != dots.end(); it++) {
		if ((*it)->Position() == pos) {
			DynamicEntity::RemoveEntity(*it);
			(*it)->RemoveFromDerivedList();
			dots.erase(it);
			//delete* it;
			return true;
		}
	}
	return false;
}
int Dot::DotReamining() {
	return dots.size();
}
void Dot::RemoveFromDerivedList() {
	for (auto it = dots.begin(); it != dots.end(); it++) {
		if (*it == this) {
			dots.erase(it);
			//delete* it;
			break;
		}
	}
}
bool Dot::CheckDot(Size_TXY pos) {
	for (Dot* d : dots) {
		if (d->Position() == pos) {
			return true;
		}
	}
	return false;
}
void Dot::ClearDots() {
	/*for (Dot* d : dots) {
		delete d;
	}*/
	dots.clear();
}