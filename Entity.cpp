#include "Entity.h"
list<Entity*> Entity::entities;
bool Entity::rage = false;
Entity::Entity(Size_TXY coords, EntTypes type) : coords(coords), type(type) {
	entities.push_back(this);
}
bool Entity::move(IntXY dis) {
	coords = {coords.x+dis.x,coords.y+dis.y};
	return true;
}
Size_TXY Entity::Position() const {
	return coords;
}
EntTypes Entity::Type() const {
	return type;
}