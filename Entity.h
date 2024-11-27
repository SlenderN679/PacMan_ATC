#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "_Size_TXY.h" // Inclui a definição da estrutura Size_TXY

#include <list> // Inclui a biblioteca de listas da STL

using namespace std; // Usa o namespace std para evitar prefixar std::

// Enumeração para os tipos de entidades
enum EntTypes { BIT_E, BYTE_E, CHERRY_E, GHOST_E, PACMAN_E };

// Declaração da classe Entity
class Entity {
    Size_TXY coords; // Coordenadas da entidade
    const EntTypes type; // Tipo da entidade
    static list<Entity*> entities; // Lista estática de apontadores para entidades

protected:
    static bool rage; // Atributo protegido estático para indicar o estado de "rage"

public:
    // Construtor da classe Entity
    Entity(Size_TXY coords, EntTypes type);
    bool move(IntXY dis); // Método para mover a entidade
    Size_TXY Position() const; // Método para obter a posição da entidade
    EntTypes Type() const; // Método para obter o tipo da entidade
    /*bool ECollision(Size_TXY coords);
    bool OCollision(Size_TXY coords);*/
    // Métodos comentados para verificar colisões com outras entidades e objetos
};