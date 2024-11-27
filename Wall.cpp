#include "Wall.h" // Inclui a definição da classe Wall

list<Wall> Wall::walls; // Inicializa a lista estática de objetos Wall

// Construtor da classe Wall que inicializa os membros da classe base Object
Wall::Wall(size_t width, size_t height, Size_TXY coords) : Object(width, height, coords, WALL_O) {
    
    walls.push_back(*this); // Adiciona o novo objeto Wall à lista estática de paredes
    
	for (size_t x = coords.x; x < coords.x + width; x++) { // Loop para percorrer a largura da parede

		for (size_t y = coords.y; y < coords.y + height; y++) { // Loop para percorrer a altura da parede

            Map::addWall({ x, y }); // Adiciona cada célula da parede ao mapa
            
        }
    }
}