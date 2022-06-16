#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

Cell::Cell() {
	state = VACANT;
	VanishScheduledFlag = false;
}

Cell::Cell(enum State init_state) {
	state = init_state;
	VanishScheduledFlag = false;
}

void Cell::draw(int draw_pos_pxl_x, int draw_pos_pxl_y) {
	draw_pos_pxl_x += PIYO_POS_OFFSET;
	draw_pos_pxl_y += PIYO_POS_OFFSET;

	switch (state) {
	case VACANT:
		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_vacant, TRUE);
		break;
	case BLUE:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_blue, TRUE);
		break;
	case GREEN:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_green, TRUE);
		break;
	case PURPLE:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_purple, TRUE);
		break;
	case RED:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_red, TRUE);
		break;
	case YELLOW:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_yellow, TRUE);
		break;
	case OUTSIDE:
		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_outside, TRUE);
		break;
	}
}

void Cell::setState(enum State given_state) {
	state = given_state;
}

void Cell::setRandomState() {
	int Number = GetRand(4) + 1;
	switch (Number) {
	case 0:
		state = VACANT;
		break;
	case 1:
		state = BLUE;
		break;
	case 2:
		state = GREEN;
		break;
	case 3:
		state = PURPLE;
		break;
	case 4:
		state = RED;
		break;
	case 5:
		state = YELLOW;
		break;
	case 6:
		state = OJAMA;
		break;
	case 7:
		state = OUTSIDE;
		break;
	}
}
