#include <iostream> // Inclui a biblioteca de entrada e saída padrão

#include <windows.h> // Inclui a biblioteca para funções específicas do Windows

#include <chrono> // Inclui a biblioteca para manipulação do tempo

#include <thread> // Inclui a biblioteca para manipulação de threads

#include "Map.h" // Inclui a definição da classe Map

#include "PacMan.h" // Inclui a definição da classe PacMan

using namespace std; // Usa o namespace std para evitar prefixar std::

Map map; // Cria uma instância do mapa

PacMan pacman; // Cria uma instância do PacMan

// Função para criar as paredes do labirinto
void walls() { 
    Wall w1(4, 3, { 2, 5 });
    Wall w2(5, 3, { 7, 5 });
    Wall w3(2, 4, { 13, 4 });
    Wall w4(5, 3, { 16, 5 });
    Wall w5(4, 3, { 22, 5 });
    //---
    Wall w6(4, 2, { 2, 9 });
    Wall w7(2, 8, { 7, 9 });
    Wall w8(8, 2, { 10, 9 });
    Wall w9(2, 8, { 19, 9 });
    Wall w10(4, 2, { 22, 9 });
    //---
    Wall w11(5, 1, { 1, 12 });
    Wall w12(3, 2, { 9, 12 });
    Wall w13(2, 3, { 13, 11 });
    Wall w14(3, 2, { 16, 12 });
    Wall w15(5, 1, { 22, 12 });
    //---
    Wall w16(1, 3, { 5, 13 });
    Wall w17(3, 1, { 10, 15 });
    Wall w18(3, 1, { 15, 15 });
    Wall w19(1, 3, { 22, 13 });
    //---
    Wall w20(6, 1, { 0, 16 });
    Wall w21(1, 3, { 10, 16 });
    Wall w22(1, 3, { 17, 16 });
    Wall w23(6, 1, { 22, 16 });
    //---
    Wall w24(6, 1, { 0, 18 });
    Wall w25(2, 5, { 7, 18 });
    Wall w26(8, 1, { 10, 19 });
    Wall w27(2, 5, { 19, 18 });
    Wall w28(6, 1, { 22, 18 });
    //---
    Wall w29(1, 3, { 5, 19 });
    Wall w30(8, 2, { 10, 21 });
    Wall w31(1, 3, { 22, 19 });
    //---
    Wall w32(5, 1, { 1, 22 });
    Wall w33(5, 1, { 22, 22 });
    //---
    Wall w34(4, 2, { 2, 24 });
    Wall w35(5, 2, { 7, 24 });
    Wall w36(2, 3, { 13, 23 });
    Wall w37(5, 2, { 16, 24 });
    Wall w38(4, 2, { 22, 24 });
    //---
    Wall w39(2, 2, { 1, 27 });
    Wall w40(2, 3, { 4, 26 });
    Wall w41(2, 3, { 7, 27 });
    Wall w42(8, 2, { 10, 27 });
    Wall w43(2, 3, { 19, 27 });
    Wall w44(2, 3, { 22, 26 });
    Wall w45(2, 2, { 25, 27 });
    //---
    Wall w46(10, 2, { 2, 30 });
    Wall w47(2, 3, { 13, 29 });
    Wall w48(10, 2, { 16, 30 });
}

// Função para processar a entrada do utilizador
void processInput() {
  
	while (true) { // Loop infinito para verificar a entrada do utilizador
		if (GetAsyncKeyState(VK_UP) & 0x8000) { // Verifica se a tecla de seta para cima foi pressionada

            pacman.turn(UP); // Muda a direção do PacMan para cima
            
        }
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // Verifica se a tecla de seta para baixo foi pressionada

            pacman.turn(DOWN); // Muda a direção do PacMan para baixo
            
        }
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) { // Verifica se a tecla de seta para a esquerda foi pressionada

            pacman.turn(LEFT); // Muda a direção do PacMan para a esquerda
            
        }
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { // Verifica se a tecla de seta para a direita foi pressionada

            pacman.turn(RIGHT); // Muda a direção do PacMan para a direita
            
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Espera por 50 milissegundos antes de verificar novamente
       
    }
}

int main() {
    walls(); // Cria as paredes do labirinto
    
    Dot::Grid(); // Adiciona os pontos ao labirinto
    
    map.addGhost({ 5, 9 }); // Adiciona um fantasma ao mapa
    
    map.addWall({ 13, 10 }); // Adiciona uma parede ao mapa
    
	//map.addByte({ 4, 1 }); // Adiciona um byte ao mapa
	//map.addBit({ 17, 20 }); // Adiciona um bit ao mapa

    map.addPortal({ 0, 17 }); // Adiciona um portal ao mapa
    
    map.addPortal({ 27, 17 }); // Adiciona outro portal ao mapa
    
    map.drawMap(); // Desenha o mapa na consola
    
    std::thread inputThread(processInput); // Cria uma thread para processar a entrada do utilizador
    
    this_thread::sleep_for(chrono::milliseconds(1000)); // Espera por 1 segundo antes de iniciar o loop principal
    
	while (true) { // Loop infinito para mover o PacMan e desenhar o mapa
        pacman.move(); // Move o PacMan
        
        map.drawMap(); // Desenha o mapa na consola
        
        this_thread::sleep_for(chrono::milliseconds(250)); // Espera por 250 milissegundos antes de repetir o loop
        
    }
    inputThread.join(); // Aguarda até a thread de entrada terminar (nunca acontece neste caso)
    
    return 0;
}

/*
wall -> 178
byte -> 233
bit -> 248
Pacman -> 67
ghost -> 234
*/