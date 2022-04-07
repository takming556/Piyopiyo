#pragma once
//#include "defines.h"
#include "consts.h"

enum CellState GetCellStateFromNumber(int Number);

class Cell {
public:
	enum CellState state;
	bool VanishScheduledFlag;
	Cell(enum CellState init_state);
	Cell() {}
};
inline Cell::Cell(enum CellState init_state) {
	state = init_state;
	VanishScheduledFlag = false;
}

class Piece {
public:
	enum Direction direction;
	unsigned int PositionX;
	unsigned int PositionY;
	Cell inner;
	Cell outer;
	Piece();
};
inline Piece::Piece() {
	direction = UP;
	PositionX = INITIAL_PIYO_POS_CEL_X;
	PositionY = INITIAL_PIYO_POS_CEL_Y;
	enum CellState RndStateInner = GetCellStateFromNumber(GetRand(4) + 1);
	enum CellState RndStateOuter = GetCellStateFromNumber(GetRand(4) + 1);
	inner.state = RndStateInner;
	outer.state = RndStateOuter;
}

//enum CellState {
//	VACANT,     //ぴよが無い
//	BLUE,       //青ぴよ
//	GREEN,      //緑ぴよ
//	PURPLE,     //紫ぴよ
//	RED,        //赤ぴよ
//	YELLOW,     //黄ぴよ
//	OJAMA,      //おじゃまぴよ(将来的に実装するかも？)
//	OUTSIDE     //外枠（壁とか床）
//};
//
//enum GameScene {
//	TITLE,
//	INSTRUCTION,
//	GAME,
//	GAMEOVER,
//	RESULT
//};
//
//enum Direction {
//	UP,
//	RIGHT,
//	DOWN,
//	LEFT
//};