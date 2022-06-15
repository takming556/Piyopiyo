#pragma once
#include "enums.h"

//定数たち
const bool DebugFlag = true;                   //TRUEにすると「空」「外」などの表示がされる
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

const enum State initFieldState[FIELD_WIDTH][FIELD_HEIGHT] = {
					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE},
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE}
};