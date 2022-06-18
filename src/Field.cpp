#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"


Field::Field() : cellcontainer(FIELD_WIDTH, vector<Cell>(FIELD_HEIGHT)) {
	for (unsigned int width = 0; width < FIELD_WIDTH; width++) {
		for (unsigned int height = 0; height < FIELD_HEIGHT; height++) {
			cellcontainer[width][height].state = initFieldCellState[width][height];
			cellcontainer[width][height].PositionX = width;
			cellcontainer[width][height].PositionY = height;
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