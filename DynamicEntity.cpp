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
EntTypes DynamicEntity::CheckPos(Size_TXY coords) {
	for (DynamicEntity* e : entities) {
		if (e->Position() == coords) {
			return e->Type();
		}
	}
	return XX;
}
void DynamicEntity::rage_timer(int seconds) {
	
}
void DynamicEntity::StartRage() {
	std::thread rageThread(&DynamicEntity::rage_timer, this, 15);
	rageThread.detach();
}