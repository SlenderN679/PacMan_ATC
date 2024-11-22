#include "Dot.h"
list<Dot> Dot::dots;
Dot::Dot(Size_TXY pos, EntTypes type) : Entity(pos, type) {
	dots.push_back(*this);
}
bool Dot::Grid() {
	return true;
}