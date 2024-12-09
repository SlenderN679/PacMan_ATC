#include "Ghost.h"
#include "Map.h"
#include "Intersection.h"
#include "PacMan.h"
#include "Wall.h"
#include <chrono>
#include <thread>
using namespace std;
list<Ghost*> Ghost::ghosts;
Ghost::Ghost(Size_TXY coords, GstNames name) : Entity(coords, GHOST_E), name(name) {
	direction = RIGHT;
	prevSpot = BIT;
	wallCount = 0;
	attack = false;
	inHome = true;
	//ghosts.push_back(this);
	Map::addGhost(coords);
	switch (name){
	case BLINKY:
		scatter = { 25, 0 };
		break;
	case PINKY:
		scatter = { 2, 0 };
		break;
	case INKY:
		scatter = { 27, 35 };
		break;
	case CLYDE:
		scatter = { 0, 35 };
		break;
	default:
		scatter = { 0, 0 };
		break;
	}
	std::thread scatterThread(&Ghost::scatter_timer, this, 30);
	scatterThread.detach();
}
void Ghost::move(PacMan& p) {
	if (!inHome) {
		Roam(p);
	} else {
		Home();
	}
}
void Ghost::Roam(PacMan& p) {
	Size_TXY pos = Entity::Position();
	Size_TXY pacPos = p.Position();
	Directions pacDir = p.getDirection();
	IntXY dir = { 0,0 };
	Directions nextDir = direction;
	//---
	if (attack) {
		switch (name) {
		case BLINKY:
			target = pacPos;
			break;
		case PINKY:
			switch (pacDir) {
			case UP:
				target = { pacPos.x, pacPos.y + 4 };
				break;
			case DOWN:
				target = { pacPos.x, pacPos.y - 4 };
				break;
			case LEFT:
				target = { pacPos.x - 4, pacPos.y };
				break;
			case RIGHT:
				target = { pacPos.x + 4, pacPos.y };
				break;
			default:
				target = { pacPos.x, pacPos.y };
				break;
			}
			break;
		case INKY:
			switch (pacDir) {
			case UP:
				target = { pacPos.x, pacPos.y + 2 };
				break;
			case DOWN:
				target = { pacPos.x, pacPos.y - 2 };
				break;
			case LEFT:
				target = { pacPos.x - 2, pacPos.y };
				break;
			case RIGHT:
				target = { pacPos.x + 2, pacPos.y };
				break;
			default:
				target = { pacPos.x, pacPos.y };
				break;
			}
			break;
		case CLYDE:
			if (abs((int)(pos.x - pacPos.x)) + abs((int)(pos.y - pacPos.y)) > 8) {
				target = pacPos;
			}
			else {
				target = scatter;
			}
			break;
		}
	} else {
		target = scatter;
	}
	if (rage) {
		target = scatter;
	}
	for (Directions i : Intersection::isIntersection(pos)) {
		bool choice = false;
		while (!choice) {
			if (pos == target) {
				choice = true;
				return;
			}
			switch (direction) {
			case UP:
				if (pos.x < target.x) {
					nextDir = RIGHT;
					choice = true;
				}
				else if (pos.x > target.x) {
					nextDir = LEFT;
					choice = true;
				}/*else if(pos.y > target.y) {
					nextDir = UP;
					choice = true;
				}*/else if (pos.x == target.x) {
					nextDir = UP;
					choice = true;
				}
				break;
			case DOWN:
				/*if (pos.y < target.y) {
					nextDir = DOWN;
					choice = true;
				} else*/
				if (pos.x > target.x) {
					nextDir = LEFT;
					choice = true;
				}
				else if (pos.x <= target.x) {
					nextDir = RIGHT;
					choice = true;
				}
				else if (pos.x == target.x) {
					nextDir = DOWN;
					choice = true;
				}
				break;
			case LEFT:
				/*if (pos.x > target.x) {
					nextDir = LEFT;
					choice = true;
				} else*/
				if (pos.y <= target.y) {
					nextDir = DOWN;
					choice = true;
				}
				else if (pos.y > target.y) {
					nextDir = UP;
					choice = true;
				}
				else if (pos.y == target.y) {
					nextDir = LEFT;
					choice = true;
				}
				break;
			case RIGHT:
				if (pos.y > target.y) {
					nextDir = UP;
					choice = true;
				} else
				if (pos.y < target.y) {
					nextDir = DOWN;
					choice = true;
				}/* else if (pos.x < target.x) {
					nextDir = RIGHT;
					choice = true;
				}*/
				else if (pos.y == target.y) {
					nextDir = RIGHT;
					choice = true;
				}
				break;
			default:
				break;
			}
		}
		if (i == nextDir) {
			direction = nextDir;
		}
	};
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
	unsigned char currSpot = Map::getCell({ pos.x + dir.x, pos.y + dir.y });
	switch (currSpot) {
	case BYTE:
		wallCount = 0;
		Map::clearCell(pos);
		Map::add(pos, prevSpot);
		prevSpot = BYTE;
		pos = Entity::move(dir);
		Map::clearCell(pos);
		Map::addGhost(pos);
		break;
	case BIT:
		wallCount = 0;
		Map::clearCell(pos);
		Map::add(pos, prevSpot);
		prevSpot = BIT;
		pos = Entity::move(dir);
		Map::clearCell(pos);
		Map::addGhost(pos);
		break;
	case PORTAL:
		wallCount = 0;
		Map::clearCell(pos);
		Map::add(pos, prevSpot);
		prevSpot = Map::getCell({ pos.x + (25 * (-dir.x)), pos.y });
		pos = Entity::move({ 25 * (-dir.x), 0 });
		Map::addGhost(pos);
		break;
	case GHOST:
		wallCount = 0;
		switch (direction)
		{
		case UP:
			direction = DOWN;
			break;
		case DOWN:
			direction = UP;
			break;
		case LEFT:
			direction = RIGHT;
			break;
		case RIGHT:
			direction = LEFT;
			break;
		default:
			break;
		}
	case WALL:
		wallCount++;
		switch (direction)
		{
		case UP:
			if ((pos.x <= target.x) && ((Map::getCell({ pos.x + 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x + 1, pos.y }) != (WALL_)))) {
				direction = RIGHT;
			}
			else if ((pos.x > target.x) && ((Map::getCell({ pos.x - 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x - 1, pos.y }) != (WALL_)))) {
				direction = LEFT;
			}
			else {
				direction = DOWN;
			}
			break;
		case DOWN:
			if ((pos.x <= target.x) && ((Map::getCell({ pos.x + 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x + 1, pos.y }) != (WALL_)))) {
				direction = RIGHT;
			} else if ((pos.x > target.x) && ((Map::getCell({ pos.x - 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x - 1, pos.y }) != (WALL_)))) {
				direction = LEFT;
			} else {
				direction = UP;
			}
			break;
		case LEFT:
			if ((pos.y <= target.y) && ((Map::getCell({ pos.x , pos.y + 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y + 1 }) != (WALL_)))) {
				direction = DOWN;
			} else if ((pos.y > target.y) && ((Map::getCell({ pos.x , pos.y - 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y - 1 }) != (WALL_)))) {
				direction = UP;
			} else {
				direction = RIGHT;
			}
			break;
		case RIGHT:
			if ((pos.y <= target.y) && ((Map::getCell({ pos.x , pos.y + 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y + 1 }) != (WALL_)))) {
				direction = DOWN;
			} else if ((pos.y > target.y) && ((Map::getCell({ pos.x , pos.y - 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y - 1 }) != (WALL_)))) {
				direction = UP;
			} else {
				direction = LEFT;
			}
			break;
		default:
			break;
		}
		break;
	case WALL_:
		wallCount++;
		switch (direction)
		{
		case UP:
			if ((pos.x <= target.x) && ((Map::getCell({ pos.x + 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x + 1, pos.y }) != (WALL_)))) {
				direction = RIGHT;
			}
			else if ((pos.x > target.x) && ((Map::getCell({ pos.x - 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x - 1, pos.y }) != (WALL_)))) {
				direction = LEFT;
			}
			else {
				direction = DOWN;
			}
			break;
		case DOWN:
			if ((pos.x <= target.x) && ((Map::getCell({ pos.x + 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x + 1, pos.y }) != (WALL_)))) {
				direction = RIGHT;
			}
			else if ((pos.x > target.x) && ((Map::getCell({ pos.x - 1, pos.y }) != (WALL)) || (Map::getCell({ pos.x - 1, pos.y }) != (WALL_)))) {
				direction = LEFT;
			}
			else {
				direction = UP;
			}
			break;
		case LEFT:
			if ((pos.y <= target.y) && ((Map::getCell({ pos.x , pos.y + 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y + 1 }) != (WALL_)))) {
				direction = DOWN;
			}
			else if ((pos.y > target.y) && ((Map::getCell({ pos.x , pos.y - 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y - 1 }) != (WALL_)))) {
				direction = UP;
			}
			else {
				direction = RIGHT;
			}
			break;
		case RIGHT:
			if ((pos.y <= target.y) && ((Map::getCell({ pos.x , pos.y + 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y + 1 }) != (WALL_)))) {
				direction = DOWN;
			}
			else if ((pos.y > target.y) && ((Map::getCell({ pos.x , pos.y + 1 }) != (WALL)) || (Map::getCell({ pos.x , pos.y + 1 }) != (WALL_)))) {
				direction = UP;
			}
			else {
				direction = LEFT;
			}
			break;
		default:
			break;
		}
		break;
	case PACMAN:
		wallCount = 0;
		p.hit();
		if (rage) {
			Map::clearCell(pos);
			pos = GStart();
			Map::addGhost(pos);
		}
		else {
			Map::clearCell(pos);
			Map::add(pos, prevSpot);
			prevSpot = SPACE;
			pos = Entity::move(dir);
			Map::clearCell(pos);
			Map::addGhost(pos);
		}
	default:
		wallCount = 0;
		//unsigned char a = SPACE;
		Map::clearCell(pos);
		Map::add(pos, prevSpot);
		prevSpot = SPACE;
		pos = Entity::move(dir);
		Map::clearCell(pos);
		Map::addGhost(pos);
		break;
	}
	if (wallCount >= 3) {
		switch (direction)
		{
		case UP:
			direction = DOWN;
			break;
		case DOWN:
			direction = UP;
			break;
		case LEFT:
			direction = RIGHT;
			break;
		case RIGHT:
			direction = LEFT;
			break;
		default:
			break;
		}
	}
}
Directions Ghost::getDirection() const {
	return direction;
}
GstNames Ghost::getNames() {
	return name;
}
void Ghost::Home() {
	Size_TXY pos = Entity::Position();
	switch (direction)
	{
	case LEFT:
		Map::clearCell(pos);
		pos = Entity::move({ -1,0 });
		Map::clearCell(pos);
		Map::addGhost(pos);
		direction = RIGHT;
		break;
	case RIGHT:
		Map::clearCell(pos);
		pos = Entity::move({ 1,0 });
		Map::clearCell(pos);
		Map::addGhost(pos);
		direction = LEFT;
		break;
	default:
		direction = RIGHT;
		break;
	}
}
void Ghost::CreateGhosts() {
	ghosts.push_back(new Ghost({ 13, 14 }, BLINKY));
	ghosts.push_back(new Ghost({ 13, 17 }, PINKY));
	ghosts.push_back(new Ghost({ 11, 17 }, INKY));
	ghosts.push_back(new Ghost({ 15, 17 }, CLYDE));

	/*Ghost blinky({ 13, 14 }, BLINKY);
	Ghost pinky({ 13, 17 }, PINKY);
	Ghost inky({ 11, 17 }, INKY);
	Ghost clyde({ 15, 17 }, CLYDE);*/
}
void Ghost::MoveGhosts(PacMan& p) {
	for (Ghost* g : ghosts) {
		g->move(p);
	}
}
void Ghost::scatter_timer(int seconds) {
	while (true) {
		if (!attack) {
			for (int i = 0; i < seconds; i++) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			attack=true;
		}
		if (attack) {
			for (int i = 0; i < (seconds/2); i++) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			attack = false;
		}
	}
}
void Ghost::start_timer(int seconds) {
	for (int i = 0; i < seconds; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	attack = true;
	inHome = false;
	GStart();
}
void Ghost::Start() {
	int x = 0;
	for (Ghost* g : ghosts) {
		//std::thread scatterThread(&Ghost::start_timer, g, x);
		//g->start_timer(x);
		for (int i = 0; i < x; i++) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		g->attack = true;
		g->inHome = false;
		Map::clearCell(g->Position());
		g->GStart();
		x = 30;
	}
}
GstNames Ghost::getNames(Size_TXY pos) {
	for (Ghost* g : ghosts) {
		if (g->Position() == pos) {
			return g->name;
		}
	}
	return X;
}
