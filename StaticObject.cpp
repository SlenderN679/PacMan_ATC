#include "StaticObject.h"
list<StaticObject*> StaticObject::objects;
StaticObject::StaticObject(Size_TXY coords, ObjTypes type) : coords(coords), type(type) {
	objects.push_back(this);
}
Size_TXY StaticObject::Coords() {
	return coords;
}
ObjTypes StaticObject::Type() {
	return type;
}
void StaticObject::ClearObjects() {
	/*for (StaticObject* o : objects) {
		if (o != nullptr)
		delete o;
	}*/
	objects.clear();
}