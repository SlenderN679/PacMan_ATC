#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "Object.h" // Inclui a definição da classe Object

#include "Map.h" // Inclui a definição da classe Map

#include "list" // Inclui a biblioteca de listas da STL

using namespace std; // Usa o namespace std para evitar prefixar std::

// Declaração da subclasse Wall que herda de Object
class Wall : public Object {
    static list<Wall> walls; // Lista estática de objetos Wall

public:
    // Construtor da classe Wall
    Wall(size_t width, size_t height, Size_TXY coords);
};

