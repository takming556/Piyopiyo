#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

GameSession::GameSession() :
	piece(nullptr),
	is_down_key_pushed(false),
	is_right_key_pushed(false),
	is_left_key_pushed(false),
	is_z_key_pushed(false),
	is_x_key_pushed(false),
	is_game_over(false),
	piyo_drop_freq(1.0)
{
	clock_keeper = GetNowCount();
	next_piece.set_randomly();
	piece = new Piece(field, next_piece.get_inner_state(), next_piece.get_outer_state());
	next_piece.set_randomly();
}


void GameSession::patrol() {
	DrawGraph(0, 0, hImg_background, TRUE); //背景画像を表示
	field.draw();
	piece->draw();
	next_piece.draw();
	DrawFormatString(0, 740, GetColor(255, 255, 0), "←→でぴよ移動　Zで左回転　Xで右回転");
	deal_keyinput();
	deal_clockkeeper();
}


void GameSession::deal_clockkeeper() {
	float piyodropwait = 1.0 / piyo_drop_freq;
	if (GetNowCount() >= clock_keeper + piyodropwait * 1000) {
		clock_keeper = GetNowCount();
		if (check_piece_landing() == true) {
			copy_piece_to_field();
			update_piece();
		}
		else {
			piece->drop_onestep();
		}
	}
}


void GameSession::deal_keyinput() {
	char keybuf[256];
	GetHitKeyStateAll(keybuf);

	//Zキー
	if (is_z_key_pushed == false && keybuf[KEY_INPUT_Z] == 1) {
		is_z_key_pushed = true;
		piece->rotate_counterclockwise();
	}
	else if (is_z_key_pushed == true && keybuf[KEY_INPUT_Z] == 0) {
		is_z_key_pushed = false;
	}

	//Xキー
	if (is_x_key_pushed == false && keybuf[KEY_INPUT_X] == 1) {
		is_x_key_pushed = true;
		piece->rotate_forwardclockwise();
	}
	else if (is_x_key_pushed == true && keybuf[KEY_INPUT_X] == 0) {
		is_x_key_pushed = false;
	}

	//左矢印キー
	if (is_left_key_pushed == false && keybuf[KEY_INPUT_LEFT] == 1) {
		is_left_key_pushed = true;
		piece->consider_move_left();
	}
	else if (is_left_key_pushed == true && keybuf[KEY_INPUT_LEFT] == 0) {
		is_left_key_pushed = false;
	}

	//右矢印キー
	if (is_right_key_pushed == false && keybuf[KEY_INPUT_RIGHT] == 1) {
		is_right_key_pushed = true;
		piece->consider_move_right();
	}
	else if (is_right_key_pushed == true && keybuf[KEY_INPUT_RIGHT] == 0) {
		is_right_key_pushed = false;
	}
}


bool GameSession::check_piece_landing() {
	if (piece->get_inner().get_downer_fcell().get_state() != VACANT || piece->get_outer().get_downer_fcell().get_state() != VACANT) {
		return true;
	}
	else {
		return false;
	}
}


void GameSession::copy_piece_to_field() {
	Fcell& inner_standing_fcell = field.get_fcell(piece->get_inner().get_position());
	Fcell& outer_standing_fcell = field.get_fcell(piece->get_outer().get_position());
	inner_standing_fcell.set_state(piece->get_inner().get_state());
	outer_standing_fcell.set_state(piece->get_outer().get_state());
}


void GameSession::update_piece() {
	delete piece;
	piece = new Piece(field, next_piece.get_inner_state(), next_piece.get_outer_state());
	next_piece.set_randomly();
}