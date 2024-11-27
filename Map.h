#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "_Size_TXY.h" // Inclui a definição da estrutura Size_TXY

#define SPACE 32 // Define o valor ASCII para o espaço

#define PACMAN 184 // Define o valor ASCII para o PacMan

#define GHOST 225 // Define o valor ASCII para o fantasma

#define WALL 178 // Define o valor ASCII para a parede

#define BYTE 157 // Define o valor ASCII para o byte

#define BIT 155 // Define o valor ASCII para o bit

#define PORTAL 245 // Define o valor ASCII para o portal

// Declaração da classe Map
class Map {
    static unsigned char maze[36][28]; // Matriz estática que representa o labirinto

public:
    // Construtor da classe Map
    Map();
    void drawMap(); // Método para desenhar o mapa
    static bool addPacman(Size_TXY pos); // Método estático para adicionar o PacMan no mapa
    static bool addGhost(Size_TXY pos); // Método estático para adicionar um fantasma no mapa
    static bool addWall(Size_TXY pos); // Método estático para adicionar uma parede no mapa
    static bool addByte(Size_TXY pos); // Método estático para adicionar um byte no mapa
    static bool addBit(Size_TXY pos); // Método estático para adicionar um bit no mapa
    static bool addPortal(Size_TXY pos); // Método estático para adicionar um portal no mapa
    static bool clearCell(Size_TXY pos); // Método estático para limpar uma célula do mapa
    static unsigned char getCell(Size_TXY pos); // Método estático para obter o valor de uma célula do mapa
};

/*
#define PACMAN 67
#define GHOST 71
#define WALL 178
#define BYTE 48
#define BIT 111
*/
// Comentários com definições alternativas de valores ASCII para os elementos do mapa