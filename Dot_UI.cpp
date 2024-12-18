#include "Dot_UI.h"
list<Dot_UI*> Dot_UI::dots;
Dot_UI::Dot_UI(Size_TXY pos, EntTypes type) : Dot(pos, type) {
	dots.push_back(this);
}
void Dot_UI::Draw(Size_TXY coords) {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size
	int startY = (maxY - ROWS) / 2;  // Center the map vertically
	int startX = (maxX - COLS) / 2;  // Center the map horizontally
	init_pair(AMARELO, COLOR_YELLOW, COLOR_BLACK);  // Byte,PacMan,Clyde
	init_pair(CIANO, COLOR_CYAN, COLOR_BLACK);  // Inky
	init_pair(VERMELHO, COLOR_RED, COLOR_BLACK);  // Blinky
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);  // Pinky
	if(CheckDot(coords)){
		switch (Type()) {
		case BYTE_E:
			attron(COLOR_PAIR(AMARELO));
			mvaddch(startY + coords.y, startX + coords.x, ACS_DIAMOND);
			attroff(COLOR_PAIR(AMARELO));
			break;
		case BIT_E:
			attron(COLOR_PAIR(BRANCO));
			mvaddch(startY + coords.y, startX + coords.x, (chtype)250);
			attroff(COLOR_PAIR(BRANCO));
			break;
		default:
			break;
		}
	}
	attron(COLOR_PAIR(MAGENTA));
	mvprintw(startY + 1, startX, "Dots:     ");
	mvprintw(startY + 1, startX, "Dots: %d", Dot::DotReamining());
	attroff(COLOR_PAIR(MAGENTA));
}
void Dot_UI::Update() {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size
	int startY = (maxY - ROWS) / 2;  // Center the map vertically
	int startX = (maxX - COLS) / 2;  // Center the map horizontally
	Size_TXY coords = Dot::Position();
	if ((CheckPos(coords) != PACMAN_E) && (CheckPos(coords) != GHOST_E)) {
		Draw(coords);
	}
}
Size_TXY Dot_UI::Start() {
	return Dot::Start();
}
bool Dot_UI::CreateDots() {
	for (size_t y = 4; y < 33; y++) {
		for (size_t x = 1; x < 27; x++) {
			if ((Map::getCell({ x,y }) == SPACE) && ((!(0 <= x && x < 5 && 12 < y && y < 16)) && (!(0 <= x && x < 5 && 18 < y && y < 22)) && (!(22 < x && x <= 27 && 12 < y && y < 16)) && (!(22 < x && x <= 27 && 18 < y && y < 22)) && (!(10 < x && x < 17 && 14 < y && y < 19)))) {
				if ((x == 1 || x == 26) && (y == 6 || y == 26)) {
					Dot_UI* dot = new Dot_UI({ x, y }, BYTE_E);
					if (dot == nullptr) {
						return false;
					}
				}
				else {
					Dot_UI* dot = new Dot_UI({ x, y }, BIT_E);
					if (dot == nullptr) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
list<Dot_UI*> Dot_UI::DotList() {
	return dots;
}
void Dot_UI::RemoveFromDerivedList()  {
	// Ensure removal from the derived list
	dots.erase(std::remove(dots.begin(), dots.end(), this), dots.end());
}
EntTypes Dot_UI::Type() {
	return Dot::Type();
}
void Dot_UI::ClearDots() {
	/*for (Dot_UI* d : dots) {
		delete d;
	}*/
	dots.clear();
	Dot::ClearDots();
}