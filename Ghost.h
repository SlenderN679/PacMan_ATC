#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "Entity.h" // Inclui a definição da classe Entity

#include "_Directions.h" // Inclui a definição da enumeração Directions

#include "list" // Inclui a biblioteca de listas da STL

using namespace std; // Usa o namespace std para evitar prefixar std::

enum GstTypes { BLINKY/*RED*/, PINKY/*PINK*/, INKY/*BLUE*/, CLYDE/*ORANGE*/ }; // Enumeração para os tipos de fantasmas com as cores associadas

// Declaração da subclasse Ghost que herda de Entity
class Ghost : public Entity {
    Directions direction; // Direção atual do fantasma
    const GstTypes type; // Tipo de fantasma
    static list<Ghost*> ghosts; // Lista estática de apontadores para objetos Ghost

public:
    // Construtor da classe Ghost
    Ghost(Size_TXY coords, GstTypes type);
    void move(); // Método para mover o fantasma
    Directions getDirection(); // Método para obter a direção atual do fantasma
    GstTypes getType(); // Método para obter o tipo de fantasma
    void wall(); // Método para interagir com uma parede
    bool teleport(); // Método para teletransportar o fantasma
};