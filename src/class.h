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
	//Cell���g��Field��ł̑��݈ʒu��\�������o�[�ϐ���p�ӂ���ׂ���
	//���������ꍇ�Acellcontainer������������ۂ̏������������q���X�g���g�p�������X���G�Ȃ��̂ɂȂ邩������Ȃ�
	//�܂��APiece�̈ʒu�E�������ϓ������ꍇ��inner, outer�̑��݈ʒu�����X�V����K�v���o�Ă��邾�낤
	//�ʓ|��������Ȃ����A��������Ό����ɂ���ď������򂷂邱�ƂȂ�Piece�̏Փ˔��肪�s���Ă��Ƃ��Ƌ�J�����ɍςމ\��������
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
	bool PieceLandingFlag; //���̃t���O���������玟���clock���ߎ���Piece��Field�ɓ]�ʂ���A�]�ʂ��I�������t���O��܂�
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