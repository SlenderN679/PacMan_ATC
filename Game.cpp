#include "Game.h"

Game::Game() : difficulty(1), levels_completed(0), score(0), gameRunning(false), cheat(false){}

void Game::DrawMenu(const char* title, const char* option[], int num_options, int highlight) {
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);  // Get the current window size
    int startY = (maxY) / 2;  // Center the map vertically
    int startX = (maxX) / 2;  // Center the map horizontally
    clear();
    mvprintw(startY, (startX - (strlen(title)) / 2), title);
    for (int i = 0; i < num_options; ++i) {
        if (i == highlight) {
            attron(A_REVERSE);
            mvprintw(startY + 2 + i, startX - (strlen(option[i]) / 2), option[i]);
            attroff(A_REVERSE);
        }
        else {
            mvprintw(startY+ 2 + i, startX - (strlen(option[i]) / 2), option[i]);
        }
    }
    refresh();
}
void Game::MainMenu() {
    int highlight = 0;
    int choice;
    const char* options[] = { "Play", "Settings", "Exit" };
    const int num_options = 3;

    while (true) {
        DrawMenu("PAC-MAN", options, num_options, highlight);
        choice = getch();
        switch (choice) {
        case KEY_UP:
            highlight = (highlight == 0) ? num_options - 1 : highlight - 1;
            break;
        case KEY_DOWN:
            highlight = (highlight == num_options - 1) ? 0 : highlight + 1;
            break;
        case '\n':
            if (highlight == 0) {
                StartLevel();
            }
            else if (highlight == 1) {
                SettingsMenu();
            }
            else if (highlight == 2) {
                endwin();
                exit(0);
            }
            break;
        default:
            break;
        }
    }
}

void Game::SettingsMenu() {
    int highlight = 0;
    int choice;
    const char* options[] = { "Controls", "Difficulty", "Back" };
    const int num_options = 3;

    while (true) {
        DrawMenu("Settings", options, num_options, highlight);
        choice = getch();
        switch (choice) {
        case KEY_UP:
            highlight = (highlight == 0) ? num_options - 1 : highlight - 1;
            break;
        case KEY_DOWN:
            highlight = (highlight == num_options - 1) ? 0 : highlight + 1;
            break;
        case '\n':
            if (highlight == 0) {
                SelectControls();
            }
            else if (highlight == 1) {
                SelectDifficulty();
            }
            else if (highlight == 2) {
				endwin();
                return;
            }
            break;
        default:
            break;
        }
    }
}

void Game::SelectControls() {
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);  // Get the current window size
    int startY = (maxY) / 2;  // Center the map vertically
    int startX = (maxX) / 2;  // Center the map horizontally
    clear();
    mvprintw(startY, startX - (17 / 2), "Controls:");
    mvprintw(startY + 2, startX - (25 / 2), "Move Up:    Arrow Up");
    mvprintw(startY + 3, startX - (25 / 2), "Move Down:  Arrow Down");
    mvprintw(startY + 4, startX - (25 / 2), "Move Left:  Arrow Left");
    mvprintw(startY + 5, startX - (25 / 2), "Move Right: Arrow Right");
    mvprintw(startY + 6, startX - (10 / 2), "Press any key to go back");
    refresh();
    getch();
}
void Game::SelectDifficulty() {
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);  // Get the current window size
    int startY = maxY / 2;         // Center vertically
    int startX = maxX / 2;         // Center horizontally
    int currentSelection = 1;      // Start with "Easy" selected

    while (true) {
        clear();
        mvprintw(startY, startX - 10, "Choose Difficulty:");

        // Display options with highlighting
        for (int i = 1; i <= 3; ++i) {
            if (i == currentSelection) {
                attron(A_REVERSE);  // Highlight the current selection
            }
            mvprintw(startY + 1 + i, startX - 10, "%d. %s", i,
                (i == 1 ? "Easy" : i == 2 ? "Medium" : "Hard"));
            if (i == currentSelection) {
                attroff(A_REVERSE); // Turn off highlighting
            }
        }

        refresh();
        int ch = getch();

        switch (ch) {
        case KEY_UP:
            if (currentSelection > 1) {
                --currentSelection;
            }
            break;
        case KEY_DOWN:
            if (currentSelection < 3) {
                ++currentSelection;
            }
            break;
        case '\n': // Enter key
            difficulty = currentSelection;
            return;
        }
    }
}

