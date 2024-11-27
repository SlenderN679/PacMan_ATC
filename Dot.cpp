#include "Dot.h" // Inclui a definição da classe Dot

list<Dot*> Dot::dots; // Inicializa a lista estática de apontadores para objetos Dot

// Construtor da classe Dot que inicializa os membros da classe base Entity
Dot::Dot(Size_TXY pos, EntTypes type) : Entity(pos, type) {
    
    dots.push_back(this); // Adiciona o novo objeto dots à lista estática de pontos
    
}

// Método estático para verificar a grade
bool Dot::Grid() {
	for (size_t y = 4; y < 33; y++) { // Loop para percorrer as linhas do mapa
		for (size_t x = 1; x < 27; x++) { // Loop para percorrer as colunas do mapa
            if (Map::getCell({ x, y }) == SPACE) { // Verifica se a célula no mapa está vazia
                
                if ((x == 1 || x == 26) && (y == 6 || y == 26)) { // Verifica se a posição é uma das posições especiais para bytes
                    
                    Dot* dot = new Dot({ x, y }, BYTE_E); // Cria um novo objeto Dot do tipo BYTE_E (dot)
                    
                    Map::addByte({ x, y }); // Adiciona o byte ao mapa
                    
                    if (dot == nullptr) {

                        return false; // Retorna false se a alocação de memória falhar
                    }
                }
                else {

                    Dot* dot = new Dot({ x, y }, BIT_E); // Cria um novo objeto Dot do tipo BIT_E (dot)
                    
                    Map::addBit({ x, y }); // Adiciona o bit ao mapa
                    
                    if (dot == nullptr) {

                        return false; // Retorna false se a alocação de memória falhar  
                    }
                }
            }
        }
    }
    return true;// Retorna true se todos os pontos forem adicionados com sucesso
    
}