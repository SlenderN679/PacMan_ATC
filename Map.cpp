#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "Map.h" // Inclui a definição da classe Map

#include "iostream" // Inclui a biblioteca de entrada e saída padrão

#include <cstdlib> // Inclui a biblioteca padrão para funções do sistema

using namespace std; // Usa o namespace std para evitar prefixar std::

unsigned char Map::maze[36][28]; // Inicializa a matriz estática que representa o labirinto

// Construtor da classe Map
Map::Map() {

	for (int y = 0; y < 36; y++) { 

		for (int x = 0; x < 28; x++) { // Loop para percorrer as colunas do labirinto

			if ((x == 0 || x == 27 || y == 3 || y == 33) && (y > 2 && y < 34) && !(y >= 13 && y <= 21)) { // Condição para as bordas e algumas linhas

                maze[y][x] = WALL; // Define as bordas e algumas linhas como paredes
                
            }
            else {
                maze[y][x] = SPACE;  // Define o restante como espaço vazio
               
            }
        }
    }
}

// Método para desenhar o mapa
void Map::drawMap() {

    system("cls"); // Limpa a tela da consola

    for (int y = 0; y < 36; y++) { // Loop para percorrer as linhas do labirinto

		for (int x = 0; x < 28; x++) { // Loop para percorrer as colunas do labirinto

            cout << maze[y][x]; // Imprime cada célula do labirinto
            
        }
        cout << endl; // Pula para a próxima linha após imprimir uma linha do labirinto
        
    }
}

// Método estático para adicionar o PacMan no mapa
bool Map::addPacman(Size_TXY pos) {

	if (maze[pos.y][pos.x] == SPACE) { // Condição para a posição especificada estar vazia

        maze[pos.y][pos.x] = PACMAN; // Adiciona o PacMan na posição especificada se estiver vazia
        
        return true;
    }
    return false;
}

// Método estático para adicionar um fantasma no mapa
bool Map::addGhost(Size_TXY pos) {

	if (maze[pos.y][pos.x] == SPACE) { // Condição para a posição especificada estar vazia

        maze[pos.y][pos.x] = GHOST; // Adiciona um fantasma na posição especificada se estiver vazia
        
        return true;
    }
    return false;
}

// Método estático para adicionar uma parede no mapa
bool Map::addWall(Size_TXY pos) {

	if (maze[pos.y][pos.x] == SPACE) { // Condição para a posição especificada estar vazia

        maze[pos.y][pos.x] = WALL; // Adiciona uma parede na posição especificada se estiver vazia
        
        return true;
    }
    return false;
}

// Método estático para adicionar um byte no mapa
bool Map::addByte(Size_TXY pos) {

	if (maze[pos.y][pos.x] == SPACE) { // Condição para a posição especificada estar vazia

        maze[pos.y][pos.x] = BYTE; // Adiciona um byte na posição especificada se estiver vazia
        
        return true;
    }
    return false;
}

// Método estático para adicionar um bit no mapa
bool Map::addBit(Size_TXY pos) {

	if (maze[pos.y][pos.x] == SPACE) { // Condição para a posição especificada estar vazia

        maze[pos.y][pos.x] = BIT; // Adiciona um bit na posição especificada se estiver vazia
        
        return true;
    }
    return false;
}

// Método estático para adicionar um portal no mapa
bool Map::addPortal(Size_TXY pos) {

	if (maze[pos.y][pos.x] == SPACE) { // Condição para a posição especificada estar vazia

        maze[pos.y][pos.x] = PORTAL; // Adiciona um portal na posição especificada se estiver vazia
        
        return true;
    }
    return false;
}

// Método estático para limpar uma célula do mapa
bool Map::clearCell(Size_TXY pos) {

	if (maze[pos.y][pos.x] != WALL) { // Condição para a posição especificada não ser uma parede

        maze[pos.y][pos.x] = 32; // Limpa a célula na posição especificada se não for uma parede

        return true;
    }
    return false;
}

// Método estático para obter o valor de uma célula do mapa
unsigned char Map::getCell(Size_TXY pos) {

    return maze[pos.y][pos.x]; // Retorna o valor da célula na posição especificada
    
}