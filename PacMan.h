#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "Entity.h" // Inclui a definição da classe Entity

#include "_Directions.h" // Inclui a definição da enumeração Directions

#include "Dot.h" // Inclui a definição da classe Dot

#include "Ghost.h" // Inclui a definição da classe Ghost

#include "Wall.h" // Inclui a definição da classe Wall

#include "Portal.h" // Inclui a definição da classe Portal

#include "Map.h" // Inclui a definição da classe Map

#include "list" // Inclui a biblioteca de listas da STL

using namespace std; // Usa o namespace std para evitar prefixar std::

// Declaração da subclasse PacMan que herda de Entity
class PacMan : public Entity {
    Directions direction; // Direção atual do PacMan
    int lives; // Número de vidas do PacMan
    int score; // Pontuação do PacMan

public:
    // Construtor da classe PacMan
    PacMan();
    void move(); // Método para mover o PacMan
    void turn(Directions direction); // Método para mudar a direção do PacMan
    void dot(const Dot& d); // Método para interagir com um Dot
    void wall(const Wall& w); // Método para interagir com uma Wall
    void ghost(const Ghost& g); // Método para interagir com um Ghost
    void portal(const Portal& p); // Método para interagir com um Portal
    Directions getDirection(); // Método para obter a direção atual do PacMan
    int getLives(); // Método para obter o número de vidas do PacMan
    int getScore(); // Método para obter a pontuação do PacMan
};