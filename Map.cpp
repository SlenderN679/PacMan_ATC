#pragma once
#include "Map.h"
#include "iostream"
#include <cstdlib>
using namespace std;
unsigned char Map::maze[36][28];
Map::Map() {
	for (int y = 0; y < 36; y++) {
		for (int x = 0; x < 28; x++) {
			if ((x == 0 || x == 27 || y == 3 || y == 33) && (y > 2 && y < 34) && !(y >= 13 && y <= 21)) {
				maze[y][x] = WALL;
			}
			else {
				maze[y][x] = SPACE;
			}
		}
	}
}
void Map::drawMap() {
	system("cls");
	for (int y = 0; y < 36; y++) {
		for (int x = 0; x < 28; x++) {
			if (maze[y][x] == WALL && Entity::Rage()) {
				cout << (char)WALL_;
			}
			else {
				cout << maze[y][x];
			}
				
		}
		cout << endl;
	}
}
bool Map::addPacman(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = PACMAN;
		return true;
	}
	return false;
}
bool Map::addGhost(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = GHOST;
		return true;
	}
	return false;
}
bool Map::addWall(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = WALL;
		return true;
	}
	return false;
}
bool Map::addByte(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = BYTE;
		return true;
	}
	return false;
}
bool Map::addBit(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = BIT;
		return true;
	}
	return false;
}
bool Map::addPortal(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = PORTAL;
		return true;
	}
	return false;
}
bool Map::addInter(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = INTER;
		return true;
	}
	return false;
}
bool Map::clearCell(Size_TXY pos) {
	if (maze[pos.y][pos.x] != WALL) {
		maze[pos.y][pos.x] = SPACE;
		return true;
	}
	return false;
}
unsigned char Map::getCell(Size_TXY pos) {
	return maze[pos.y][pos.x];
}