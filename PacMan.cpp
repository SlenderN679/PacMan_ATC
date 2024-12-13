#include "PacMan.h"
Size_TXY pacmanStart = { 14 , 26 };
PacMan::PacMan() : DynamicEntity(pacmanStart, PACMAN_E) {
	direction = RIGHT;
	nextDirection = RIGHT;
	lives = 3;
	score = 0;
	Map::addPacman(pacmanStart);
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
	//case BYTE:
	//	score += 10;
	//	rage = true;
	//	Map::clearCell(pos);
	//	pos = DynamicEntity::Move(dir);
	//	Dot::destroy(pos);
	//	Map::clearCell(pos);
	//	Map::addPacman(pos);
	//	break;
	//case BIT:
	//	score += 1;
	//	/*Map::moveEntity(pos, DynamicEntity::Move(dir), PACMAN, SPACE);*/
	//	Map::clearCell(pos);
	//	pos = DynamicEntity::Move(dir);
	//	Map::clearCell(pos);
	//	Map::addPacman(pos);
	//	break;
	case PORTAL:
		Map::clearCell(pos);
		pos = DynamicEntity::Move({ 25 * (-dir.x), 0 });
		Map::addPacman(pos);
		break;
	case WALL:
		direction = nextDirection;
		break;
	case WALL_:
		direction = nextDirection;
		break;
	/*case GHOST:
		Hit();
		if (rage) {
			Map::clearCell(pos);
			pos = DynamicEntity::Move(dir);
			Map::clearCell(pos);
			Map::addPacman(pos);
		}
		break;*/
	default:
		break;
	}
	return pos;
}
void PacMan::Turn(Directions direction) {
	nextDirection = direction;
}
void PacMan::Hit() {
	if (rage) {
		score += 100;
	} else {
		lives--;
		if (lives == 0) {
			//game over
		} else {
		 	Map::clearCell(Position());
			PStart(pacmanStart);
			Map::addPacman(Position());
		}
	}
	
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

