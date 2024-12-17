#pragma once
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>
#include <curses.h>
#include "Map.h"
#include "PacMan_UI.h"
#include "Ghost_UI.h"
#include "Dot_UI.h"
#include "Wall.h"
#include "Intersection.h"
#include "Menu.h"

class Game {
private:
	int difficulty;
	int score;
	int levels_completed;
	//---
	void draw_menu(const char* tittle, const char* options[], int num_options, int highlight);
	void menu();
	void settings();
	void show_controls();
	void set_difficulty();
	void play_game();
	void game_loop();
	void death();
	void win();
	void processInput(PacMan& pacman);
	void rage_timer(int seconds);

public:
	Game();
	void run();

};