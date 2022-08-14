#pragma once
#include <vector>
#include <valarray>
#include "consts.h"
using std::vector;
using std::valarray;

class Field;
class Piece;
class Fcell;
class Pcell;


class Compass{
private:
	Direction direction;
public:
	Compass();
	Compass(Direction given_direction);
	Direction get_direction();
	void set_direction(Direction given_direction);
	void rotate_forwardclockwise();
	void rotate_forwardclockwise(unsigned int rotate_amount);
	void rotate_counterclockwise();
	void rotate_counterclockwise(unsigned int rotate_amount);
	//void operator ++(int n);
	//void operator --(int n);
	//Compass operator ++();
	//Compass operator --();
	//void operator +=(int rotate_amount_plus);
	//void operator -=(int rotate_amount_minus);
	//Compass operator +(int rotate_amount_plus);
	//Compass operator -(int rotate_amount_minus);
	//Compass operator =(Compass righthand);
	//Compass operator =(Direction righthand);
	//bool operator ==(Compass righthand);
	//bool operator !=(Compass righthand);
	//bool operator ==(Direction righthand);
	//bool operator !=(Direction righthand);
};


class Field {
private:
	vector<vector<Fcell>> fcell_matrix;
public:
	Field();
	Fcell& get_fcell(valarray<int> given_position);
	void draw();
	static const unsigned int FIELD_WIDTH = 8;				//ゲームフィールドのセル幅
	static const unsigned int FIELD_HEIGHT = 14;			//ゲームフィールドのセル高
	static const unsigned int FIELD_DRAWPOS_PXL_X = 96;		//ゲームフィールドのピクセル位置X座標
	static const unsigned int FIELD_DRAWPOS_PXL_Y = 48;		//ゲームフィールドのピクセル位置Y座標
};


class Fcell {
private:
	Field& master_field;
	enum State state;
	valarray<int> position;
public:
	Fcell(Field& given_master_field, enum State initial_state, valarray<int> lying_position);
	void set_state(enum State given_state);
	//void set_position(int given_x, int given_y);
	enum State get_state();
	Fcell& get_upper();
	Fcell& get_downer();
	Fcell& get_righter();
	Fcell& get_lefter();
	void draw(int x, int y);
	static const unsigned int FCELL_WIDTH = 48;		//フィールドセルのピクセル幅
	static const unsigned int FCELL_HEIGHT = 48;	//フィールドセルのピクセル高
	static inline const enum State INITIAL_FCELL_STATES[Field::FIELD_WIDTH][Field::FIELD_HEIGHT] = {
					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE},
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
					{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE}
	};
};


class Pcell {
private:
	Piece& master_piece;
	enum State state;
	valarray<int> position;
public:
	Pcell(Piece& given_master_piece, valarray<int> given_position, enum State given_state);
	void set_state(enum State given_state);
	//void set_state_randomly();
	void set_position(int given_x, int given_y);
	void set_position(valarray<int> given_position);
	void set_position(valarray<int> base_position, Direction given_direction);
	enum State get_state();
	valarray<int> get_position();
	Fcell& get_upper_fcell();
	Fcell& get_downer_fcell();
	Fcell& get_righter_fcell();
	Fcell& get_lefter_fcell();
	Fcell& get_standing_fcell();
	void draw(int x, int y);
	static inline const double PCELL_DRAWSIZE_EXTRATE = (double)Fcell::FCELL_WIDTH / 333 * 1.5;	// ぴよ表示サイズ倍率
	static const int PCELL_DRAWPOS_OFFSET = 24;
};


class Piece {
private:
	Field& master_field;
	Compass compass;
	valarray<int> position;
	Pcell inner;
	Pcell outer;
public:
	Piece(Field& given_master_field, enum State given_inner_state, enum State given_outer_state);
	//Piece(const Piece& original);
	void set_position(valarray<int> given_position);
	Field& get_master_field();
	Pcell get_inner();
	Pcell get_outer();
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
	void receive_next_piece(Piece given_next_piece);
	//void set_position(int given_x, int given_y);
	static inline const valarray<int> INITIAL_PIECE_POSITION{ 3,1 };		//Pieceの初期位置
	static const enum Direction INITIAL_PIECE_DIRECTION = Direction::UP;	//Pieceの初期方向
	static inline const valarray<int> INITIAL_INNER_PCELL_POSITION{ 3,1 };
	static inline const valarray<int> INITIAL_OUTER_PCELL_POSITION{ 3,0 };
};


class NextPiece {
private:
	enum State inner;
	enum State outer;
public:
	NextPiece();
	void set_randomly();
	enum State get_inner_state();
	enum State get_outer_state();
	void draw();
	static const int NEXT_PIECE_BACKGROUND_DRAWPOS_PXL_X = 504; //next_pieceの背景画像描画位置ピクセルX座標
	static const int NEXT_PIECE_BACKGROUND_DRAWPOS_PXL_Y = 96;  //next_pieceの背景画像描画位置ピクセルY座標
	static const int NEXT_PIECE_DRAWPOS_OFFSET_PXL_X = 24;
	static const int NEXT_PIECE_DRAWPOS_OFFSET_PXL_Y = 64;
	static const int NEXT_PIECE_DRAWPOS_PXL_X = NEXT_PIECE_BACKGROUND_DRAWPOS_PXL_X + NEXT_PIECE_DRAWPOS_OFFSET_PXL_X;
	static const int NEXT_PIECE_DRAWPOS_PXL_Y = NEXT_PIECE_BACKGROUND_DRAWPOS_PXL_Y + NEXT_PIECE_DRAWPOS_OFFSET_PXL_Y;
};


class GameSession {
private:
	Field field;
	Piece* piece;
	NextPiece next_piece;
	int clock_keeper;
	float piyo_drop_freq;
	bool is_down_key_pushed;
	bool is_left_key_pushed;
	bool is_right_key_pushed;
	bool is_z_key_pushed;
	bool is_x_key_pushed;
	bool is_game_over;
	void deal_clockkeeper();
	void deal_keyinput();
	bool check_piece_landing();
	void copy_piece_to_field();
	void update_piece();
	static const unsigned int VANISH_THRESHOLD = 4;	//ぴよ消し閾値
public:
	GameSession();
	void patrol();
};


class SceneManager {
private:
	GameSession* game_session;
	enum Scene scene;
	bool is_enter_key_pushed;
	void initialize_scene_game();
public:
	SceneManager();
	~SceneManager();
	void patrol();
};