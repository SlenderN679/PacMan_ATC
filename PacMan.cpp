#include "PacMan.h"
Size_TXY pacmanStart = { 26 , 14 };
PacMan::PacMan() : Entity(pacmanStart, PACMAN_E) {
	direction = RIGHT;
	lives = 3;
	score = 0;
	Map::addPacman(pacmanStart);
}
void PacMan::move() {
	switch (direction) {
	case UP:
		if (Map::getCell({ Position().x, Position().y - 1 }) != WALL) {
			Map::clearCell(Position());
			Entity::move({ 0 , -1 });
			Map::addPacman(Position());
		}
		break;
	case DOWN:
		if (Map::getCell({ Position().x, Position().y + 1 }) != WALL) {
			Map::clearCell(Position());
			Entity::move({ 0 , 1 });
			Map::addPacman(Position());
		}
		break;
	case LEFT:
		if (Map::getCell({ Position().x - 1, Position().y }) != WALL) {
			Map::clearCell(Position());
			Entity::move({ -1, 0 });
			Map::addPacman(Position());
		} else if (Map::getCell({ Position().x - 1, Position().y }) == PORTAL) {
			Map::clearCell(Position());
			Entity::move({ 25 , 0 });
			Map::addPacman(Position());
		}
		break;
	case RIGHT:
		if (Map::getCell({Position().x + 1, Position().y}) != WALL) {
			Map::clearCell(Position());
			Entity::move({ 1 , 0 });
			Map::addPacman(Position());
		} else if (Map::getCell({Position().x + 1, Position().y}) == PORTAL) {
			Map::clearCell(Position());
			Entity::move({ -25 , 0 });
			Map::addPacman(Position());
		}
		break;
	}
}
void PacMan::turn(Directions direction) {
	this->direction = direction;
}
		//Map::getCell returned - 78 	char
