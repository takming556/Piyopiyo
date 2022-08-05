#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

#include <valarray>

using std::valarray;

//FCell::FCell(Field* given_master_field_ptr) {
//	master_field = given_master_field_ptr;
//	state = VACANT;
//	setPosition(-1, -1);
//	master_field = given_master_field_ptr;
//	upper = nullptr;
//	righter = nullptr;
//	downer = nullptr;
//	lefter = nullptr;
//	VanishScheduledFlag = false;
//}

FCell::FCell() {
	state = VACANT;
	setPosition(-1, -1);
	VanishScheduledFlag = false;
}

void FCell::draw(int draw_pos_pxl_x, int draw_pos_pxl_y) {
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

void FCell::setPosition(int given_x, int given_y) {
	valarray<int> newPosition = { given_x, given_y };
	Position = newPosition;
}
void FCell::setSurrounder(valarray<int> givenPosition) {
	if (givenPosition[Dimension::Y] == 0)upper = nullptr;
	else upper = master_field->getFCellptr(givenPosition + upward);

	if (givenPosition[Dimension::X] == FIELD_WIDTH - 1)righter = nullptr;
	else righter = master_field->getFCellptr(givenPosition + rightward);

	if (givenPosition[Dimension::Y] == FIELD_HEIGHT - 1)downer = nullptr;
	else downer = master_field->getFCellptr(givenPosition + downward);

	if (givenPosition[Dimension::X] == 0)lefter = nullptr;
	else lefter = master_field->getFCellptr(givenPosition + leftward);

	//upper = master_field->getFCellptr(givenPosition + upward);
	//righter = master_field->getFCellptr(givenPosition + rightward);
	//downer = master_field->getFCellptr(givenPosition + downward);
	//lefter = master_field->getFCellptr(givenPosition + leftward);
}