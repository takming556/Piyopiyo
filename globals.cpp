#include "DxLib.h"
#include "externs.h"
#include "class.h"
#include "enums.h"


bool KeyPushFlag_Up = false;
bool KeyPushFlag_Down = false;
bool KeyPushFlag_Left = false;
bool KeyPushFlag_Right = false;
bool KeyPushFlag_Z = false;
bool KeyPushFlag_X = false;
bool KeyPushFlag_Space = false;
bool KeyPushFlag_Enter = false;

bool NowVanishingFlag = false;

enum GameScene gamescene = TITLE;

//enum State GetCellStateFromNumber(int Number) {
//	switch (Number) {
//	case 0:
//		return VACANT;
//		break;
//	case 1:
//		return BLUE;
//		break;
//	case 2:
//		return GREEN;
//		break;
//	case 3:
//		return PURPLE;
//		break;
//	case 4:
//		return RED;
//		break;
//	case 5:
//		return YELLOW;
//		break;
//	case 6:
//		return OJAMA;
//		break;
//	case 7:
//		return OUTSIDE;
//		break;
//	}
//}

//void LoadAllGraph() {
//	hImg_title = LoadGraph("sprite/title.png");
//	hImg_background = LoadGraph("sprite/background.png");
//	hImg_field = LoadGraph("sprite/field.png");
//	hImg_nextframe = LoadGraph("sprite/next_piyo_frame.png");
//
//	hImg_blue = LoadGraph("sprite/piyo_blue.png");
//	hImg_green = LoadGraph("sprite/piyo_green.png");
//	hImg_purple = LoadGraph("sprite/piyo_purple.png");
//	hImg_red = LoadGraph("sprite/piyo_red.png");
//	hImg_yellow = LoadGraph("sprite/piyo_yellow.png");
//
//	hImg_vacant = LoadGraph("sprite/vacant.png");
//	hImg_vacant_piece = LoadGraph("sprite/vacant_piece.png");
//	hImg_outside = LoadGraph("sprite/outside.png");
//	hImg_explode = LoadGraph("sprite/explode.png");
//	hImg_num0 = LoadGraph("sprite/0.png");
//	hImg_num1 = LoadGraph("sprite/1.png");
//	hImg_num2 = LoadGraph("sprite/2.png");
//	hImg_num3 = LoadGraph("sprite/3.png");
//	hImg_num4 = LoadGraph("sprite/4.png");
//	hImg_num5 = LoadGraph("sprite/5.png");
//	hImg_num6 = LoadGraph("sprite/6.png");
//	hImg_num7 = LoadGraph("sprite/7.png");
//	hImg_num8 = LoadGraph("sprite/8.png");
//	hImg_num9 = LoadGraph("sprite/9.png");
//	hImg_cursor = LoadGraph("sprite/cursor.png");
//}



//const bool DebugFlag = false;                   //TRUE�ɂ���Ɓu��v�u�O�v�Ȃǂ̕\���������
//const bool AutoPiyoFallFlag = true;             //FALSE�ɂ���Ƃ҂�͎蓮�ł̂ݗ�������悤�ɂȂ�
//
//const unsigned int RES_SCR_X = 1024;      //��ʉ𑜓xX
//const unsigned int RES_SCR_Y = 512;       //��ʉ𑜓xY
//
//const unsigned int PIECE_WIDTH = 3;       //�҂�Piece�̃Z����
//const unsigned int PIECE_HEIGHT = 3;      //�҂�Piece�̃Z����
//
//const unsigned int FIELD_WIDTH = 8;       //�Q�[���t�B�[���h�̃Z����
//const unsigned int FIELD_HEIGHT = 14;     //�Q�[���t�B�[���h�̃Z����
//
//const unsigned int CELL_WIDTH = 48;       //�Z���̃s�N�Z����
//const unsigned int CELL_HEIGHT = 48;      //�Z���̃s�N�Z����
//
//const unsigned int VANISH_THRESHOLD = 4;  //�҂����臒l
//
//const double PIYO_SIZE_EXTRATE = (double)CELL_WIDTH / 333 * 1.5; // �҂�\���T�C�Y�{��
//const int PIYO_POS_OFFSET = 24;
//
//const unsigned int FIELD_POS_PXL_X = 96;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuX���W
//const unsigned int FIELD_POS_PXL_Y = 48;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuY���W
//
//const unsigned int NEXTPIYO_POS_PXL_X = 504; //Next�҂�Piece�̕\���s�N�Z���ʒuX���W
//const unsigned int NEXTPIYO_POS_PXL_Y = 96;  //Next�҂�Piece�̕\���s�N�Z���ʒuY���W
//const int OFFSET_NEXTFRAME_POS_PXL_X = -48;
//const int OFFSET_NEXTFRAME_POS_PXL_Y = 0;
//
//const unsigned int INITIAL_PIYO_POS_CEL_X = 3;  //�҂�Piece�̏����Z���ʒuX���W
//const unsigned int INITIAL_PIYO_POS_CEL_Y = 1;  //�҂�Piece�̏����Z���ʒuY���W
//
//const enum CellState initFieldState[FIELD_WIDTH][FIELD_HEIGHT] = {
//					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE},
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE}
//};