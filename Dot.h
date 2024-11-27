#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "Entity.h" // Inclui a definição da classe Entity

#include "Map.h" // Inclui a definição da classe Map

#include "list" // Inclui a biblioteca de listas da STL

using namespace std; // Usa o namespace std para evitar prefixar std::

// Declaração da subclasse Dot que herda de Entity
class Dot : public Entity {
    static list<Dot*> dots; // Lista estática de apontadores para objetos Dot

public:
    // Construtor da classe Dot
    Dot(Size_TXY pos, EntTypes type);
    static bool Grid(); // Método estático para verificar a grade
};