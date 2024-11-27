#include "Entity.h" // Inclui a definição da classe Entity

list<Entity*> Entity::entities; // Inicializa a lista estática de apontadores para objetos Entity

bool Entity::rage = false; // Inicializa a variável estática rage como false

// Construtor da classe Entity que inicializa os membros coords e type
Entity::Entity(Size_TXY coords, EntTypes type) : coords(coords), type(type) {
    
    entities.push_back(this); // Adiciona o novo objeto entities à lista estática de entidades
    
}

bool Entity::move(IntXY dis) { // Método para mover a entidade

    coords = { coords.x + dis.x, coords.y + dis.y }; // Atualiza as coordenadas da entidade com base no deslocamento fornecido
    
    return true; // Retorna true para indicar que a entidade foi movida
}

Size_TXY Entity::Position() const { // Método para obter a posição da entidade

    return coords; // Retorna as coordenadas atuais da entidade
}

EntTypes Entity::Type() const { // Método para obter o tipo da entidade

    return type; // Retorna o tipo da entidade
}