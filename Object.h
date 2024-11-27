#pragma once // Diretiva do pré-processador para garantir que o arquivo do cabeçalho seja incluído apenas uma vez durante a compilação

#include "list" // Inclui a biblioteca de listas da STL

#include "_Size_TXY.h" // Inclui a definição da estrutura Size_TXY

using namespace std; // Usa o namespace std para evitar prefixar std::

// Enumeração para os tipos de objetos
enum ObjTypes { WALL_O, PORTAL_O };

// Declaração da classe Object
class Object {
    size_t width; // Largura do objeto
    size_t height; // Altura do objeto
    Size_TXY coords; // Coordenadas do objeto
    const ObjTypes type; // Tipo do objeto
    static list<Object*> objects; // Lista estática de apontadores para objetos

public:
    // Construtor da classe Object
    Object(size_t width, size_t height, Size_TXY coords, ObjTypes type);
    Size_TXY getCoords(); // Método para obter as coordenadas do objeto
    ObjTypes getType(); // Método para obter o tipo do objeto
};

