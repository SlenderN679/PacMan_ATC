#pragma once
#include "Map.h"
#include "iostream"
#include <cstdlib>
#include <fstream>
using namespace std;
unsigned char Map::maze[36][28] = {};
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
	//readMap();
}
void Map::drawMap(const PacMan& p) {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size

	int startY = (maxY - 36) / 2;  // Center the map vertically
	int startX = (maxX - 28) / 2;  // Center the map horizontally

	for (int y = 0; y < 36; ++y) {
		for (int x = 0; x < 28; ++x) {
			if (maze[y][x] == WALL && Entity::Rage()) {
				mvaddch(startY + y, startX + x, WALL_);
			}
			else {
				mvaddch(startY + y, startX + x, maze[y][x]);
			}
			//mvaddch(startY + y, startX + x, maze[y][x]);
		}
	}
	refresh();
}
//	for (int y = 0; y < 36; ++y) {
//		for (int x = 0; x < 28; ++x) {
//			mvaddch(y, x, maze[y][x]); 
//		}
//
//	}
//	refresh();
//	/*system("cls");
//	maze[1][1] = (p.getLives()+48);
//	for (size_t y = 0; y < 36; y++) {
//		for (size_t x = 0; x < 28; x++) {
//			if (maze[y][x] == WALL && Entity::Rage()) {
//				cout << (char)WALL_;
//			}
//			else {
//				cout << maze[y][x];
//			}
//				
//		}
//		cout << endl;
//	}*/
//}
bool Map::add(Size_TXY pos, unsigned char type) {
	maze[pos.y][pos.x] = type;
	switch (type){
	case WALL:
		Wall::CreateWall(pos);
	case BYTE:
		Dot::CreateByte(pos);
	case BIT:
		Dot::CreateBit(pos);
	default:
		break;
	}
	return true;
}
bool Map::addPacman(Size_TXY pos) {
	if (maze[pos.y][pos.x] == SPACE) {
		maze[pos.y][pos.x] = PACMAN;
		return true;
	}
	return false;
}
bool Map::addGhost(Size_TXY pos) {
	if ((maze[pos.y][pos.x] == SPACE)|| (maze[pos.y][pos.x] == BIT)) {
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
//bool Map::addInter(Size_TXY pos) {
//	if (maze[pos.y][pos.x] == SPACE) {
//		maze[pos.y][pos.x] = INTER;
//		return true;
//	}
//	return false;
//}
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
void Map::readMap() {
    std::ifstream file("mapa.txt");
	unsigned char c;
    if (!file) {
        std::cout << "Error opening file" << std::endl;
    } else {
        for (size_t y = 0; y < 36; y++) {
            for (size_t x = 0; x < 28; x++) {
                file >> c;
                add({ x, y }, c);
            }
            //file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
	/*std::ifstream file("mapa.txt");
	unsigned char c;
	if (!file) {
		std::cout << "Error opening file" << std::endl;
	}
	else {
		for (size_t y = 0; y < 36; y++) {
			do {
				size_t x = 0;
				file >> c;
				add({ x, y }, c);
				x++;
			} while (c != '\n');
		}
	}*/
}
	//unsigned char c;
	//file.open("mapa.txt");
	////fopen_s(&file, "map.txt", "r");
	//if (file == NULL) {
	//	cout << "Error opening file" << endl;
	//}
	//else {
	//	for (size_t y = 0; y < 36; y++) {
	//		for (size_t x = 0; x < 28; x++) {

	//			c = fgetc(file);
	//			add({ x, y }, c);
	//		}
	//		fgetc(file);
	//	}
	//}
	//fclose(file);
//}
void Map::moveEntity(Size_TXY pos, Size_TXY prev, unsigned char c, unsigned char p) {
	mvaddch(prev.x, prev.y, p);
	mvaddch(pos.x, pos.y, c);
}