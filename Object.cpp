#include "Object.h" // Inclui a definição da classe Object

list<Object*> Object::objects; // Inicializa a lista estática de apontadores para objetos Object

// Construtor da classe Object que inicializa os membros width, height, coords e type
Object::Object(size_t width, size_t height, Size_TXY coords, ObjTypes type) : width(width), height(height), coords(coords), type(type) {
    
    objects.push_back(this); // Adiciona o novo objeto objects à lista estática de objetos
    
}

// Método para obter as coordenadas do objeto
Size_TXY Object::getCoords() {

    return coords; // Retorna as coordenadas do objeto
    
}

// Método para obter o tipo do objeto
ObjTypes Object::getType() {

    return type; // Retorna o tipo do objeto
    
}