void Game::StartLevel() {
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);  // Get the current window size
    int startY = (maxY) / 2;  // Center the map vertically
    int startX = (maxX) / 2;  // Center the map horizontally
    clear();
    mvprintw(startY , startX - (11 / 2), "Playing...");//tentar implementar o jogo//
    refresh();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    clear();
    levels_completed = 0;
    while (levels_completed != difficulty) {
        gameRunning = true;
        clear();
        mvprintw(startY, startX - (22 / 2), "Starting level %d ...", (levels_completed+1));
        refresh();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        clear();
        LevelLoop();
    }
	Win();
}
void Game::LevelLoop() {
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);  // Get the current window size
    int startY = (maxY - ROWS) / 2;  // Center the map vertically
    int startX = (maxX - COLS) / 2;  // Center the map horizontally
    Map map;
    PacMan_UI pacman;
    Wall::CreateWalls();
    Portal::CreatePortals();
    Intersection::CreateIntersections();
    Ghost_UI::CreateGhosts();
    Dot_UI::CreateDots();
    Ghost::AddPacMan(pacman);
    //---
    list<Drawing*> sprites;
    sprites.push_back(&pacman);
    for (Ghost_UI* g : Ghost_UI::GhostList()) {
        sprites.push_back(g);
    }
    for (Dot_UI* d : Dot_UI::DotList()) {
        sprites.push_back(d);
    }
    //---
    map.drawMap();
    for (auto it = sprites.rbegin(); it != sprites.rend(); ++it) {
		Drawing* d = *it;
        if (d == nullptr) {
            sprites.remove(d);
        }
        else {
            d->Draw(d->Start());
        }
    }
    attron(COLOR_PAIR(AMARELO));
    mvprintw(startY + 1, startX + 20, "Level: %d", levels_completed + 1);
    attroff(COLOR_PAIR(AMARELO));
    refresh();
    //---
    std::thread inputThread(&Game::process_input, this, std::ref(pacman));
    std::thread ghostStart(&Ghost::start_ghosts, &gameRunning);
    std::thread rageThread(&Game::rage_timer, this, 15);
    this_thread::sleep_for(chrono::milliseconds(1000));
    //---
    bool r = false;
	bool tickPacMan = false;
	bool tickBlinky = false;
	bool tickPinky = false;
	bool tickInky = false;
	bool tickClyde = false;
    //---
    while ((pacman.Lives() > 0) && (Dot::DotReamining() > 0) && (!cheat)) {
        for (auto it = sprites.rbegin(); it != sprites.rend(); ++it) {
            Drawing* d = *it;
            if (d == nullptr) {
                sprites.remove(d);
            }
            else {
                switch (d->Type()){
				case PACMAN_E:
                    if (levels_completed == 2) {
						if (!tickPacMan) {
							d->Update();
							tickPacMan = true;
						} else {
							tickPacMan = false;
						}
                    } else {
                        d->Update();
                    }
					break;
				case GHOST_E:
                    if (levels_completed == 0) {
                        switch (static_cast<Ghost_UI*>(d)->getNames()) {
                        case BLINKY:
                            if (!tickBlinky) {
                                d->Update();
                                tickBlinky = true;
                            }
                            else {
                                tickBlinky = false;
                            }
                            break;
                        case PINKY:
                            if (!tickPinky) {
                                d->Update();
                                tickPinky = true;
                            }
                            else {
                                tickPinky = false;
                            }
                            break;
                        case INKY:
                            if (!tickInky) {
                                d->Update();
                                tickInky = true;
                            }
                            else {
                                tickInky = false;
                            }
                            break;
                        case CLYDE:
                            if (!tickClyde) {
                                d->Update();
                                tickClyde = true;
                            }
                            else {
                                tickClyde = false;
                            }
                            break;
                        default:
                            break;
                        };
                    } else {
                        d->Update();
                    }
					break;
                default:
					d->Update();
                    break;
                }
            }
        }
        if (r != DynamicEntity::Rage()) {
            map.drawMap();
            r = DynamicEntity::Rage();
        }
        this_thread::sleep_for(chrono::milliseconds(250));
        refresh();
    }
	cheat = false;
    clear();
	if (pacman.Lives() <= 0) {
		Death();
	} else {
        levels_completed++;
		score += pacman.Score();
	}
	Ghost_UI::ClearGhosts();
	Dot_UI::ClearDots();
	Wall::ClearWalls();
	Portal::ClearPortals();
	Intersection::ClearIntersections();
    //--
	DynamicEntity::ClearEntities();
	StaticObject::ClearObjects();
    //--
    refresh();
    //---
	gameRunning = false;
    inputThread.join();
    ghostStart.join();
    rageThread.join();
}
void Game::RunGame() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
	while (true)
    MainMenu();
    endwin();
}
void Game::Death() {
    clear();
    mvprintw(0, 0, "                                                   .##################################+.\n");
    mvprintw(1, 0, "                                                 .####------------------------------+###+.\n");
    mvprintw(2, 0, "                                               .##+#-.                               .+###-\n");
    mvprintw(3, 0, "                                             .+#+#-.                                   .##+#-\n");
    mvprintw(4, 0, "                                           .-###-                                        .####-\n");
    mvprintw(5, 0, "                                          -###+.                  ..---..                  .####.\n");
    mvprintw(6, 0, "                                        -####.                .-+#+-...-+#+..                -####.\n");
    mvprintw(7, 0, "                                      -####.               .+#+.        ..-###-.              .-####.\n");
    mvprintw(8, 0, "                                    .####.               .#+.           .+##+.-++.               -###+.\n");
    mvprintw(9, 0, "                                  .####-                +#.            .-##+.   -#.               .-###-.\n");
    mvprintw(10, 0, "                                .##-#-                 .#.++#-..         --.  .-+-#.                 +#+#.\n");
    mvprintw(11, 0, "                              .+#+#-                   +- -++-..+--.      .#+ .+###-                  .##+#-.\n");
    mvprintw(12, 0, "                              -##-.                   .#. -+                . .##+++                    .####.\n");
    mvprintw(13, 0, "                              -#+                     .#..+-                  .+##-#                     .#+#.\n");
    mvprintw(14, 0, "                              -#+                     .#.-#.  ...        ....  -#--+                     .#+#.\n");
    mvprintw(15, 0, "                              -#+                      #-#-+#---+#-.-. -#----+###+#-                     .#+#.\n");
    mvprintw(16, 0, "                              -#+                      +#-#-     -+#+..#-    .+####.                     .#+#.\n");
    mvprintw(17, 0, "                              -#+                     .##-#.     -#-. .#.  -##-++##.                     .#+#.\n");
    mvprintw(18, 0, "                              -#+                      -#-#.  ..-#-.+#-.##-##..++##.                     .#+#.\n");
    mvprintw(19, 0, "                              -#+            .-####-. .#-#+####-  -#-.#-  .####-#-#-  .+###+.            .#+#.\n");
    mvprintw(20, 0, "                              -#+           .+-.-+-++. .#-.-...#. +#-.-#.-#+-+#+.++. -#-  .+#.           .#+#.\n");
    mvprintw(21, 0, "                              -#+        .+###--+..-++#+.####- -+ -####+.+- .####+-+#-.    -#++-.        .#+#.\n");
    mvprintw(22, 0, "                              -#+      .#+..+.  -#- .. .--+++++..       .+-++.#-+--.   .--.  ...-#.      .#+#.\n");
    mvprintw(23, 0, "                              -#+      --. .+.####+--++...#-+++.+###+####++#.+#-+.  ....+###.--  -#      .#+#.\n");
    mvprintw(24, 0, "                              -#+      .#- .+#.      .-##--+++##############+#.-###-..-##.  -#+ .#.      .#+#.\n");
    mvprintw(25, 0, "                              -#+        .#+.            .+- +######++-####+#..+-            .+#+.       .#+#.\n");
    mvprintw(26, 0, "                              -#+                         -+-###-..--....++#-.++                         .#+#.\n");
    mvprintw(27, 0, "                              -#+                          ++-###.      .+##..#.                         .#+#.\n");
    mvprintw(28, 0, "                              -#+                        .-++.+##+.     -###.#++.                        .#+#.\n");
    mvprintw(29, 0, "                              -##-.                  .-##--.-#.#####..+####+#- .-+##.                   .####.\n");
    mvprintw(30, 0, "                              .+#+#-        .+#--###+-..   .#+#.##########-#-#+.   .--#######.        .##+#-.\n");
    mvprintw(31, 0, "                                .##+#-      -#-..#.     .-#-. .##..+###--+#-  .-#-      .#. ..#-    .+###-\n");
    mvprintw(32, 0, "                                  .####.    .+-. .+   .+#.      .-######-.       .#+.   .-#-.-#.  .-###+.\n");
    mvprintw(33, 0, "                                    .####.    ++.+. .-#.                           .#-..+-.++.   -###+.\n");
    mvprintw(34, 0, "                                      -####.  +#+.  ++.                             .+#-..-#+  -####.\n");
    mvprintw(35, 0, "                                        -###+..#+---#-                               .##---#.-####.\n");
    mvprintw(36, 0, "                                          -###+......                                  .---.####-\n");
    mvprintw(37, 0, "                                           .+###-                                        .####-.\n");
    mvprintw(38, 0, "                                             .##+#-                                    .+#+#-\n");
    mvprintw(39, 0, "                                               .####-.                               .+###-\n");
    mvprintw(40, 0, "                                                 .####-------------------------------###+.\n");
	mvprintw(41, 0, "                                                   -##################################+.\n");
	refresh();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	score = 0;
	levels_completed = 0;
    while (getch() != '\n');
}
void Game::Win() {
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);  // Get the current window size
    int startY = (maxY) / 2;  // Center the map vertically
    int startX = (maxX) / 2;  // Center the map horizontally
	clear();
	mvprintw(startY, startX - (9 / 2), "You win!");
	mvprintw(startY + 1, startX - (16 / 2), "Final score: %d", score);
	mvprintw(startY + 2, startX - (15 / 2), "Difficulty: %d", difficulty);
	refresh();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	score = 0;
	levels_completed = 0;
	while (getch() != '\n');
}
void Game::process_input(PacMan& pacman) {
    while (gameRunning) {
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            pacman.Turn(UP);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            pacman.Turn(DOWN);
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            pacman.Turn(LEFT);
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            pacman.Turn(RIGHT);
        }
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            cheat = true;
		}
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
void Game::rage_timer(int seconds) {
    while (gameRunning) {
        if (DynamicEntity::Rage()) {
            for (int i = 0; i < seconds; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            DynamicEntity::Calm();
        }
    }
}