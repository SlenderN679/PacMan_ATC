#include "PacMan.h"
Size_TXY reset = { 14 , 26 };
PacMan::PacMan() : DynamicEntity(reset, PACMAN_E) {
	direction = RIGHT;
	nextDirection = RIGHT;
	lives = 3;
	score = 0;
}
Size_TXY PacMan::Move() {
	Map::addNumber(score, 0, 0);
	Map::addNumber(lives, 1, 0);
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
	if (Map::getCell(pos) == GHOST) {
		Hit();
		return pos;
	} 
	switch (Map::getCell({ pos.x + dir.x, pos.y + dir.y })) {
	case PORTAL:
		pos = DynamicEntity::Move({ 26 * (-dir.x), 0 });
		break;
	case WALL:
		direction = nextDirection;
		break;
	/*case WALL_:
		direction = nextDirection;
		break;*/
	default:
		break;
	}
	switch (CheckPos({ pos.x + dir.x, pos.y + dir.y })) {
	case BYTE_E:
		rage = true;
		pos = DynamicEntity::Move(dir);
		Dot::destroy(pos);
		break;
	case BIT_E:
		score += 1;
		pos = DynamicEntity::Move(dir);
		Dot::destroy(pos);
		break;
	case GHOST_E:
		pos = Hit();
		if (rage) {
			pos = DynamicEntity::Move(dir);
		}
		break;
	default:
		break;
	};
	return pos;
}
void PacMan::Turn(Directions direction) {
	nextDirection = direction;
}
Size_TXY PacMan::Hit() {
	if (rage) {
		score += 100;
	} else {
		lives--;
		if (lives == 0) {
			//game over
		} else {
			PStart(pacmanStart);
		}
	}
	return Position();
}
Directions PacMan::getDirection() const{
	return direction;
}
int PacMan::getLives() const{
	return lives;
}
int PacMan::getScore() const{
	return score;
}
void PacMan::UpdateStats() {
	//update stats
}


