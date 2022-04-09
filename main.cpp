#include "DxLib.h"
#include <math.h>
#include "externs.h"
#include "consts.h"
#include "class.h"
#include "enums.h"


//�v���g�^�C�v�錾����
void initTitle();
void initGame();

void onTitle();
void onInstruction();
void onGame();
void onGameover();
void onResult();

void LoadAllGraph();
void DrawField();
void DrawPiece();

//�O���t�B�b�N�n���h������
int hImg_title;
int hImg_background;
int hImg_field;
int hImg_nextframe;
int hImg_blue;
int hImg_green;
int hImg_purple;
int hImg_red;
int hImg_yellow;
int hImg_vacant;
int hImg_vacant_piece;
int hImg_outside;
int hImg_explode;
int hImg_num0;
int hImg_num1;
int hImg_num2;
int hImg_num3;
int hImg_num4;
int hImg_num5;
int hImg_num6;
int hImg_num7;
int hImg_num8;
int hImg_num9;
int hImg_cursor;

Field field;

//Cell Field[FIELD_WIDTH][FIELD_HEIGHT]= {
//					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE},
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE}
//};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);            //�E�B���h�E�\�� ��/��
	SetMainWindowText("PIYOPIYO");
	SetGraphMode(RES_SCR_X, RES_SCR_Y, 32);  //��ʉ𑜓x1024x768, 24�r�b�g�J���[�ɐݒ�
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DxLib_Init();                      //DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);     //�`���𗠉�ʂɐݒ�

	LoadAllGraph();
	initTitle();

	while (true) {
		if (ProcessMessage() != 0)break; //�E�B���h�E�̕���{�^��������������while�������[�v�𔲂���

		ClearDrawScreen();

		switch (gamescene) {
		case TITLE:
			onTitle();
			break;
		case INSTRUCTION:
			onInstruction();
			break;
		case GAME:
			onGame();
			break;
		case GAMEOVER:
			onGameover();
			break;
		case RESULT:
			onResult();
			break;
		}

		ScreenFlip();

	}
}

void initTitle() {
	gamescene = TITLE;
}

void onTitle() {
	DrawRotaGraph(RES_SCR_X / 2 - 1, RES_SCR_Y / 2 - 1, 0.71, 0, hImg_title, TRUE);
	if (KeyPushFlag_Enter == false && CheckHitKey(KEY_INPUT_RETURN) == TRUE) {
		KeyPushFlag_Enter = true;
		initGame();
	}
}

void onInstruction() {

}

void initGame() {
	KeyPushFlag_Enter = false;
	gamescene = GAME;
	NowVanishingFlag = false;
}


void onGame() {
	DrawGraph(0, 0, hImg_background, TRUE); //�w�i�摜��\��
	DrawGraph(144, 96, hImg_field, FALSE);  //�Q�[���t�B�[���h�̉摜��\��
	DrawGraph(NEXTPIYO_POS_PXL_X, NEXTPIYO_POS_PXL_Y, hImg_nextframe, FALSE); //Next�҂�s�[�X�g��\��
	DrawFormatString(0, 740, GetColor(255, 255, 0), "�����ł҂�ړ��@Z�ō���]�@X�ŉE��]");
	DrawField();
}

void onGameover() {

}

void onResult() {

}

void LoadAllGraph() {
	hImg_title = LoadGraph("sprite/title.png");
	hImg_background = LoadGraph("sprite/background.png");
	hImg_field = LoadGraph("sprite/field.png");
	hImg_nextframe = LoadGraph("sprite/next_piyo_frame.png");

	hImg_blue = LoadGraph("sprite/piyo_blue.png");
	hImg_green = LoadGraph("sprite/piyo_green.png");
	hImg_purple = LoadGraph("sprite/piyo_purple.png");
	hImg_red = LoadGraph("sprite/piyo_red.png");
	hImg_yellow = LoadGraph("sprite/piyo_yellow.png");

	hImg_vacant = LoadGraph("sprite/vacant.png");
	hImg_vacant_piece = LoadGraph("sprite/vacant_piece.png");
	hImg_outside = LoadGraph("sprite/outside.png");
	hImg_explode = LoadGraph("sprite/explode.png");
	hImg_num0 = LoadGraph("sprite/0.png");
	hImg_num1 = LoadGraph("sprite/1.png");
	hImg_num2 = LoadGraph("sprite/2.png");
	hImg_num3 = LoadGraph("sprite/3.png");
	hImg_num4 = LoadGraph("sprite/4.png");
	hImg_num5 = LoadGraph("sprite/5.png");
	hImg_num6 = LoadGraph("sprite/6.png");
	hImg_num7 = LoadGraph("sprite/7.png");
	hImg_num8 = LoadGraph("sprite/8.png");
	hImg_num9 = LoadGraph("sprite/9.png");
	hImg_cursor = LoadGraph("sprite/cursor.png");
}

void DrawField(void) {
	for (char y = 0; y < FIELD_HEIGHT; y++) {
		for (char x = 0; x < FIELD_WIDTH; x++) {
			int draw_pos_x = FIELD_POS_PXL_X + CELL_WIDTH * x + PIYO_POS_OFFSET;
			int draw_pos_y = FIELD_POS_PXL_Y + CELL_WIDTH * y + PIYO_POS_OFFSET;
			switch (field.cellcontainer[x][y].state) {
			case VACANT:
				if (DebugFlag==true)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_vacant, TRUE);
				break;
			case BLUE:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_blue, TRUE);
				break;
			case GREEN:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_green, TRUE);
				break;
			case PURPLE:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_purple, TRUE);
				break;
			case RED:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_red, TRUE);
				break;
			case YELLOW:
				DrawRotaGraph(draw_pos_x, draw_pos_y, PIYO_SIZE_EXTRATE, 0, hImg_yellow, TRUE);
				break;
			case OUTSIDE:
				if (DebugFlag==true)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_outside, TRUE);
				break;
			}
		}
	}
}
