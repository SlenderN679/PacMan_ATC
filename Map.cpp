#pragma once
#include "Map.h"
#include "iostream"
#include <cstdlib>
#include <fstream>
#include <string>
#include <curses.h>

#define BRANCO 0
#define AZUL 1
#define AMARELO 2
#define VERDE 3
#define VERMELHO 4
#define MAGENTA 5
#define CIANO 6
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
void Map::drawMap() {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size

	int startY = (maxY - 36) / 2;  // Center the map vertically
	int startX = (maxX - 28) / 2;  // Center the map horizontally
	init_pair(AZUL, COLOR_BLUE, COLOR_BLACK);  // Wall
	init_pair(AMARELO, COLOR_YELLOW, COLOR_BLACK);  // Byte,PacMan,Clyde
	init_pair(VERDE, COLOR_GREEN, COLOR_BLACK);  // Portal
	init_pair(VERMELHO, COLOR_RED, COLOR_BLACK);  // Blinky
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);  // Pinky
	init_pair(CIANO, COLOR_CYAN, COLOR_BLACK);  // Inky
	init_pair(BRANCO, COLOR_WHITE, COLOR_BLACK);  // Bit
	//--
	for (size_t y = 0; y < 36; ++y) {
		for (size_t x = 0; x < 28; ++x) {
			if (DynamicEntity::Rage()) {
				if (y > 1) {
					switch (maze[y][x]) {
					case WALL:
						attron(COLOR_PAIR(BRANCO));
						mvaddch(startY + y, startX + x, WALL_);
						attroff(COLOR_PAIR(BRANCO));
						break;
					case BYTE:
						attron(COLOR_PAIR(AMARELO));
						mvaddch(startY + y, startX + x, ACS_DIAMOND);
						attroff(COLOR_PAIR(AMARELO));
						break;
					case BIT:
						attron(COLOR_PAIR(BRANCO));
						mvaddch(startY + y, startX + x, (chtype)250);
						attroff(COLOR_PAIR(BRANCO));
						break;
					/*case PACMAN:
						attron(COLOR_PAIR(2));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(2));
						break;*/
					case GHOST:
						attron(COLOR_PAIR(AZUL));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(AZUL));
						break;
					case PORTAL:
						attron(COLOR_PAIR(VERDE));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(VERDE));
						break;
					default:
						attron(COLOR_PAIR(BRANCO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(BRANCO));
						break;
					};
				} else {
					switch (y) {
					case 0:
						attron(COLOR_PAIR(CIANO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(CIANO));
						break;
					case 1:
						attron(COLOR_PAIR(VERMELHO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(VERMELHO));
						break;
					default:
						attron(COLOR_PAIR(BRANCO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(BRANCO));
						break;
					};
				}
			} else {
				if (y > 1) {
					switch (maze[y][x]) {
					case WALL:
						attron(COLOR_PAIR(AZUL));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(AZUL));
						break;
					case BYTE:
						attron(COLOR_PAIR(AMARELO));
						mvaddch(startY + y, startX + x, ACS_DIAMOND);
						attroff(COLOR_PAIR(AMARELO));
						break;
					case BIT:
						attron(COLOR_PAIR(BRANCO));
						mvaddch(startY + y, startX + x, (chtype)250);
						attroff(COLOR_PAIR(BRANCO));
						break;
					/*case PACMAN:
						attron(COLOR_PAIR(2));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(2));
						break;*/
					case GHOST:
						switch (Ghost::getNames({ x,y })) {
						case BLINKY:
							attron(COLOR_PAIR(VERMELHO));
							mvaddch(startY + y, startX + x, maze[y][x]);
							attroff(COLOR_PAIR(VERMELHO));
							break;
						case PINKY:
							attron(COLOR_PAIR(MAGENTA));
							mvaddch(startY + y, startX + x, maze[y][x]);
							attroff(COLOR_PAIR(MAGENTA));
							break;
						case INKY:
							attron(COLOR_PAIR(CIANO));
							mvaddch(startY + y, startX + x, maze[y][x]);
							attroff(COLOR_PAIR(CIANO));
							break;
						case CLYDE:
							attron(COLOR_PAIR(AMARELO));
							mvaddch(startY + y, startX + x, maze[y][x]);
							attroff(COLOR_PAIR(AMARELO));
							break;
						default:
							attron(COLOR_PAIR(BRANCO));
							mvaddch(startY + y, startX + x, maze[y][x]);
							attroff(COLOR_PAIR(BRANCO));
							break;
						}
						break;
					case PORTAL:
						attron(COLOR_PAIR(VERDE));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(VERDE));
						break;
					default:
						attron(COLOR_PAIR(BRANCO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(BRANCO));
						break;
					}
				} else {
					switch (y){
					case 0:
						attron(COLOR_PAIR(CIANO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(CIANO));
						break;
					case 1:
						attron(COLOR_PAIR(VERMELHO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(VERMELHO));
						break;
					default:
						attron(COLOR_PAIR(BRANCO));
						mvaddch(startY + y, startX + x, maze[y][x]);
						attroff(COLOR_PAIR(BRANCO));
						break;
					};
				}
			}
		}
	};
	refresh();
}
//	/*system("cls");
//	maze[1][1] = (p.getLives()+48);
//	for (size_t y = 0; y < 36; y++) {
//		for (size_t x = 0; x < 28; x++) {
//			if (maze[y][x] == WALL && DynamicEntity::Rage()) {
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
//void Map::moveEntity(Size_TXY pos, Size_TXY prev, unsigned char c, unsigned char p) {
//	mvaddch(prev.x, prev.y, p);
//	mvaddch(pos.x, pos.y, c);
//}
void Map::addNumber(int number, int startY, int startX) {
	std::string numberStr = std::to_string(number);
	for (size_t i = 0; i < numberStr.length(); ++i) {
		if (startX + i < 28) { 
			maze[startY][startX + i] = numberStr[i];
		}
	}
}