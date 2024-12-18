#include "Wall.h"
list<Wall*> Wall::walls;
Wall::Wall(size_t width, size_t height, Size_TXY coords) : StaticObject(coords, WALL_O), height(height), width(width){
	for (size_t x = coords.x; x < coords.x + width; x++) {
		for (size_t y = coords.y; y < coords.y + height; y++) {
			Map::addWall({x,y});
		}
	}
}
Wall::Wall(Size_TXY coords) : StaticObject(coords, WALL_O), height(1), width(1) {
}
void Wall::CreateWalls() {
	walls.push_back(new Wall(4, 3, { 2,5 }));
	walls.push_back(new Wall(5, 3, { 7,5 }));
	walls.push_back(new Wall(2, 4, { 13,4 }));
	walls.push_back(new Wall(5, 3, { 16,5 }));
	walls.push_back(new Wall(4, 3, { 22,5 }));
	//---
	walls.push_back(new Wall(4, 2, { 2,9 }));
	walls.push_back(new Wall(2, 8, { 7,9 }));
	walls.push_back(new Wall(8, 2, { 10,9 }));
	walls.push_back(new Wall(2, 8, { 19,9 }));
	walls.push_back(new Wall(4, 2, { 22,9 }));
	//---
	walls.push_back(new Wall(5, 1, { 1,12 }));
	walls.push_back(new Wall(3, 2, { 9,12 }));
	walls.push_back(new Wall(2, 3, { 13,11 }));
	walls.push_back(new Wall(3, 2, { 16,12 }));
	walls.push_back(new Wall(5, 1, { 22,12 }));
	//---
	walls.push_back(new Wall(1, 3, { 5,13 }));
	walls.push_back(new Wall(3, 1, { 10,15 }));
	walls.push_back(new Wall(3, 1, { 15,15 }));
	walls.push_back(new Wall(1, 3, { 22,13 }));
	//---
	walls.push_back(new Wall(6, 1, { 0,16 }));
	walls.push_back(new Wall(1, 3, { 10,16 }));
	walls.push_back(new Wall(1, 3, { 17,16 }));
	walls.push_back(new Wall(6, 1, { 22,16 }));
	//---
	walls.push_back(new Wall(6, 1, { 0,18 }));
	walls.push_back(new Wall(2, 5, { 7,18 }));
	walls.push_back(new Wall(8, 1, { 10,19 }));
	walls.push_back(new Wall(2, 5, { 19,18 }));
	walls.push_back(new Wall(6, 1, { 22,18 }));
	//---
	walls.push_back(new Wall(1, 3, { 5,19 }));
	walls.push_back(new Wall(8, 2, { 10,21 }));
	walls.push_back(new Wall(1, 3, { 22,19 }));
	//---
	walls.push_back(new Wall(5, 1, { 1,22 }));
	walls.push_back(new Wall(5, 1, { 22,22 }));
	//---
	walls.push_back(new Wall(4, 2, { 2,24 }));
	walls.push_back(new Wall(5, 2, { 7,24 }));
	walls.push_back(new Wall(2, 3, { 13,23 }));
	walls.push_back(new Wall(5, 2, { 16,24 }));
	walls.push_back(new Wall(4, 2, { 22,24 }));
	//---
	walls.push_back(new Wall(2, 2, { 1,27 }));
	walls.push_back(new Wall(2, 3, { 4,26 }));
	walls.push_back(new Wall(2, 3, { 7,27 }));
	walls.push_back(new Wall(8, 2, { 10,27 }));
	walls.push_back(new Wall(2, 3, { 19,27 }));
	walls.push_back(new Wall(2, 3, { 22,26 }));
	walls.push_back(new Wall(2, 2, { 25,27 }));
	//---
	walls.push_back(new Wall(10, 2, { 2,30 }));
	walls.push_back(new Wall(2, 3, { 13,29 }));
	walls.push_back(new Wall(10, 2, { 16,30 }));
}
void Wall::CreateWall(Size_TXY coords) {
	walls.push_back(new Wall(coords));
} 
void Wall::ClearWalls() {
	/*for (Wall* w : walls) {
		delete w;
	}*/
	walls.clear();
}