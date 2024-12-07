#include "Entity.h"
list<Entity*> Entity::entities;
bool Entity::rage = false;
Size_TXY Entity::GStart() {
	coords = { 13, 14 };
	return coords;
}
void Entity::PStart(Size_TXY c) {
	coords = c;
}
Entity::Entity(Size_TXY coords, EntTypes type) : coords(coords), type(type) {
	entities.push_back(this);
}
Size_TXY Entity::move(IntXY dis) {
	coords = {coords.x+dis.x,coords.y+dis.y};
	return coords;
}
Size_TXY Entity::Position() const {
	return coords;
}
EntTypes Entity::Type() const {
	return type;
}
bool Entity::Rage() {
	return rage;
}
void Entity::Calm() {
	rage = false;
}
void Entity::timer(int seconds) {
	for (int i = 0; i < seconds; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}