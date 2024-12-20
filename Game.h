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
	int difficulty;																				// 1 - Easy, 2 - Medium, 3 - Hard
	int score;																					// Score of the current game
	int levels_completed;																		// Number of levels completed
	bool cheat;																					// If the player used a cheat
	bool game_running;																			// If the game is running
	//---
	void DrawMenu(const char* tittle, const char* options[], int num_options, int highlight);	// Draw the MainMenu
	void MainMenu();																			// Main Menu
	void SettingsMenu();																		// Settings Menu
	void SelectControls();																		// Select the controls
	void SelectDifficulty();																	// Select the difficulty
	void StartLevel();																			// Start the level
	void LevelLoop();																			// Loop of the level
	void Death();																				// Death screen
	void Win();																					// Win screen
	void process_input(PacMan& pacman);															// Process the input *parallel*
	void rage_timer(int seconds);																// Rage timer *parallel*

public:
	Game();																						// Constructor
	void RunGame();																				// Run the game

};