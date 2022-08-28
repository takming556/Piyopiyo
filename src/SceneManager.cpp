#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

SceneManager::SceneManager() :
	game_session(nullptr),
	scene(Scene::TITLE),
	is_enter_key_pushed(false)
{
}


SceneManager::~SceneManager() {
	delete game_session;
}


void SceneManager::patrol() {
	switch (scene) {
	case TITLE:
		DrawRotaGraph(SCREEN_RESOLUTION_X / 2 - 1, SCREEN_RESOLUTION_Y / 2 - 1, 0.71, 0, hImg_title, TRUE);
		if (is_enter_key_pushed == false && CheckHitKey(KEY_INPUT_RETURN) == TRUE) {
			is_enter_key_pushed = true;
			initialize_scene_game();
		}
		break;
	case GAME:
		game_session->patrol();
		break;
	}
}


void SceneManager::initialize_scene_game() {
	is_enter_key_pushed = false;
	scene = GAME;
	game_session = new GameSession();
}