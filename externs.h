#pragma once
//#include "consts.h"

//�v���g�^�C�v�錾
//class Cell;
enum State;
enum GameScene;

//extern�錾
//extern void LoadAllGraph();
//extern enum State GetCellStateFromNumber(int Number);

extern enum GameScene gamescene;              //���݂̃Q�[���V�[�����i�[�����
//extern Cell Field[FIELD_WIDTH][FIELD_HEIGHT]; //���݂̃Q�[���Ֆʂ��i�[�����


//�L�[�����t���O����
extern bool KeyPushFlag_Up;
extern bool KeyPushFlag_Down;
extern bool KeyPushFlag_Left;
extern bool KeyPushFlag_Right;
extern bool KeyPushFlag_Z;
extern bool KeyPushFlag_X;
extern bool KeyPushFlag_Space;
extern bool KeyPushFlag_Enter;

//��Ԃ�\���t���O����
extern bool NowVanishingFlag;

//�O���t�B�b�N�n���h������
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