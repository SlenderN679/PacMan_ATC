#include "DynamicEntity.h"
list<DynamicEntity*> DynamicEntity::entities;
bool DynamicEntity::rage = false;
Size_TXY DynamicEntity::GStart() {
	coords = { 13, 14 };
	return coords;
}
void DynamicEntity::PStart(Size_TXY c) {
	coords = c;
}
DynamicEntity::DynamicEntity(Size_TXY coords, EntTypes type) : coords(coords), type(type) {
	entities.push_back(this);
}
Size_TXY DynamicEntity::Move(IntXY dis) {
	coords = {coords.x+dis.x,coords.y+dis.y};
	return coords;
}
Size_TXY DynamicEntity::Position() const {
	return coords;
}
EntTypes DynamicEntity::Type() const {
	return type;
}
bool DynamicEntity::Rage() {
	return rage;
}
void DynamicEntity::Calm() {
	rage = false;
}
void DynamicEntity::timer(int seconds) {
	for (int i = 0; i < seconds; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}