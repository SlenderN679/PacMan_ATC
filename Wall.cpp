#include "Wall.h"
list<Wall*> Wall::walls;
Wall::Wall(size_t width, size_t height, Size_TXY coords) : StaticObject(width, height, coords, WALL_O) {
	//walls.push_back(this);
	for (size_t x = coords.x; x < coords.x + width; x++) {
		for (size_t y = coords.y; y < coords.y + height; y++) {
			Map::addWall({x,y});
		}
	}
}
Wall::Wall(Size_TXY coords) : StaticObject(1, 1 , coords, WALL_O) {
}
void Wall::CreateWalls() {
	walls.push_back(new Wall(4, 3, { 2,5 }));
	walls.push_back(new Wall(5, 3, { 7,5 }));
	walls.push_back(new Wall(2, 4, { 13,4 }));
	walls.push_back(new Wall(5, 3, { 16,5 }));
	walls.push_back(new Wall(4, 3, { 22,5 }));
	//---
	walls.push_back(new Wall(4, 2, { 2,9 }));
	walls.push_back(new Wall(2, 8, { 7,9 }));
	walls.push_back(new Wall(8, 2, { 10,9 }));
	walls.push_back(new Wall(2, 8, { 19,9 }));
	walls.push_back(new Wall(4, 2, { 22,9 }));
	//---
	walls.push_back(new Wall(5, 1, { 1,12 }));
	walls.push_back(new Wall(3, 2, { 9,12 }));
	walls.push_back(new Wall(2, 3, { 13,11 }));
	walls.push_back(new Wall(3, 2, { 16,12 }));
	walls.push_back(new Wall(5, 1, { 22,12 }));
	//---
	walls.push_back(new Wall(1, 3, { 5,13 }));
	walls.push_back(new Wall(3, 1, { 10,15 }));
	walls.push_back(new Wall(3, 1, { 15,15 }));
	walls.push_back(new Wall(1, 3, { 22,13 }));
	//---
	walls.push_back(new Wall(6, 1, { 0,16 }));
	walls.push_back(new Wall(1, 3, { 10,16 }));
	walls.push_back(new Wall(1, 3, { 17,16 }));
	walls.push_back(new Wall(6, 1, { 22,16 }));
	//---
	walls.push_back(new Wall(6, 1, { 0,18 }));
	walls.push_back(new Wall(2, 5, { 7,18 }));
	walls.push_back(new Wall(8, 1, { 10,19 }));
	walls.push_back(new Wall(2, 5, { 19,18 }));
	walls.push_back(new Wall(6, 1, { 22,18 }));
	//---
	walls.push_back(new Wall(1, 3, { 5,19 }));
	walls.push_back(new Wall(8, 2, { 10,21 }));
	walls.push_back(new Wall(1, 3, { 22,19 }));
	//---
	walls.push_back(new Wall(5, 1, { 1,22 }));
	walls.push_back(new Wall(5, 1, { 22,22 }));
	//---
	walls.push_back(new Wall(4, 2, { 2,24 }));
	walls.push_back(new Wall(5, 2, { 7,24 }));
	walls.push_back(new Wall(2, 3, { 13,23 }));
	walls.push_back(new Wall(5, 2, { 16,24 }));
	walls.push_back(new Wall(4, 2, { 22,24 }));
	//---
	walls.push_back(new Wall(2, 2, { 1,27 }));
	walls.push_back(new Wall(2, 3, { 4,26 }));
	walls.push_back(new Wall(2, 3, { 7,27 }));
	walls.push_back(new Wall(8, 2, { 10,27 }));
	walls.push_back(new Wall(2, 3, { 19,27 }));
	walls.push_back(new Wall(2, 3, { 22,26 }));
	walls.push_back(new Wall(2, 2, { 25,27 }));
	//---
	walls.push_back(new Wall(10, 2, { 2,30 }));
	walls.push_back(new Wall(2, 3, { 13,29 }));
	walls.push_back(new Wall(10, 2, { 16,30 }));
	//---

    //Wall w1(4, 3, { 2,5 });
    //Wall w2(5, 3, { 7,5 });
    //Wall w3(2, 4, { 13,4 });
    //Wall w4(5, 3, { 16,5 });
    //Wall w5(4, 3, { 22,5 });
    ////---
    //Wall w6(4, 2, { 2,9 });
    //Wall w7(2, 8, { 7,9 });
    //Wall w8(8, 2, { 10,9 });
    //Wall w9(2, 8, { 19,9 });
    //Wall w10(4, 2, { 22,9 });
    ////---
    //Wall w11(5, 1, { 1,12 });
    //Wall w12(3, 2, { 9,12 });
    //Wall w13(2, 3, { 13,11 });
    //Wall w14(3, 2, { 16,12 });
    //Wall w15(5, 1, { 22,12 });
    ////---
    //Wall w16(1, 3, { 5,13 });
    //Wall w17(3, 1, { 10,15 });
    //Wall w18(3, 1, { 15,15 });
    //Wall w19(1, 3, { 22,13 });
    ////---
    //Wall w20(6, 1, { 0,16 });
    //Wall w21(1, 3, { 10,16 });
    //Wall w22(1, 3, { 17,16 });
    //Wall w23(6, 1, { 22,16 });
    ////---
    //Wall w24(6, 1, { 0,18 });
    //Wall w25(2, 5, { 7,18 });
    //Wall w26(8, 1, { 10,19 });
    //Wall w27(2, 5, { 19,18 });
    //Wall w28(6, 1, { 22,18 });
    ////---
    //Wall w29(1, 3, { 5,19 });
    //Wall w30(8, 2, { 10,21 });
    //Wall w31(1, 3, { 22,19 });
    ////---
    //Wall w32(5, 1, { 1,22 });
    //Wall w33(5, 1, { 22,22 });
    ////---
    //Wall w34(4, 2, { 2,24 });
    //Wall w35(5, 2, { 7,24 });
    //Wall w36(2, 3, { 13,23 });
    //Wall w37(5, 2, { 16,24 });
    //Wall w38(4, 2, { 22,24 });
    ////---
    //Wall w39(2, 2, { 1,27 });
    //Wall w40(2, 3, { 4,26 });
    //Wall w41(2, 3, { 7,27 });
    //Wall w42(8, 2, { 10,27 });
    //Wall w43(2, 3, { 19,27 });
    //Wall w44(2, 3, { 22,26 });
    //Wall w45(2, 2, { 25,27 });
    ////---
    //Wall w46(10, 2, { 2,30 });
    //Wall w47(2, 3, { 13,29 });
    //Wall w48(10, 2, { 16,30 });
}//por em ficheiro separado
void Wall::CreateWall(Size_TXY coords) {
	walls.push_back(new Wall(coords));
} 