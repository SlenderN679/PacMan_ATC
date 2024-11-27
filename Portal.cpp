#include "Portal.h" // Inclui a definição da classe Portal

list<Portal> Portal::portals; // Inicializa a lista estática de objetos Portal

// Construtor da classe Portal que inicializa os membros da classe base Object e o membro side
Portal::Portal(float width, float height, Size_TXY coords, ObjTypes type, Sides side) : Object(width, height, coords, type), side(side) {
    
    portals.push_back(*this); // Adiciona o novo objeto portals à lista estática de portais
    
}