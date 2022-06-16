#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

GameSession::GameSession() {
	clockkeeper = GetNowCount();
	piyodropfreq = 1.0;
}

void GameSession::patrol() {
	DrawGraph(0, 0, hImg_background, TRUE); //背景画像を表示
	DrawGraph(144, 96, hImg_field, FALSE);  //ゲームフィールドの画像を表示
	DrawGraph(NEXTPIYO_POS_PXL_X, NEXTPIYO_POS_PXL_Y, hImg_nextframe, FALSE); //Nextぴよピース枠を表示
	DrawFormatString(0, 740, GetColor(255, 255, 0), "←→でぴよ移動　Zで左回転　Xで右回転");
	field.draw();
	piece.draw();
	check_clockkeeper();
}

void GameSession::check_clockkeeper() {
	float piyodropwait = 1.0 / piyodropfreq;
	if (GetNowCount() >= clockkeeper + piyodropwait * 1000) {
		clockkeeper = GetNowCount();
		piece.drop_onestep();
	}
}