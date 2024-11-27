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

// Método para interagir com um Dot
void PacMan::dot(const Dot& d) {

    score += 10; //  Implementação da interação com um Dot. Exemplo: aumenta a pontuação
}

// Método para interagir com uma Wall
void PacMan::wall(const Wall& w) {
    // Implementação da interação com uma Wall
    // Exemplo: pode parar o movimento ou causar um efeito
}

// Método para interagir com um Ghost
void PacMan::ghost(const Ghost& g) {
    // Implementação da interação com um Ghost
	if (Entity::rage) { // Verifica se o PacMan está em modo "rage"
        score += 200; // Exemplo: aumenta a pontuação se em modo "rage"
    }
    else {
        lives--; // Exemplo: perde uma vida
    }
}

// Método para interagir com um Portal
void PacMan::portal(const Portal& p) {
    // Implementação da interação com um Portal
    // Exemplo: teletransporta o PacMan para outra posição
}

// Método para obter a direção atual do PacMan
Directions PacMan::getDirection() {
	return direction; // Retorna a direção atual do PacMan
}

// Método para obter o número de vidas do PacMan
int PacMan::getLives() {
	return lives; // Retorna o número de vidas atual do PacMan
}

// Método para obter a pontuação do PacMan
int PacMan::getScore() {
	return score; // Retorna a pontuação atual do PacMan
}