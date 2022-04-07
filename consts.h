#pragma once
//#include "defines.h"
//#include "class.h"
#include "enums.h"

//enum CellState;

//定数たち
const bool DebugFlag = false;                   //TRUEにすると「空」「外」などの表示がされる
const bool AutoPiyoFallFlag = true;             //FALSEにするとぴよは手動でのみ落下するようになる

const unsigned int RES_SCR_X = 1024;      //画面解像度X
const unsigned int RES_SCR_Y = 768;       //画面解像度Y

const unsigned int PIECE_WIDTH = 3;       //ぴよPieceのセル幅
const unsigned int PIECE_HEIGHT = 3;      //ぴよPieceのセル高

const unsigned int FIELD_WIDTH = 8;       //ゲームフィールドのセル幅
const unsigned int FIELD_HEIGHT = 14;     //ゲームフィールドのセル高

const unsigned int CELL_WIDTH = 48;       //セルのピクセル幅
const unsigned int CELL_HEIGHT = 48;      //セルのピクセル高

const unsigned int VANISH_THRESHOLD = 4;  //ぴよ消し閾値

const double PIYO_SIZE_EXTRATE = (double)CELL_WIDTH / 333 * 1.5; // ぴよ表示サイズ倍率
const int PIYO_POS_OFFSET = 24;

const unsigned int FIELD_POS_PXL_X = 96;  //ゲームフィールドのピクセル位置X座標
const unsigned int FIELD_POS_PXL_Y = 48;  //ゲームフィールドのピクセル位置Y座標

const unsigned int NEXTPIYO_POS_PXL_X = 504; //NextぴよPieceの表示ピクセル位置X座標
const unsigned int NEXTPIYO_POS_PXL_Y = 96;  //NextぴよPieceの表示ピクセル位置Y座標
const int OFFSET_NEXTFRAME_POS_PXL_X = -48;
const int OFFSET_NEXTFRAME_POS_PXL_Y = 0;

const unsigned int INITIAL_PIYO_POS_CEL_X = 3;  //ぴよPieceの初期セル位置X座標
const unsigned int INITIAL_PIYO_POS_CEL_Y = 1;  //ぴよPieceの初期セル位置Y座標

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


//extern const bool DebugFlag;                   //TRUEにすると「空」「外」などの表示がされる
//extern const bool AutoPiyoFallFlag;             //FALSEにするとぴよは手動でのみ落下するようになる
//
//extern const unsigned int RES_SCR_X;      //画面解像度X
//extern const unsigned int RES_SCR_Y;       //画面解像度Y
//
//extern const unsigned int PIECE_WIDTH;       //ぴよPieceのセル幅
//extern const unsigned int PIECE_HEIGHT;      //ぴよPieceのセル高
//
//extern const unsigned int FIELD_WIDTH;       //ゲームフィールドのセル幅
//extern const unsigned int FIELD_HEIGHT;     //ゲームフィールドのセル高
//
//extern const unsigned int CELL_WIDTH;       //セルのピクセル幅
//extern const unsigned int CELL_HEIGHT;      //セルのピクセル高
//
//extern const unsigned int VANISH_THRESHOLD;  //ぴよ消し閾値
//
//extern const double PIYO_SIZE_EXTRATE; // ぴよ表示サイズ倍率
//extern const int PIYO_POS_OFFSET;
//
//extern const unsigned int FIELD_POS_PXL_X;  //ゲームフィールドのピクセル位置X座標
//extern const unsigned int FIELD_POS_PXL_Y;  //ゲームフィールドのピクセル位置Y座標
//
//extern const unsigned int NEXTPIYO_POS_PXL_X; //NextぴよPieceの表示ピクセル位置X座標
//extern const unsigned int NEXTPIYO_POS_PXL_Y;  //NextぴよPieceの表示ピクセル位置Y座標
//extern const int OFFSET_NEXTFRAME_POS_PXL_X;
//extern const int OFFSET_NEXTFRAME_POS_PXL_Y;
//
//extern const unsigned int INITIAL_PIYO_POS_CEL_X;  //ぴよPieceの初期セル位置X座標
//extern const unsigned int INITIAL_PIYO_POS_CEL_Y;  //ぴよPieceの初期セル位置Y座標
//
//extern const enum CellState initFieldState[FIELD_WIDTH][FIELD_HEIGHT];

//inline extern const bool DebugFlag;                   //TRUEにすると「空」「外」などの表示がされる
//inline extern const bool AutoPiyoFallFlag;             //FALSEにするとぴよは手動でのみ落下するようになる
//
//inline extern const unsigned int RES_SCR_X;      //画面解像度X
//inline extern const unsigned int RES_SCR_Y;       //画面解像度Y
//
//inline extern const unsigned int PIECE_WIDTH;       //ぴよPieceのセル幅
//inline extern const unsigned int PIECE_HEIGHT;      //ぴよPieceのセル高
//
//inline extern const unsigned int FIELD_WIDTH;       //ゲームフィールドのセル幅
//inline extern const unsigned int FIELD_HEIGHT;     //ゲームフィールドのセル高
//
//inline extern const unsigned int CELL_WIDTH;       //セルのピクセル幅
//inline extern const unsigned int CELL_HEIGHT;      //セルのピクセル高
//
//inline extern const unsigned int VANISH_THRESHOLD;  //ぴよ消し閾値
//
//inline extern const double PIYO_SIZE_EXTRATE; // ぴよ表示サイズ倍率
//inline extern const int PIYO_POS_OFFSET;
//
//inline extern const unsigned int FIELD_POS_PXL_X;  //ゲームフィールドのピクセル位置X座標
//inline extern const unsigned int FIELD_POS_PXL_Y;  //ゲームフィールドのピクセル位置Y座標
//
//inline extern const unsigned int NEXTPIYO_POS_PXL_X; //NextぴよPieceの表示ピクセル位置X座標
//inline extern const unsigned int NEXTPIYO_POS_PXL_Y;  //NextぴよPieceの表示ピクセル位置Y座標
//inline extern const int OFFSET_NEXTFRAME_POS_PXL_X;
//inline extern const int OFFSET_NEXTFRAME_POS_PXL_Y;
//
//inline extern const unsigned int INITIAL_PIYO_POS_CEL_X;  //ぴよPieceの初期セル位置X座標
//inline extern const unsigned int INITIAL_PIYO_POS_CEL_Y;  //ぴよPieceの初期セル位置Y座標
//
//inline extern const enum CellState initFieldState[FIELD_WIDTH][FIELD_HEIGHT];