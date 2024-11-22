#include "Object.h"
list<Object*> Object::objects;
Object::Object(float width, float height, Size_TXY coords, ObjTypes type) : width(width), height(height), coords(coords), type(type) {
	objects.push_back(this);
}
Size_TXY Object::getCoords() {
	return coords;
}
ObjTypes Object::getType() {
	return type;
}