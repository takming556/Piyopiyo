#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

SceneManager::SceneManager() {
	scene = TITLE;
}

void SceneManager::patrol() {
	switch (scene) {
	case TITLE:
		DrawRotaGraph(RES_SCR_X / 2 - 1, RES_SCR_Y / 2 - 1, 0.71, 0, hImg_title, TRUE);
		if (KeyPushFlag_Enter == false && CheckHitKey(KEY_INPUT_RETURN) == TRUE) {
			KeyPushFlag_Enter = true;
			game_session = initGame();
		}
		break;
	case GAME:
		game_session.patrol();
		break;
	}
}

GameSession SceneManager::initGame() {
	KeyPushFlag_Enter = false;
	scene = GAME;
	GameSession gs;
	return gs;
}