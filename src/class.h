#pragma once
#include <vector>
#include <valarray>
#include "consts.h"
using std::vector;
using std::valarray;

class Compass{
public:
	Direction direction;
	Compass();
	Compass(Direction given_direction);
	void operator ++(int n);
	void operator --(int n);
	Compass operator ++();
	Compass operator --();
	void operator +=(int rotate_amount_plus);
	void operator -=(int rotate_amount_minus);
	Compass operator +(int rotate_amount_plus);
	Compass operator -(int rotate_amount_minus);
	Compass operator =(Compass righthand);
	Compass operator =(Direction righthand);
	bool operator ==(Compass righthand);
	bool operator !=(Compass righthand);
	bool operator ==(Direction righthand);
	bool operator !=(Direction righthand);
};

class Cell {
public:
	enum State state;
	//int PositionX;
	//int PositionY;
	valarray<int> Position;
	Cell* upper;
	Cell* righter;
	Cell* downer;
	Cell* lefter;
	bool VanishScheduledFlag;
	//Cell(enum State init_state);
	//Cell(enum State init_state, unsigned int init_PositionX, unsigned int init_PositionY);
	Cell();
	void draw(int draw_pos_pxl_x, int draw_pos_pxl_y);
	void draw(valarray<int> drowPosition);
	void setRandomState();
	void setPosition(int given_x, int given_y);
	void setPosition(valarray<int> givenPosition);
	void setPosition(valarray<int> basePosition, Direction given_direction);
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
	Compass compass;
	//unsigned int PositionX;
	//unsigned int PositionY;
	valarray<int> Position;
	Cell inner;
	Cell outer;
	Piece();
	void draw();
	void drop_onestep();
	void move_right();
	void move_left();
	void rotate_forwardclockwise();
	void rotate_counterclockwise();
	void setPosition(int given_x, int given_y);
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