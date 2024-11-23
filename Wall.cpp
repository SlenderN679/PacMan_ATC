#include "Wall.h"
list<Wall> Wall::walls;
Wall::Wall(size_t width, size_t height, Size_TXY coords) : Object(width, height, coords, WALL_O) {
	walls.push_back(*this);
	for (size_t x = coords.x; x < coords.x + width; x++) {
		for (size_t y = coords.y; y < coords.y + height; y++) {
			Map::addWall({x,y});
		}
	}
}