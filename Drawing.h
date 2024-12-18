#pragma once
#include "DynamicEntity.h"
#include "list"
#define BRANCO 0
#define AZUL 1
#define AMARELO 2
#define VERDE 3
#define VERMELHO 4
#define MAGENTA 5
#define CIANO 6
using namespace std;
class Drawing{
public:
	virtual void Draw(Size_TXY coords) = 0;			// Draw the object
	virtual void Update() = 0;						// Update the object
	virtual Size_TXY Start() = 0;					// Get the start position of the object
	virtual EntTypes Type() = 0;					// Get the type of the object
};