#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"


Field::Field() : cellcontainer(FIELD_WIDTH, vector<Cell>(FIELD_HEIGHT)) {
	//int address_offset;
	for (int width = 0; width < FIELD_WIDTH; width++) {
		for (int height = 0; height < FIELD_HEIGHT; height++) {
			cellcontainer[width][height].setState(initFieldState[width][height]);
		}
	}
}

void Field::draw() {
	int draw_pos_x;
	int draw_pos_y;
	for (char y = 0; y < FIELD_HEIGHT; y++) {
		for (char x = 0; x < FIELD_WIDTH; x++) {
			draw_pos_x = FIELD_POS_PXL_X + CELL_WIDTH * x;
			draw_pos_y = FIELD_POS_PXL_Y + CELL_WIDTH * y;
			cellcontainer[x][y].draw(draw_pos_x, draw_pos_y);
		}
	}
}