#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação
#include "Object.h" // Inclui a definição da classe Object
#include "list" // Inclui a biblioteca de listas da STL
using namespace std; // Usa o namespace std para evitar prefixar std::

// Enumeração para os lados do portal
enum Sides { P_RIGHT, P_LEFT };

// Declaração da subclasse Portal que herda de Object
class Portal : public Object {
    Sides side; // Variável-membro que armazena o lado do portal
    static list<Portal> portals; // Lista estática de todos os portais
public:
    // Construtor da classe Portal
    Portal(float width, float height, Size_TXY coords, ObjTypes type, Sides side);
};