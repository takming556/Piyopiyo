#include "DxLib.h"
#include <math.h>
#include "externs.h"
#include "consts.h"
#include "class.h"
#include "enums.h"

#pragma warning(disable:4996)

//�v���g�^�C�v�錾����
void LoadAllGraph();


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);            //�E�B���h�E�\�� ��/��
	SetMainWindowText("PIYOPIYO");
	SetGraphMode(RES_SCR_X, RES_SCR_Y, 32);  //��ʉ𑜓x1024x768, 24�r�b�g�J���[�ɐݒ�
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DxLib_Init();                      //DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);     //�`���𗠉�ʂɐݒ�

	LoadAllGraph();
	SceneManager scenemanager;
	//initTitle();

	while (true) {
		if (ProcessMessage() != 0)break; //�E�B���h�E�̕���{�^��������������while�������[�v�𔲂���

		ClearDrawScreen();

		scenemanager.patrol();

		ScreenFlip();

	}
}

//void initTitle() {
//	PlayMusic("sound/hoge.mp3", DX_PLAYTYPE_BACK);
//	SetVolumeMusic(96);
//	gamescene = TITLE;
//}

void onInstruction() {

}

void onGameover() {

}

void onResult() {

}

void LoadAllGraph() {
	hImg_title        = LoadGraph("sprite/title.png");
	hImg_background   = LoadGraph("sprite/background.png");
	hImg_field        = LoadGraph("sprite/field.png");
	hImg_nextframe    = LoadGraph("sprite/next_piyo_frame.png");

	hImg_blue         = LoadGraph("sprite/piyo_blue.png");
	hImg_green        = LoadGraph("sprite/piyo_green.png");
	hImg_purple       = LoadGraph("sprite/piyo_purple.png");
	hImg_red          = LoadGraph("sprite/piyo_red.png");
	hImg_yellow       = LoadGraph("sprite/piyo_yellow.png");

	hImg_vacant       = LoadGraph("sprite/vacant.png");
	hImg_vacant_piece = LoadGraph("sprite/vacant_piece.png");
	hImg_outside      = LoadGraph("sprite/outside.png");
	hImg_explode      = LoadGraph("sprite/explode.png");
	hImg_cursor       = LoadGraph("sprite/cursor.png");

	char tmp[30];
	for (int i=0; i < 10; i++) {
		sprintf(tmp, "sprite/%d.png", i);
		hImg_num[i] = LoadGraph(tmp);
	}
}