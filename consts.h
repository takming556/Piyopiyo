#pragma once
//#include "defines.h"
//#include "class.h"
#include "enums.h"

//enum CellState;

//�萔����
const bool DebugFlag = false;                   //TRUE�ɂ���Ɓu��v�u�O�v�Ȃǂ̕\���������
const bool AutoPiyoFallFlag = true;             //FALSE�ɂ���Ƃ҂�͎蓮�ł̂ݗ�������悤�ɂȂ�

const unsigned int RES_SCR_X = 1024;      //��ʉ𑜓xX
const unsigned int RES_SCR_Y = 768;       //��ʉ𑜓xY

const unsigned int PIECE_WIDTH = 3;       //�҂�Piece�̃Z����
const unsigned int PIECE_HEIGHT = 3;      //�҂�Piece�̃Z����

const unsigned int FIELD_WIDTH = 8;       //�Q�[���t�B�[���h�̃Z����
const unsigned int FIELD_HEIGHT = 14;     //�Q�[���t�B�[���h�̃Z����

const unsigned int CELL_WIDTH = 48;       //�Z���̃s�N�Z����
const unsigned int CELL_HEIGHT = 48;      //�Z���̃s�N�Z����

const unsigned int VANISH_THRESHOLD = 4;  //�҂����臒l

const double PIYO_SIZE_EXTRATE = (double)CELL_WIDTH / 333 * 1.5; // �҂�\���T�C�Y�{��
const int PIYO_POS_OFFSET = 24;

const unsigned int FIELD_POS_PXL_X = 96;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuX���W
const unsigned int FIELD_POS_PXL_Y = 48;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuY���W

const unsigned int NEXTPIYO_POS_PXL_X = 504; //Next�҂�Piece�̕\���s�N�Z���ʒuX���W
const unsigned int NEXTPIYO_POS_PXL_Y = 96;  //Next�҂�Piece�̕\���s�N�Z���ʒuY���W
const int OFFSET_NEXTFRAME_POS_PXL_X = -48;
const int OFFSET_NEXTFRAME_POS_PXL_Y = 0;

const unsigned int INITIAL_PIYO_POS_CEL_X = 3;  //�҂�Piece�̏����Z���ʒuX���W
const unsigned int INITIAL_PIYO_POS_CEL_Y = 1;  //�҂�Piece�̏����Z���ʒuY���W

const enum CellState initFieldState[FIELD_WIDTH][FIELD_HEIGHT] = {
					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE},
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE}
};


//extern const bool DebugFlag;                   //TRUE�ɂ���Ɓu��v�u�O�v�Ȃǂ̕\���������
//extern const bool AutoPiyoFallFlag;             //FALSE�ɂ���Ƃ҂�͎蓮�ł̂ݗ�������悤�ɂȂ�
//
//extern const unsigned int RES_SCR_X;      //��ʉ𑜓xX
//extern const unsigned int RES_SCR_Y;       //��ʉ𑜓xY
//
//extern const unsigned int PIECE_WIDTH;       //�҂�Piece�̃Z����
//extern const unsigned int PIECE_HEIGHT;      //�҂�Piece�̃Z����
//
//extern const unsigned int FIELD_WIDTH;       //�Q�[���t�B�[���h�̃Z����
//extern const unsigned int FIELD_HEIGHT;     //�Q�[���t�B�[���h�̃Z����
//
//extern const unsigned int CELL_WIDTH;       //�Z���̃s�N�Z����
//extern const unsigned int CELL_HEIGHT;      //�Z���̃s�N�Z����
//
//extern const unsigned int VANISH_THRESHOLD;  //�҂����臒l
//
//extern const double PIYO_SIZE_EXTRATE; // �҂�\���T�C�Y�{��
//extern const int PIYO_POS_OFFSET;
//
//extern const unsigned int FIELD_POS_PXL_X;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuX���W
//extern const unsigned int FIELD_POS_PXL_Y;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuY���W
//
//extern const unsigned int NEXTPIYO_POS_PXL_X; //Next�҂�Piece�̕\���s�N�Z���ʒuX���W
//extern const unsigned int NEXTPIYO_POS_PXL_Y;  //Next�҂�Piece�̕\���s�N�Z���ʒuY���W
//extern const int OFFSET_NEXTFRAME_POS_PXL_X;
//extern const int OFFSET_NEXTFRAME_POS_PXL_Y;
//
//extern const unsigned int INITIAL_PIYO_POS_CEL_X;  //�҂�Piece�̏����Z���ʒuX���W
//extern const unsigned int INITIAL_PIYO_POS_CEL_Y;  //�҂�Piece�̏����Z���ʒuY���W
//
//extern const enum CellState initFieldState[FIELD_WIDTH][FIELD_HEIGHT];

//inline extern const bool DebugFlag;                   //TRUE�ɂ���Ɓu��v�u�O�v�Ȃǂ̕\���������
//inline extern const bool AutoPiyoFallFlag;             //FALSE�ɂ���Ƃ҂�͎蓮�ł̂ݗ�������悤�ɂȂ�
//
//inline extern const unsigned int RES_SCR_X;      //��ʉ𑜓xX
//inline extern const unsigned int RES_SCR_Y;       //��ʉ𑜓xY
//
//inline extern const unsigned int PIECE_WIDTH;       //�҂�Piece�̃Z����
//inline extern const unsigned int PIECE_HEIGHT;      //�҂�Piece�̃Z����
//
//inline extern const unsigned int FIELD_WIDTH;       //�Q�[���t�B�[���h�̃Z����
//inline extern const unsigned int FIELD_HEIGHT;     //�Q�[���t�B�[���h�̃Z����
//
//inline extern const unsigned int CELL_WIDTH;       //�Z���̃s�N�Z����
//inline extern const unsigned int CELL_HEIGHT;      //�Z���̃s�N�Z����
//
//inline extern const unsigned int VANISH_THRESHOLD;  //�҂����臒l
//
//inline extern const double PIYO_SIZE_EXTRATE; // �҂�\���T�C�Y�{��
//inline extern const int PIYO_POS_OFFSET;
//
//inline extern const unsigned int FIELD_POS_PXL_X;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuX���W
//inline extern const unsigned int FIELD_POS_PXL_Y;  //�Q�[���t�B�[���h�̃s�N�Z���ʒuY���W
//
//inline extern const unsigned int NEXTPIYO_POS_PXL_X; //Next�҂�Piece�̕\���s�N�Z���ʒuX���W
//inline extern const unsigned int NEXTPIYO_POS_PXL_Y;  //Next�҂�Piece�̕\���s�N�Z���ʒuY���W
//inline extern const int OFFSET_NEXTFRAME_POS_PXL_X;
//inline extern const int OFFSET_NEXTFRAME_POS_PXL_Y;
//
//inline extern const unsigned int INITIAL_PIYO_POS_CEL_X;  //�҂�Piece�̏����Z���ʒuX���W
//inline extern const unsigned int INITIAL_PIYO_POS_CEL_Y;  //�҂�Piece�̏����Z���ʒuY���W
//
//inline extern const enum CellState initFieldState[FIELD_WIDTH][FIELD_HEIGHT];