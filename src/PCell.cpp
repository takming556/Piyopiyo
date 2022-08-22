#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

#include <valarray>

using std::valarray;

Pcell::Pcell(Piece& given_master_piece, valarray<int> given_position, enum State given_state) :
	master_piece(given_master_piece),
	state(given_state),
	position(given_position)
{
}


void Pcell::set_state(enum State given_state) {
	state = given_state;
}


//void Pcell::set_state_randomly() {
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


void Pcell::set_position(int given_x, int given_y) {
	valarray<int> new_position = { given_x, given_y };
	position = new_position;
}


void Pcell::set_position(valarray<int> given_position) {
	position = given_position;
}


void Pcell::set_position(valarray<int> base_position, Direction given_direction) {
	switch (given_direction) {
	case UP:
		position = base_position + upward;
		break;
	case RIGHT:
		position = base_position + rightward;
		break;
	case DOWN:
		position = base_position + downward;
		break;
	case LEFT:
		position = base_position + leftward;
		break;
	}
}


enum State Pcell::get_state() {
	return state;
}


valarray<int> Pcell::get_position() {
	return position;
}


bool Pcell::is_upper_fcell_available() {
	return (position[Dimension::Y] > 0 && position[Dimension::Y] <= Field::FIELD_HEIGHT - 1) ? true : false;
}


bool Pcell::is_downer_fcell_available() {
	return (position[Dimension::Y] >= 0 && position[Dimension::Y] < Field::FIELD_HEIGHT - 1) ? true : false;
}


bool Pcell::is_righter_fcell_available() {
	return (position[Dimension::X] >= 0 && position[Dimension::X] < Field::FIELD_WIDTH - 1) ? true : false;
}


bool Pcell::is_lefter_fcell_available() {
	return (position[Dimension::X] > 0 && position[Dimension::X] <= Field::FIELD_WIDTH - 1) ? true : false;
}


bool Pcell::is_standing_position_in_range_field() {
	if (position[Dimension::X] < 0) return false;
	else if (position[Dimension::X] > Field::FIELD_WIDTH - 1) return false;
	else if (position[Dimension::Y] < 0)return false;
	else if (position[Dimension::Y] > Field::FIELD_HEIGHT - 1) return false;
	else return true;
}


Fcell& Pcell::get_upper_fcell() {
	return master_piece.get_master_field().get_fcell(position + upward);
}


Fcell& Pcell::get_downer_fcell() {
	return master_piece.get_master_field().get_fcell(position + downward);
}


Fcell& Pcell::get_righter_fcell() {
	return master_piece.get_master_field().get_fcell(position + rightward);
}


Fcell& Pcell::get_lefter_fcell() {
	return master_piece.get_master_field().get_fcell(position + leftward);
}


Fcell& Pcell::get_standing_fcell() {
	return master_piece.get_master_field().get_fcell(position);
}


void Pcell::draw(int draw_pos_pxl_x, int draw_pos_pxl_y) {
	draw_pos_pxl_x += PCELL_DRAWPOS_OFFSET;
	draw_pos_pxl_y += PCELL_DRAWPOS_OFFSET;

	switch (state) {
	case VACANT:
		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_vacant, TRUE);
		break;
	case BLUE:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PCELL_DRAWSIZE_EXTRATE, 0, hImg_blue, TRUE);
		break;
	case GREEN:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PCELL_DRAWSIZE_EXTRATE, 0, hImg_green, TRUE);
		break;
	case PURPLE:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PCELL_DRAWSIZE_EXTRATE, 0, hImg_purple, TRUE);
		break;
	case RED:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PCELL_DRAWSIZE_EXTRATE, 0, hImg_red, TRUE);
		break;
	case YELLOW:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, PCELL_DRAWSIZE_EXTRATE, 0, hImg_yellow, TRUE);
		break;
	case OUTSIDE:
		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_outside, TRUE);
		break;
	}
}