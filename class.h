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
};

class GameSession {
public:
	Field field;
	Piece piece;
	int timekeeper;
	GameSession();
	void patrol();
};

class SceneManager {
public:
	enum Scene scene;
	SceneManager();
	void patrol();
	GameSession initGame();
};