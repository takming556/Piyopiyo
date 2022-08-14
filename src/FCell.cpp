#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

#include <valarray>

using std::valarray;


Fcell::Fcell(Field& given_master_field, enum State initial_state, valarray<int> lying_position) :
	master_field(given_master_field),
	state(initial_state),
	position(lying_position)
{
}


void Fcell::set_state(enum State given_state) {
	state = given_state;
}


enum State Fcell::get_state() {
	return state;
}


Fcell& Fcell::get_upper() {
	return master_field.get_fcell(position + upward);
}


Fcell& Fcell::get_downer() {
	return master_field.get_fcell(position + downward);
}


Fcell& Fcell::get_righter() {
	return master_field.get_fcell(position + rightward);
}


Fcell& Fcell::get_lefter() {
	return master_field.get_fcell(position + leftward);
}


void Fcell::draw(int draw_pos_pxl_x, int draw_pos_pxl_y) {
	draw_pos_pxl_x += Pcell::PCELL_DRAWPOS_OFFSET;
	draw_pos_pxl_y += Pcell::PCELL_DRAWPOS_OFFSET;

	switch (state) {
	case VACANT:
		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_vacant, TRUE);
		break;
	case BLUE:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_blue, TRUE);
		break;
	case GREEN:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_green, TRUE);
		break;
	case PURPLE:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_purple, TRUE);
		break;
	case RED:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_red, TRUE);
		break;
	case YELLOW:
		DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_yellow, TRUE);
		break;
	case OUTSIDE:
		if (DebugFlag == true)DrawRotaGraph(draw_pos_pxl_x, draw_pos_pxl_y, 1.0, 0, hImg_outside, TRUE);
		break;
	}
}