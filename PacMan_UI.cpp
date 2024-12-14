#include "PacMan_UI.h"

PacMan_UI::PacMan_UI() : PacMan() {

}
void PacMan_UI::Draw() {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size

	int startY = (maxY - 36) / 2;  // Center the map vertically
	int startX = (maxX - 28) / 2;  // Center the map horizontally
	init_pair(AMARELO, COLOR_YELLOW, COLOR_BLACK);  // Byte,PacMan,Clyde

	Size_TXY coords = Position();

	mvaddch(startY + coords.y, startX + coords.x, SPACE);

	coords = Move();

	attron(COLOR_PAIR(AMARELO));
	mvaddch(startY + coords.y, startX + coords.x, PACMAN);
	attroff(COLOR_PAIR(AMARELO));

	attron(COLOR_PAIR(CIANO));
	mvprintw(startY, startX, "Score: %d", getScore()); 
	attroff(COLOR_PAIR(CIANO));

	attron(COLOR_PAIR(VERMELHO));
	mvprintw(startY + 1, startX, "Lives: %d", getLives());
	attroff(COLOR_PAIR(VERMELHO));

	refresh();
}