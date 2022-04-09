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