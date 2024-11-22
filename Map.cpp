#pragma once
#include "Map.h"
#include "iostream"
#include <cstdlib>
using namespace std;
unsigned char Map::maze[28][36];
Map::Map() {
	for (int i = 3; i < 34; i++) {
		for (int j = 0; j < 28; j++) {
			if ((j == 0 || j == 27 || i == 3 || i == 33) && j != 17) {
				maze[j][i] = WALL;
			}
			else {
				maze[j][i] = SPACE;
			}
		}
	}
}
void Map::drawMap() {
	system("cls");
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 36; j++) {
			cout << maze[i][j];
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
bool Map::clearCell(Size_TXY pos) {
	if (maze[pos.y][pos.x] != WALL) {
		maze[pos.y][pos.x] = 32;
		return true;
	}
	return false;
}
unsigned char Map::getCell(Size_TXY pos) {
	return maze[pos.y][pos.x];
}