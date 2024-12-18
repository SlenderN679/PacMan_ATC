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
DynamicEntity::DynamicEntity(Size_TXY coords, EntTypes type) : coords(coords), type(type), start(coords) {
	entities.push_back(this);
}
Size_TXY DynamicEntity::Move(IntXY dis) {
	coords = {coords.x+dis.x,coords.y+dis.y};
	return coords;
}
Size_TXY DynamicEntity::Position() const {
	return coords;
}
Size_TXY DynamicEntity::Start() const {
	return start;
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
			return e->type;
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
list<DynamicEntity*> DynamicEntity::EntityList() {
	return entities;
}
void DynamicEntity::RemoveEntity(DynamicEntity* e) {
	for (auto it = entities.begin(); it != entities.end(); it++) {
		if (*it == e) {
			entities.erase(it);
			break;
		}
	}
}
void DynamicEntity::ClearEntities() {
	/*for (DynamicEntity* e : entities) {
		if (e != nullptr)
		delete e;
	}*/
	entities.clear();
}