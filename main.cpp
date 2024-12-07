#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include "Map.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Wall.h"
#include "Intersection.h"

using namespace std;

Map map;
PacMan pacman;

static void rage_timer(int seconds) {
    while (true) {
        if (Entity::Rage()) {
            for (int i = 0; i < seconds; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            Entity::Calm();
        }
    }
}

void processInput() {
    while (true) {
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            pacman.turn(UP);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            pacman.turn(DOWN);
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            pacman.turn(LEFT);
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            pacman.turn(RIGHT);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {
    
	//Map::readMap();
    Wall::CreateWalls();
	Intersection::CreateIntersections();
    Dot::CreateDots();
	Ghost::CreateGhosts();
    map.addPortal({ 0, 17 });
    map.addPortal({ 27, 17 });
    map.drawMap(pacman);
    std::thread inputThread(processInput);
    std::thread rageThread(rage_timer, 15);
    std::thread ghostStart(&Ghost::Start);
    this_thread::sleep_for(chrono::milliseconds(1000));
    while (pacman.getLives()>0) {
        pacman.move();
		Ghost::MoveGhosts(pacman);
        map.drawMap(pacman);
        this_thread::sleep_for(chrono::milliseconds(250));
    }
	system("cls");
	cout << "Game Over!" << endl;
    inputThread.join();
    rageThread.join();
	ghostStart.join();
    return 0;
}