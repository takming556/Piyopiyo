#pragma once
#include <vector>
#include "consts.h"
using std::vector;

class Cell {
public:
	enum State state;
	bool VanishScheduledFlag;
	Cell(enum State init_state);
	Cell();
	void draw(int draw_pos_pxl_x, int draw_pos_pxl_y);
	void setState(enum State given_state);
	void setRandomState();
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
	GameSession();
	void patrol();
	void check_clockkeeper();
	void check_keyinput();
};

class SceneManager {
public:
	enum Scene scene;
	GameSession game_session;
	SceneManager();
	void patrol();
	GameSession initGame();
};