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
	for (char y = 0; y < FIELD_HEIGHT; y++) {
		for (char x = 0; x < FIELD_WIDTH; x++) {
			int draw_pos_x = FIELD_POS_PXL_X + CELL_WIDTH * x + PIYO_POS_OFFSET;
			int draw_pos_y = FIELD_POS_PXL_Y + CELL_WIDTH * y + PIYO_POS_OFFSET;
			switch (this->cellcontainer[x][y].state) {
			case VACANT:
				if (DebugFlag == true)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_vacant, TRUE);
				break;
			case BLUE:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_blue, TRUE);
				break;
			case GREEN:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_green, TRUE);
				break;
			case PURPLE:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_purple, TRUE);
				break;
			case RED:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_red, TRUE);
				break;
			case YELLOW:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_yellow, TRUE);
				break;
			case OUTSIDE:
				if (DebugFlag == true)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_outside, TRUE);
				break;
			}
		}
	}

}