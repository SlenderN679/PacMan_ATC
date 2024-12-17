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
	virtual void Draw(Size_TXY coords) = 0;
	virtual void Update() = 0;
	virtual Size_TXY Start() = 0;
	virtual EntTypes Type() = 0;
};