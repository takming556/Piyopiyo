#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

GameSession::GameSession() {
	clockkeeper = GetNowCount();
	piyodropfreq = 1.0;
	PieceLandingFlag = false;
}

void GameSession::patrol() {
	DrawGraph(0, 0, hImg_background, TRUE); //背景画像を表示
	DrawGraph(144, 96, hImg_field, FALSE);  //ゲームフィールドの画像を表示
	DrawGraph(NEXTPIYO_POS_PXL_X, NEXTPIYO_POS_PXL_Y, hImg_nextframe, FALSE); //Nextぴよピース枠を表示
	DrawFormatString(0, 740, GetColor(255, 255, 0), "←→でぴよ移動　Zで左回転　Xで右回転");
	field.draw();
	piece.draw();
	deal_keyinput();
	deal_clockkeeper();
}

void GameSession::deal_clockkeeper() {
	float piyodropwait = 1.0 / piyodropfreq;
	if (GetNowCount() >= clockkeeper + piyodropwait * 1000) {
		clockkeeper = GetNowCount();
		piece.drop_onestep();
	}
}

void GameSession::deal_keyinput() {
	char keybuf[256];
	GetHitKeyStateAll(keybuf);

	//Zキー
	if (KeyPushFlag_Z == false && keybuf[KEY_INPUT_Z] == 1) {
		KeyPushFlag_Z = true;
		piece.rotate_counterclockwise();
	}
	else if (KeyPushFlag_Z == true && keybuf[KEY_INPUT_Z] == 0) {
		KeyPushFlag_Z = false;
	}

	//Xキー
	if (KeyPushFlag_X == false && keybuf[KEY_INPUT_X] == 1) {
		KeyPushFlag_X = true;
		piece.rotate_forwardclockwise();
	}
	else if (KeyPushFlag_X == true && keybuf[KEY_INPUT_X] == 0) {
		KeyPushFlag_X = false;
	}

	//左矢印キー
	if (KeyPushFlag_Left == false && keybuf[KEY_INPUT_LEFT] == 1) {
		KeyPushFlag_Left = true;
		piece.move_left();
	}
	else if (KeyPushFlag_Left == true && keybuf[KEY_INPUT_LEFT] == 0) {
		KeyPushFlag_Left = false;
	}

	//右矢印キー
	if (KeyPushFlag_Right == false && keybuf[KEY_INPUT_RIGHT] == 1) {
		KeyPushFlag_Right = true;
		piece.move_right();
	}
	else if (KeyPushFlag_Right == true && keybuf[KEY_INPUT_RIGHT] == 0) {
		KeyPushFlag_Right = false;
	}
}

bool GameSession::check_Piece_landing() {
	
}