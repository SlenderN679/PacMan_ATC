#include "Wall.h"
list<Wall> Wall::walls;
Wall::Wall(size_t width, size_t height, Size_TXY coords) : Object(width, height, coords, WALL_O) {
	walls.push_back(*this);
	for (size_t x = coords.x; x < coords.x + width; x++) {
		for (size_t y = coords.y; y < coords.y + height; y++) {
			Map::addWall({x,y});
		}
	}
}
void Wall::CreateWalls() {
    Wall w1(4, 3, { 2,5 });
    Wall w2(5, 3, { 7,5 });
    Wall w3(2, 4, { 13,4 });
    Wall w4(5, 3, { 16,5 });
    Wall w5(4, 3, { 22,5 });
    //---
    Wall w6(4, 2, { 2,9 });
    Wall w7(2, 8, { 7,9 });
    Wall w8(8, 2, { 10,9 });
    Wall w9(2, 8, { 19,9 });
    Wall w10(4, 2, { 22,9 });
    //---
    Wall w11(5, 1, { 1,12 });
    Wall w12(3, 2, { 9,12 });
    Wall w13(2, 3, { 13,11 });
    Wall w14(3, 2, { 16,12 });
    Wall w15(5, 1, { 22,12 });
    //---
    Wall w16(1, 3, { 5,13 });
    Wall w17(3, 1, { 10,15 });
    Wall w18(3, 1, { 15,15 });
    Wall w19(1, 3, { 22,13 });
    //---
    Wall w20(6, 1, { 0,16 });
    Wall w21(1, 3, { 10,16 });
    Wall w22(1, 3, { 17,16 });
    Wall w23(6, 1, { 22,16 });
    //---
    Wall w24(6, 1, { 0,18 });
    Wall w25(2, 5, { 7,18 });
    Wall w26(8, 1, { 10,19 });
    Wall w27(2, 5, { 19,18 });
    Wall w28(6, 1, { 22,18 });
    //---
    Wall w29(1, 3, { 5,19 });
    Wall w30(8, 2, { 10,21 });
    Wall w31(1, 3, { 22,19 });
    //---
    Wall w32(5, 1, { 1,22 });
    Wall w33(5, 1, { 22,22 });
    //---
    Wall w34(4, 2, { 2,24 });
    Wall w35(5, 2, { 7,24 });
    Wall w36(2, 3, { 13,23 });
    Wall w37(5, 2, { 16,24 });
    Wall w38(4, 2, { 22,24 });
    //---
    Wall w39(2, 2, { 1,27 });
    Wall w40(2, 3, { 4,26 });
    Wall w41(2, 3, { 7,27 });
    Wall w42(8, 2, { 10,27 });
    Wall w43(2, 3, { 19,27 });
    Wall w44(2, 3, { 22,26 });
    Wall w45(2, 2, { 25,27 });
    //---
    Wall w46(10, 2, { 2,30 });
    Wall w47(2, 3, { 13,29 });
    Wall w48(10, 2, { 16,30 });
}//por em ficheiro separado