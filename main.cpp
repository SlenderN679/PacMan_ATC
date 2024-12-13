#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <curses.h>
#include "Map.h"
#include "PacMan_UI.h"
#include "Ghost.h"
#include "Wall.h"
#include "Intersection.h"
#include "Menu.h"

using namespace std;

Map map;
PacMan_UI pacman;

static void rage_timer(int seconds) {
    while (true) {
        if (DynamicEntity::Rage()) {
            for (int i = 0; i < seconds; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            DynamicEntity::Calm();
        }
    }
}

void processInput() {
    while (true) {
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
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    //---
    initscr(); // Initialize the curses library
    noecho(); // Don't echo user input to the screen
    cbreak(); // Disable line buffering
    keypad(stdscr, true); // Enable special keys
    curs_set(0);
	start_color();
    //---
    /*menu();*/
    //---
    Wall::CreateWalls();
	Intersection::CreateIntersections();
    Dot::CreateDots();
	Ghost::CreateGhosts();
    map.addPortal({ 0, 17 });
    map.addPortal({ 27, 17 });
    //---
    map.drawMap();
    //---
    std::thread inputThread(processInput);
    std::thread rageThread(rage_timer, 15);
    std::thread ghostStart(&Ghost::Start);
    this_thread::sleep_for(chrono::milliseconds(1000));
    //---
    while ((pacman.getLives()>0)&&(Dot::DotReamining()>0)) {
        //pacman.Move();
		Ghost::MoveGhosts(pacman);
		pacman.Draw();
        //map.drawMap();
        this_thread::sleep_for(chrono::milliseconds(250));
		refresh();
    }
    //---
    clear();
	if (pacman.getLives() <= 0) {
		//mvprintw(0,0,"You Lose!\n");
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
	}
	else {
		mvprintw(0,0,"You Win!\n");
	}
  refresh();
    //---
    inputThread.join();
    rageThread.join();
	ghostStart.join();
    return 0;
}