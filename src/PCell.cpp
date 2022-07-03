#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

#include <valarray>

using std::valarray;

PCell::PCell(Piece* given_master_piece_ptr) {
	master_piece = given_master_piece_ptr;
	setRandomState();
	setPosition(-1, -1);
}

//PCell::PCell() {
//	setRandomState();
//}

void PCell::draw(int draw_pos_pxl_x, int draw_pos_pxl_y) {
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

void PCell::setRandomState() {
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

void PCell::setPosition(int given_x, int given_y) {
	valarray<int> newPosition = { given_x, given_y };
	Position = newPosition;
}

void PCell::setPosition(valarray<int> givenPosition) {
	Position = givenPosition;
}

void PCell::setPosition(valarray<int> basePosition, Direction given_direction) {
	switch (given_direction) {
	case UP:
		Position = basePosition + upward;
		break;
	case RIGHT:
		Position = basePosition + rightward;
		break;
	case DOWN:
		Position = basePosition + downward;
		break;
	case LEFT:
		Position = basePosition + leftward;
		break;
	}
}

void PCell::setSurrounder(valarray<int> givenPosition) {
	upper = master_piece->master_field->getFCellptr(givenPosition + upward);
	righter = master_piece->master_field->getFCellptr(givenPosition + rightward);
	downer = master_piece->master_field->getFCellptr(givenPosition + downward);
	lefter = master_piece->master_field->getFCellptr(givenPosition + leftward);
}