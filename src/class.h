#pragma once
#include <vector>
#include <valarray>
#include "consts.h"
using std::vector;
using std::valarray;

//class Cell;
class Field;
class Piece;
class FCell;
class PCell;


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

//class Cell {
//public:
//	enum State state;
//	valarray<int> Position;
//	//Field* master_field;
//	//Piece* master_piece;
//	Cell* upper;
//	Cell* righter;
//	Cell* downer;
//	Cell* lefter;
//	bool VanishScheduledFlag;
//	Cell();
//	void draw(int draw_pos_pxl_x, int draw_pos_pxl_y);
//	void setRandomState();
//	void setPosition(int given_x, int given_y);
//	void setPosition(valarray<int> given_position);
//	void setPosition(valarray<int> base_position, Direction given_direction);
//	void setSurrounder(valarray<int> given_position);
//	//Cell���g��Field��ł̑��݈ʒu��\�������o�[�ϐ���p�ӂ���ׂ���
//	//���������ꍇ�Acellcontainer������������ۂ̏������������q���X�g���g�p�������X���G�Ȃ��̂ɂȂ邩������Ȃ�
//	//�܂��APiece�̈ʒu�E�������ϓ������ꍇ��inner, outer�̑��݈ʒu�����X�V����K�v���o�Ă��邾�낤
//	//�ʓ|��������Ȃ����A��������Ό����ɂ���ď������򂷂邱�ƂȂ�Piece�̏Փ˔��肪�s���Ă��Ƃ��Ƌ�J�����ɍςމ\��������
//};

class FCell {
public:
	enum State state;
	valarray<int> Position;
	Field* master_field;
	FCell* upper;
	FCell* righter;
	FCell* downer;
	FCell* lefter;
	bool VanishScheduledFlag;
	//FCell(Field* given_master_field_ptr);
	FCell();
	void draw(int draw_pos_pxl_x, int draw_pos_pxl_y);
	void setPosition(int given_x, int given_y);
	void setSurrounder(valarray<int> given_position);
};

class PCell {
public:
	enum State state;
	valarray<int> Position;
	Piece* master_piece;
	FCell* upper;
	FCell* righter;
	FCell* downer;
	FCell* lefter;
	FCell* standingFCell;
	PCell(Piece* given_master_piece_ptr);
	PCell(Piece& given_master_piece_ptr);
	//PCell();
	void draw(int draw_pos_pxl_x, int draw_pos_pxl_y);
	void setRandomState();
	void setPosition(int given_x, int given_y);
	void setPosition(valarray<int> given_position);
	void setPosition(valarray<int> base_position, Direction given_direction);
	void setSurrounder(valarray<int> given_position);
};

//class Container {
//	FCell** fcells;
//	Container(Field* given_master_field);
//};

class Field {
public:
	//vector<vector<FCell>> cellcontainer;
	FCell** cellcontainer;
	Field();
	void draw();
	FCell* getFCellptr(valarray<int> givenPosition);
};

class Piece {
public:
	Compass compass;
	valarray<int> Position;
	PCell inner;
	PCell outer;
	Field* master_field;
	Piece(Field* given_master_field_ptr);
	Piece(const Piece& original);
	//Piece();
	void draw();
	void drop_onestep();
	void consider_move_right();
	void consider_move_left();
	void move_right();
	void move_left();
	void consider_rotate_forwardclockwise();
	void consider_rotate_counterclockwise();
	void rotate_forwardclockwise();
	void rotate_counterclockwise();
	void reset();
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
	void copy_Piece_to_Field();
};

class SceneManager {
public:
	enum Scene scene;
	GameSession game_session;
	SceneManager();
	void patrol();
	GameSession initGame();
};