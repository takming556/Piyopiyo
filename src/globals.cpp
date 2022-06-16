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

//bool NowVanishingFlag = false;

//グラフィックハンドルたち
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
int hImg_num[10];
//int hImg_num0;
//int hImg_num1;
//int hImg_num2;
//int hImg_num3;
//int hImg_num4;
//int hImg_num5;
//int hImg_num6;
//int hImg_num7;
//int hImg_num8;
//int hImg_num9;
int hImg_cursor;

//enum Scene scene = TITLE;