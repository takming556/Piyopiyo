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


Fcell& Field::get_fcell(unsigned int given_x, unsigned int given_y) {
	return fcell_matrix.at(given_x).at(given_y);
}


void Field::draw() {
	DrawGraph(FIELD_DRAWPOS_PXL_X, FIELD_DRAWPOS_PXL_Y, hImg_field, FALSE);  //ゲームフィールドの画像を表示
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			int draw_pos_x = FIELD_DRAWPOS_PXL_X + Fcell::FCELL_WIDTH * x;
			int draw_pos_y = FIELD_DRAWPOS_PXL_Y + Fcell::FCELL_WIDTH * y;
			fcell_matrix.at(x).at(y).draw(draw_pos_x, draw_pos_y);
		}
	}
}


void Field::drop_hoverings() {
	for (int y = FIELD_HEIGHT - 1; y >= 0; y--) {
		for (int x = 0; x <= FIELD_WIDTH - 1; x++) {
			if (get_fcell(x, y).get_state() == State::VACANT) continue;
			int i = y;
			while (true) {
				if (i >= FIELD_HEIGHT - 1) break;
				else if (get_fcell(x, i).get_state() != State::VACANT) break;
				i++;
			}
			enum State copied_state = get_fcell(x, y).get_state();
			get_fcell(x, y).set_state(State::VACANT);
			get_fcell(x, i).set_state(copied_state);
		}
	}
}