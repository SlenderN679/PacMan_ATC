#include "Ghost_UI.h"

list<Ghost_UI*> Ghost_UI::ghosts;
Ghost_UI::Ghost_UI(Size_TXY coords, GstNames name) : Ghost(coords, name) {
	
}
void Ghost_UI::Update() {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size
	int startY = (maxY - ROWS) / 2;  // Center the map vertically
	int startX = (maxX - COLS) / 2;  // Center the map horizontally
	Size_TXY coords = Ghost::Position();
	switch (prevSpot) {
	case BIT:
		attron(COLOR_PAIR(BRANCO));
		mvaddch(startY + coords.y, startX + coords.x, (chtype)250);
		attroff(COLOR_PAIR(BRANCO));
		break;
	case BYTE:
		attron(COLOR_PAIR(AMARELO));
		mvaddch(startY + coords.y, startX + coords.x, ACS_DIAMOND);
		attroff(COLOR_PAIR(AMARELO));
		break;
	case SPACE:
		mvaddch(startY + coords.y, startX + coords.x, SPACE);
		break;
	default:
		break;
	}
	Ghost::Move();
	coords = Ghost::Position();
	Draw(coords);
}
void Ghost_UI::Draw(Size_TXY coords) {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size

	int startY = (maxY - ROWS) / 2;  // Center the map vertically
	int startX = (maxX - COLS) / 2;  // Center the map horizontally
	init_pair(AMARELO, COLOR_YELLOW, COLOR_BLACK);  // Byte,PacMan,Clyde
	init_pair(VERMELHO, COLOR_RED, COLOR_BLACK);  // Blinky
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);  // Pinky
	init_pair(CIANO, COLOR_CYAN, COLOR_BLACK);  // Inky
	if (rage) {
		attron(COLOR_PAIR(AZUL));
		mvaddch(startY + coords.y, startX + coords.x, GHOST);
		attroff(COLOR_PAIR(AZUL));
	}
	else {
		switch (getNames()) {
		case BLINKY:
			attron(COLOR_PAIR(VERMELHO));
			mvaddch(startY + coords.y, startX + coords.x, GHOST);
			attroff(COLOR_PAIR(VERMELHO));
			break;
		case PINKY:
			attron(COLOR_PAIR(MAGENTA));
			mvaddch(startY + coords.y, startX + coords.x, GHOST);
			attroff(COLOR_PAIR(MAGENTA));
			break;
		case INKY:
			attron(COLOR_PAIR(CIANO));
			mvaddch(startY + coords.y, startX + coords.x, GHOST);
			attroff(COLOR_PAIR(CIANO));
			break;
		case CLYDE:
			attron(COLOR_PAIR(AMARELO));
			mvaddch(startY + coords.y, startX + coords.x, GHOST);
			attroff(COLOR_PAIR(AMARELO));
			break;
		default:
			break;
		};
	}
}
void Ghost_UI::CreateGhosts() {
	ghosts.push_back(new Ghost_UI({ 13, 14 }, BLINKY));
	ghosts.push_back(new Ghost_UI({ 13, 17 }, PINKY));
	ghosts.push_back(new Ghost_UI({ 11, 17 }, INKY));
	ghosts.push_back(new Ghost_UI({ 15, 17 }, CLYDE));
}
Size_TXY Ghost_UI::Start() {
	return DynamicEntity::Start();
}
list<Ghost_UI*> Ghost_UI::GhostList() {
	return ghosts;
}
EntTypes Ghost_UI::Type() {
	return GHOST_E;
}
void Ghost_UI::ClearGhosts() {
	/*for (Ghost_UI* g : ghosts) {
		delete g;
	}*/
	ghosts.clear();
	Ghost::ClearGhosts();
}