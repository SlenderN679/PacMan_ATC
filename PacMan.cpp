#include "PacMan.h" // Inclui a definição da classe PacMan

Size_TXY pacmanStart = { 14, 26 }; // Define a posição inicial do PacMan

PacMan::PacMan() : Entity(pacmanStart, PACMAN_E) { // Construtor da classe PacMan que inicializa os membros da classe base Entity
    
    direction = RIGHT; // Define a direção inicial do PacMan como direita
    
    lives = 3; // Define o número inicial de vidas do PacMan
    
    score = 0; // Define a pontuação inicial do PacMan
    
    Map::addPacman(pacmanStart); // Adiciona o PacMan ao mapa na posição inicial
    
}

// Método para mover o PacMan
void PacMan::move() {

	switch (direction) { // Verifica a direção atual do PacMan

	case UP: // Se a direção for para cima
        if (Map::getCell({ Position().x, Position().y - 1 }) != WALL) { // Verifica se a célula acima não é uma parede
            
            Map::clearCell(Position()); // Limpa a célula atual do mapa
            
            Entity::move({ 0, -1 }); // Move o PacMan para cima
            
            Map::addPacman(Position()); // Adiciona o PacMan na nova posição no mapa
            
        }
        break;

    case DOWN: // Se a direção for para baixo
        if (Map::getCell({ Position().x, Position().y + 1 }) != WALL) { // Verifica se a célula abaixo não é uma parede
            
            Map::clearCell(Position());  // Limpa a célula atual do mapa
           
            Entity::move({ 0, 1 }); // Move o PacMan para baixo
            
            Map::addPacman(Position()); // Adiciona o PacMan na nova posição no mapa
            
        }
        break;

	case LEFT: // Se a direção for para a esquerda
        if (Map::getCell({ Position().x - 1, Position().y }) == PORTAL) { // Verifica se a célula à esquerda é um portal
            
            Map::clearCell(Position()); // Limpa a célula atual do mapa
            
            Entity::move({ 25, 0 }); // Move o PacMan para o outro lado do portal
            
            Map::addPacman(Position()); // Adiciona o PacMan na nova posição no mapa
            
        }
        else if (Map::getCell({ Position().x - 1, Position().y }) != WALL) { // Verifica se a célula à esquerda não é uma parede
            
            Map::clearCell(Position()); // Limpa a célula atual do mapa
            
            Entity::move({ -1, 0 }); // Move o PacMan para a esquerda
            
            Map::addPacman(Position()); // Adiciona o PacMan na nova posição no mapa
            
        }
        break;
	case RIGHT: // Se a direção for para a direita
        if (Map::getCell({ Position().x + 1, Position().y }) == PORTAL) { // Verifica se a célula à direita é um portal
            
            Map::clearCell(Position()); // Limpa a célula atual do mapa
            
            Entity::move({ -25, 0 }); // Move o PacMan para o outro lado do portal
            
            Map::addPacman(Position()); // Adiciona o PacMan na nova posição no mapa
            
        }
        else if (Map::getCell({ Position().x + 1, Position().y }) != WALL) { // Verifica se a célula à direita não é uma parede
            
            Map::clearCell(Position()); // Limpa a célula atual do mapa
            
            Entity::move({ 1, 0 }); // Move o PacMan para a direita
            
            Map::addPacman(Position());  // Adiciona o PacMan na nova posição no mapa
           
        }
        break;
    }
}

// Método para mudar a direção do PacMan
void PacMan::turn(Directions direction) {

    this->direction = direction; // Atualiza a direção do PacMan
    
}