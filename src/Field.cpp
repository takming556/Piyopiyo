#include <new>
#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"


//Field::Field() : cellcontainer(FIELD_WIDTH, vector<FCell>(FIELD_HEIGHT)) {
//	for (int width = 0; width < FIELD_WIDTH; width++) {
//		for (int height = 0; height < FIELD_HEIGHT; height++) {
//			cellcontainer[width][height].state = initFieldCellState[width][height];
//			cellcontainer[width][height].setPosition(width, height);
//
//			cellcontainer[width][height].master_field = this;
//
//			if (height == 0) cellcontainer[width][height].upper = nullptr;
//			else cellcontainer[width][height].upper = &cellcontainer[width][height - 1];
//
//			if (width == FIELD_WIDTH - 1) cellcontainer[width][height].righter = nullptr;
//			else cellcontainer[width][height].righter = &cellcontainer[width + 1][height];
//
//			if (height == FIELD_HEIGHT - 1) cellcontainer[width][height].downer = nullptr;
//			else cellcontainer[width][height].downer = &cellcontainer[width][height - 1];
//
//			if (width == 0) cellcontainer[width][height].lefter = nullptr;
//			else cellcontainer[width][height].lefter = &cellcontainer[width - 1][height];
//		}
//	}
//}

Field::Field() {
	//2ŽŸŒ³”z—ñcellcontainer‚ð“®“IŠm•Û
	cellcontainer = new FCell * [FIELD_WIDTH];
	for (int i = 0; i < FIELD_WIDTH; ++i) {
		cellcontainer[i] = new FCell[FIELD_HEIGHT];
	}

	for (int width = 0; width < FIELD_WIDTH; width++) {
		for (int height = 0; height < FIELD_HEIGHT; height++) {
			FCell** memptr = &(&cellcontainer[width])[height];
			new(memptr) FCell(this);
			cellcontainer[width][height].state = initFieldCellState[width][height];
			cellcontainer[width][height].setPosition(width, height);

			cellcontainer[width][height].master_field = this;

			if (height == 0) cellcontainer[width][height].upper = nullptr;
			else cellcontainer[width][height].upper = &cellcontainer[width][height - 1];

			if (width == FIELD_WIDTH - 1) cellcontainer[width][height].righter = nullptr;
			else cellcontainer[width][height].righter = &cellcontainer[width + 1][height];

			if (height == FIELD_HEIGHT - 1) cellcontainer[width][height].downer = nullptr;
			else cellcontainer[width][height].downer = &cellcontainer[width][height - 1];

			if (width == 0) cellcontainer[width][height].lefter = nullptr;
			else cellcontainer[width][height].lefter = &cellcontainer[width - 1][height];
		}
	}
}


void Field::draw() {
	int draw_pos_x;
	int draw_pos_y;
	for (unsigned int y = 0; y < FIELD_HEIGHT; y++) {
		for (unsigned int x = 0; x < FIELD_WIDTH; x++) {
			draw_pos_x = FIELD_POS_PXL_X + CELL_WIDTH * x;
			draw_pos_y = FIELD_POS_PXL_Y + CELL_WIDTH * y;
			cellcontainer[x][y].draw(draw_pos_x, draw_pos_y);
		}
	}
}

FCell* Field::getFCellptr(valarray<int> givenPosition) {
	int given_x = givenPosition[0];
	int given_y = givenPosition[1];
	return &cellcontainer[given_x][given_y];
}