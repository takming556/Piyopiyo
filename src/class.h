#pragma once
#include <vector>
#include "consts.h"
using std::vector;

class Direction {
public:

};

class Cell {
public:
	enum State state;
	unsigned int PositionX;
	unsigned int PositionY;
	bool VanishScheduledFlag;
	//Cell(enum State init_state);
	//Cell(enum State init_state, unsigned int init_PositionX, unsigned int init_PositionY);
	Cell();
	void draw(int draw_pos_pxl_x, int draw_pos_pxl_y);
	void setRandomState();
	//Cell自身のField上での存在位置を表すメンバー変数を用意するべきだ
	//実装した場合、cellcontainerを初期化する際の処理が初期化子リストを使用した少々複雑なものになるかもしれない
	//また、Pieceの位置・向きが変動した場合にinner, outerの存在位置情報を更新する必要が出てくるだろう
	//面倒かもしれないが、そうすれば向きによって条件分岐することなくPieceの衝突判定が行えてあとあと苦労せずに済む可能性が高い
};

class Field {
public:
	vector<vector<Cell>> cellcontainer;
	Field();
	void draw();
};

class Piece {
public:
	enum Direction direction;
	unsigned int PositionX;
	unsigned int PositionY;
	Cell inner;
	Cell outer;
	Piece();
	void draw();
	void drop_onestep();
	void move_right();
	void move_left();
	void rotate_forwardclockwise();
	void rotate_counterclockwise();
};

class GameSession {
public:
	Field field;
	Piece piece;
	int clockkeeper;
	float piyodropfreq;
	bool PieceLandingFlag; //このフラグが立ったら次回のclock超過時にPieceをFieldに転写せよ、転写し終わったらフラグを折れ
	GameSession();
	void patrol();
	void deal_clockkeeper();
	void deal_keyinput();
	bool check_Piece_landing();
};

class SceneManager {
public:
	enum Scene scene;
	GameSession game_session;
	SceneManager();
	void patrol();
	GameSession initGame();
};