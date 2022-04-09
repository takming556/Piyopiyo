#pragma once
//#include "consts.h"

//プロトタイプ宣言
//class Cell;
enum State;
enum GameScene;

//extern宣言
//extern void LoadAllGraph();
//extern enum State GetCellStateFromNumber(int Number);

extern enum GameScene gamescene;              //現在のゲームシーンが格納される
//extern Cell Field[FIELD_WIDTH][FIELD_HEIGHT]; //現在のゲーム盤面が格納される


//キー押下フラグたち
extern bool KeyPushFlag_Up;
extern bool KeyPushFlag_Down;
extern bool KeyPushFlag_Left;
extern bool KeyPushFlag_Right;
extern bool KeyPushFlag_Z;
extern bool KeyPushFlag_X;
extern bool KeyPushFlag_Space;
extern bool KeyPushFlag_Enter;

//状態を表すフラグたち
extern bool NowVanishingFlag;

//グラフィックハンドルたち
//extern int hImg_title;
//extern int hImg_background;
//extern int hImg_field;
//extern int hImg_nextframe;
//extern int hImg_blue;
//extern int hImg_green;
//extern int hImg_purple;
//extern int hImg_red;
//extern int hImg_yellow;
//extern int hImg_vacant;
//extern int hImg_vacant_piece;
//extern int hImg_outside;
//extern int hImg_explode;
//extern int hImg_num0;
//extern int hImg_num1;
//extern int hImg_num2;
//extern int hImg_num3;
//extern int hImg_num4;
//extern int hImg_num5;
//extern int hImg_num6;
//extern int hImg_num7;
//extern int hImg_num8;
//extern int hImg_num9;
//extern int hImg_cursor;