#include "StaticObject.h"
list<StaticObject*> StaticObject::objects;
StaticObject::StaticObject(size_t width, size_t height, Size_TXY coords, ObjTypes type) : width(width), height(height), coords(coords), type(type) {
	objects.push_back(this);
}
Size_TXY StaticObject::getCoords() {
	return coords;
}
ObjTypes StaticObject::getType() {
	return type;
}