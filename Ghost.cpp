#include "Ghost.h" // Inclui a definição da classe Ghost
#include "Map.h"   // Inclui a definição da classe Map para interagir com o mapa

list<Ghost*> Ghost::ghosts; // Inicializa a lista estática de apontadores para objetos Ghost

// Construtor da classe Ghost
Ghost::Ghost(Size_TXY coords, GstTypes type) : Entity(coords, GHOST_E), type(type), direction(UP) {
    
    ghosts.push_back(this); // Adiciona o novo fantasma à lista estática de fantasmas
    Map::addGhost(coords);  // Adiciona o fantasma ao mapa na posição inicial
}

// Método para mover o fantasma
void Ghost::move() {
	Size_TXY currentPos = Position(); // Obtém a posição atual do fantasma
	Size_TXY newPos = currentPos;    // Inicializa a nova posição com a posição atual

    // Movimenta o fantasma na direção atual
    switch (direction) {
    case UP:    
        newPos.y = (currentPos.y > 0) ? currentPos.y - 1 : currentPos.y;  
        break;

    case DOWN:
        newPos.y = (currentPos.y < 35) ? currentPos.y + 1 : currentPos.y;
        break;

    case LEFT:
        newPos.x = (currentPos.x > 0) ? currentPos.x - 1 : currentPos.x;
        break;

    case RIGHT:
        newPos.x = (currentPos.x < 27) ? currentPos.x + 1 : currentPos.x;
        break;
    }

    // Verifica se a nova posição é válida (não é uma parede)
    if (Map::getCell(newPos) != WALL) {
        Map::clearCell(currentPos); // Limpa a célula atual
        coords = newPos;            // Atualiza as coordenadas do fantasma
        Map::addGhost(newPos);      // Adiciona o fantasma na nova posição
    }
    else {
        wall(); // Interage com a parede se a nova posição for uma parede
    }
}

// Método para obter a direção atual do fantasma
Directions Ghost::getDirection() {

    return direction;
}

// Método para obter o tipo de fantasma
GstTypes Ghost::getType() {

    return type;
}

// Método para interagir com uma parede
void Ghost::wall() {
    // Implementação da lógica para quando o fantasma encontra uma parede
    // Exemplo: mudar a direção do fantasma aleatoriamente
    direction = static_cast<Directions>(rand() % 4);
}

// Método para teletransportar o fantasma
bool Ghost::teleport() {
    // Implementação da lógica de teletransporte
    // Exemplo: mover o fantasma para uma posição aleatória no mapa
    Size_TXY newPos = { rand() % 28, rand() % 36 };
	if (Map::getCell(newPos) == SPACE) { // Verifica se a nova posição é válida

        Map::clearCell(Position()); // Limpa a célula atual
        coords = newPos;            // Atualiza as coordenadas do fantasma
        Map::addGhost(newPos);      // Adiciona o fantasma na nova posição
        return true;
    }
    return false;
}