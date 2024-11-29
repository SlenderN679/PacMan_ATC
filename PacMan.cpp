#include "PacMan.h"
Size_TXY pacmanStart = { 14 , 26 };
PacMan::PacMan() : Entity(pacmanStart, PACMAN_E) {
	direction = RIGHT;
	nextDirection = RIGHT;
	lives = 3;
	score = 0;
	Map::addPacman(pacmanStart);
}
void PacMan::move() {
	Size_TXY pos = Position();
	IntXY dir = { 0,0 };
	for (Directions i : Intersection::isIntersection(pos)) {
		if (i == nextDirection) {
			direction = nextDirection;
		}
	}
	switch (direction) {
	case UP:
		dir = { 0 , -1 };
		break;
	case DOWN:
		dir = { 0 , 1 };
		break;
	case LEFT:
		dir = { -1 , 0 };
		break;
	case RIGHT:
		dir = { 1 , 0 };
		break;
	}
	switch (Map::getCell({ pos.x + dir.x, pos.y + dir.y })) {
	case BYTE:
		score += 10;
		rage = true;
		Map::clearCell(pos);
		pos = Entity::move(dir);
		Dot::destroy(pos);
		Map::clearCell(pos);
		Map::addPacman(pos);
		break;
	case BIT:
		score += 1;
		Map::clearCell(pos);
		pos = Entity::move(dir);
		Map::clearCell(pos);
		Map::addPacman(pos);
		break;
	case PORTAL:
		Map::clearCell(pos);
		pos = Entity::move({ 25 * (-dir.x), 0 });
		Map::addPacman(pos);
		break;
	case WALL:
		direction = nextDirection;
		break;
	case WALL_:
		direction = nextDirection;
		break;
	default:
		Map::clearCell(pos);
		pos = Entity::move(dir);
		Map::addPacman(pos);
	}
}
void PacMan::turn(Directions direction) {
	nextDirection = direction;
}
