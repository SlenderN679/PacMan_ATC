#include "PacMan_UI.h"

PacMan_UI::PacMan_UI() : PacMan() {

}
void PacMan_UI::Draw() {
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);  // Get the current window size

	int startY = (maxY - 36) / 2;  // Center the map vertically
	int startX = (maxX - 28) / 2;  // Center the map horizontally
	Size_TXY coords = Position();
	mvaddch(startY + coords.y, startX + coords.x, SPACE);
	coords = Move();
	mvaddch(startY + coords.y, startX + coords.x, PACMAN);
}