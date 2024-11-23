#include "Object.h"
list<Object*> Object::objects;
Object::Object(size_t width, size_t height, Size_TXY coords, ObjTypes type) : width(width), height(height), coords(coords), type(type) {
	objects.push_back(this);
}
Size_TXY Object::getCoords() {
	return coords;
}
ObjTypes Object::getType() {
	return type;
}