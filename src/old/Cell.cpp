//#include "DxLib.h"
//#include "externs.h"
//#include "consts.h"
//#include "enums.h"
//#include "class.h"
//
//#include <valarray>
//
//using std::valarray;
//
//Cell::Cell() {
//	state = VACANT;
//	setPosition(-1, -1);
//	master_field = nullptr;
//	master_piece = nullptr;
//	upper = nullptr;
//	righter = nullptr;
//	downer = nullptr;
//	lefter = nullptr;
//	VanishScheduledFlag = false;
//}
//
//void Cell::draw(int draw_pos_pxl_x, int draw_pos_pxl_y) {
//	draw_pos_pxl_x += PIYO_POS_OFFSET;
//	draw_pos_pxl_y += PIYO_POS_OFFSET;
//
//	switch (state) {
//	case VACANT:
//		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_vacant, TRUE);
//		break;
//	case BLUE:
//		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_blue, TRUE);
//		break;
//	case GREEN:
//		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_green, TRUE);
//		break;
//	case PURPLE:
//		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_purple, TRUE);
//		break;
//	case RED:
//		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_red, TRUE);
//		break;
//	case YELLOW:
//		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PIYO_SIZE_EXTRATE, 0, hImg_yellow, TRUE);
//		break;
//	case OUTSIDE:
//		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_outside, TRUE);
//		break;
//	}
//}
//
//void Cell::setRandomState() {
//	int Number = GetRand(4) + 1;
//	switch (Number) {
//	case 0:
//		state = VACANT;
//		break;
//	case 1:
//		state = BLUE;
//		break;
//	case 2:
//		state = GREEN;
//		break;
//	case 3:
//		state = PURPLE;
//		break;
//	case 4:
//		state = RED;
//		break;
//	case 5:
//		state = YELLOW;
//		break;
//	case 6:
//		state = OJAMA;
//		break;
//	case 7:
//		state = OUTSIDE;
//		break;
//	}
//}
//
//void Cell::setPosition(int given_x, int given_y) {
//	valarray<int> newPosition = { given_x, given_y };
//	Position = newPosition;
//}
//
//void Cell::setPosition(valarray<int> givenPosition) {
//	Position = givenPosition;
//}
//
//void Cell::setPosition(valarray<int> basePosition, Direction given_direction) {
//	switch (given_direction) {
//	case UP:
//		Position = basePosition + upward;
//		break;
//	case RIGHT:
//		Position = basePosition + rightward;
//		break;
//	case DOWN:
//		Position = basePosition + downward;
//		break;
//	case LEFT:
//		Position = basePosition + leftward;
//		break;
//	}
//}
//
//void Cell::setSurrounder(valarray<int> givenPosition) {
//	upper = master_piece->master_field->getCellptr(givenPosition + upward);
//	righter = master_piece->master_field->getCellptr(givenPosition + rightward);
//	downer = master_piece->master_field->getCellptr(givenPosition + downward);
//	lefter = master_piece->master_field->getCellptr(givenPosition + leftward);
//}