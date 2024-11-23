#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include "Map.h"
#include "PacMan.h"

using namespace std;

Map map;
PacMan pacman;


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
    map.addGhost({ 5, 9 });
    map.addWall({ 13, 10 });
    map.addByte({ 4, 1 });
    map.addBit({ 17, 20 });
	map.addPortal({ 0, 17 });
	map.addPortal({ 27, 17 });
	map.drawMap();
    std::thread inputThread(processInput);
    this_thread::sleep_for(chrono::milliseconds(1000));
	while (true){
		pacman.move();
		map.drawMap();
		this_thread::sleep_for(chrono::milliseconds(100));
	}
    inputThread.join();
    return 0;
}
//#include <iostream>
//#include <windows.h>
//#include <thread>
//#include <chrono>
//
//void processInput() {
//    while (true) {
//        if (GetAsyncKeyState(VK_UP) & 0x8000) {
//            std::cout << "Up arrow pressed" << std::endl;
//        }
//        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
//            std::cout << "Down arrow pressed" << std::endl;
//        }
//        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
//            std::cout << "Left arrow pressed" << std::endl;
//        }
//        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
//            std::cout << "Right arrow pressed" << std::endl;
//        }
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//}
//
//int main() {
//    std::thread inputThread(processInput);
//
//    // Main loop
//    while (true) {
//        // Your main code here
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//
//    inputThread.join();
//    return 0;
//}

/*
wall -> 178
byte -> 233
bit -> 248
Packman -> 67
ghost -> 234
*/