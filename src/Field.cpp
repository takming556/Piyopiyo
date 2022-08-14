#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"


Field::Field() {
	for (int x = 0; x < FIELD_WIDTH; x++) {
		vector<Fcell> v;
		for (int y = 0; y < FIELD_HEIGHT; y++) {
			valarray<int> pos{ x,y };
			Fcell fcell(*this, Fcell::INITIAL_FCELL_STATES[x][y], pos);
			v.push_back(fcell);
		}
		fcell_matrix.push_back(v);
	}
}


Fcell& Field::get_fcell(valarray<int> given_position) {
	return fcell_matrix.at(given_position[Dimension::X]).at(given_position[Dimension::Y]);
}


void Field::draw() {
	DrawGraph(144, 96, hImg_field, FALSE);  //ゲームフィールドの画像を表示
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			int draw_pos_x = FIELD_DRAWPOS_PXL_X + Fcell::FCELL_WIDTH * x;
			int draw_pos_y = FIELD_DRAWPOS_PXL_Y + Fcell::FCELL_WIDTH * y;
			fcell_matrix.at(x).at(y).draw(draw_pos_x, draw_pos_y);
		}
	}
}