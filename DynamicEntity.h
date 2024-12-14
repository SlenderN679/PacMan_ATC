#pragma once
#include "_Size_TXY.h"
#include "chrono"
#include "thread"
#include <cstdlib>
#include <fstream>
#include <string>
#include <curses.h>
#include <stdio.h>
#include <list>
enum EntTypes {BIT_E, BYTE_E, CHERRY_E, GHOST_E, PACMAN_E, XX};

#define BRANCO 0
#define AZUL 1
#define AMARELO 2
#define VERDE 3
#define VERMELHO 4
#define MAGENTA 5
#define CIANO 6

using namespace std;

class DynamicEntity {
	Size_TXY coords;
	const EntTypes type;
	static list<DynamicEntity*> entities;
protected:
	static bool rage;
	Size_TXY GStart();
	void PStart(Size_TXY c);
public:
	DynamicEntity(Size_TXY coords, EntTypes type);
	Size_TXY Move(IntXY dis);
	Size_TXY Position() const;
	EntTypes Type() const;
	static bool Rage();
	static void Calm();
	static void timer(int seconds);
	EntTypes CheckPos(Size_TXY coords);
	void rage_timer(int seconds);
	void StartRage();
	/*bool ECollision(Size_TXY coords);
	bool OCollision(Size_TXY coords);*/
};