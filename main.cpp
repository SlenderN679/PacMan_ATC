#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include "Map.h"
#include "PacMan.h"

using namespace std;

Map map;
PacMan pacman;

void walls() {
	Wall w1(4, 3, { 2,5 });
	Wall w2(5, 3, { 7,5 });
	Wall w3(2, 4, { 13,4 });
	Wall w4(5, 3, { 16,5 });
	Wall w5(4, 3, { 22,5 });
    //---
    Wall w6(4, 2, { 2,9 });
    Wall w7(2, 8, { 7,9 });
    Wall w8(8, 2, { 10,9 });
    Wall w9(2, 8, { 19,9 });
    Wall w10(4, 2, { 22,9 });
	//---
	Wall w11(5, 1, { 1,12 });
	Wall w12(3, 2, { 9,12 });
	Wall w13(2, 3, { 13,11 });
	Wall w14(3, 2, { 16,12 });
	Wall w15(5, 1, { 22,12 });
	//---
	Wall w16(1, 3, { 5,13 });
	Wall w17(3, 1, { 10,15 });
	Wall w18(3, 1, { 15,15 });
	Wall w19(1, 3, { 22,13 });
	//---
	Wall w20(6, 1, { 0,16 });
	Wall w21(1, 3, { 10,16 });
	Wall w22(1, 3, { 17,16 });
	Wall w23(6, 1, { 22,16 });
	//---
	Wall w24(6, 1, { 0,18 });
	Wall w25(2, 5, { 7,18 });
	Wall w26(8, 1, { 10,19 });
	Wall w27(2, 5, { 19,18 });
	Wall w28(6, 1, { 22,18 });
	//---
	Wall w29(1, 3, { 5,19 });
	Wall w30(8, 2, { 10,21 });
	Wall w31(1, 3, { 22,19 });
	//---
	Wall w32(5, 1, { 1,22 });
	Wall w33(5, 1, { 22,22 });
	//---
	Wall w34(4, 2, { 2,24 });
	Wall w35(5, 2, { 7,24 });
	Wall w36(2, 3, { 13,23 });
	Wall w37(5, 2, { 16,24 });
	Wall w38(4, 2, { 22,24 });
	//---
	Wall w39(2, 2, { 1,27 });
	Wall w40(2, 3, { 4,26 });
	Wall w41(2, 3, { 7,27 });
	Wall w42(8, 2, { 10,27 });
	Wall w43(2, 3, { 19,27 });
	Wall w44(2, 3, { 22,26 });
	Wall w45(2, 2, { 25,27 });
	//---
	Wall w46(10, 2, { 2,30 });
	Wall w47(2, 3, { 13,29 });
	Wall w48(10, 2, { 16,30 });
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
    walls();
	Dot::Grid();
    map.addGhost({ 5, 9 });
    map.addWall({ 13, 10 });
    //map.addByte({ 4, 1 });
    //map.addBit({ 17, 20 });
	map.addPortal({ 0, 17 });
	map.addPortal({ 27, 17 });
	map.drawMap();
    std::thread inputThread(processInput);
    this_thread::sleep_for(chrono::milliseconds(1000));
	while (true){
		pacman.move();
		map.drawMap();
		this_thread::sleep_for(chrono::milliseconds(250));
	}
    inputThread.join();
    return 0;
}

/*
wall -> 178
byte -> 233
bit -> 248
Packman -> 67
ghost -> 234
*/