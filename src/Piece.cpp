#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"


Piece::Piece(Field& given_master_field, enum State given_inner_state, enum State given_outer_state) :	//コンストラクタ
	inner(*this, INITIAL_INNER_PCELL_POSITION, given_inner_state),
	outer(*this, INITIAL_OUTER_PCELL_POSITION, given_outer_state),
	master_field(given_master_field),
	compass(INITIAL_PIECE_DIRECTION),
	position(INITIAL_PIECE_POSITION)
{
}


//Piece::Piece(const Piece& original) :
//	inner(original.inner.master_piece, original.inner.position)
//{	//コピーコンストラクタ
//	inner = original.inner.
//	master_field = original.master_field;
//	compass = original.compass;
//	position = original.position;
//}


void Piece::set_position(valarray<int> given_position) {
	position = given_position;
	inner.set_position(given_position);
	outer.set_position(given_position, compass.get_direction());
}


Field& Piece::get_master_field() {
	return master_field;
}


Pcell Piece::get_inner() {
	return inner;
}


Pcell Piece::get_outer() {
	return outer;
}


void Piece::draw() {
	valarray<int> inner_position = inner.get_position();
	valarray<int> outer_position = outer.get_position();
	inner.draw(Field::FIELD_DRAWPOS_PXL_X + Fcell::FCELL_WIDTH * inner_position[Dimension::X], Field::FIELD_DRAWPOS_PXL_Y + Fcell::FCELL_HEIGHT * inner_position[Dimension::Y]);
	outer.draw(Field::FIELD_DRAWPOS_PXL_X + Fcell::FCELL_WIDTH * outer_position[Dimension::X], Field::FIELD_DRAWPOS_PXL_Y + Fcell::FCELL_HEIGHT * outer_position[Dimension::Y]);
}


void Piece::drop_onestep() { //Pieceを1段落とす
	position += downward;
	inner.set_position(inner.get_position() += downward);
	outer.set_position(outer.get_position() += downward);
}


void Piece::consider_move_right() {
	if (inner.get_righter_fcell().get_state() == State::VACANT && outer.get_righter_fcell().get_state() == State::VACANT) {
		move_right();
	}
}


void Piece::consider_move_left() {
	if (inner.get_lefter_fcell().get_state() == State::VACANT && outer.get_lefter_fcell().get_state() == State::VACANT) {
		move_left();
	}
}


void Piece::move_right() { //Pieceを右に動かす
	position += rightward;
	inner.set_position(inner.get_position() + rightward);
	outer.set_position(outer.get_position() + rightward);
}


void Piece::move_left() { //Pieceを左に動かす
	position += leftward;
	inner.set_position(inner.get_position() + leftward);
	outer.set_position(outer.get_position() + leftward);
}


void Piece::consider_rotate_forwardclockwise() {
	//Piece i(*this);
	//i.rotate_forwardclockwise();
	//if(i.inner.)
}


void Piece::consider_rotate_counterclockwise() {

}


void Piece::rotate_forwardclockwise() { //Pieceを順時計回りに回す
	compass.rotate_forwardclockwise();
	outer.set_position(inner.get_position(), compass.get_direction());
}


void Piece::rotate_counterclockwise() { //Pieceを反時計回りに回す
	compass.rotate_counterclockwise();
	outer.set_position(inner.get_position(), compass.get_direction());
}


void Piece::receive_next_piece(Piece given_next_piece) {
	compass.set_direction(given_next_piece.compass.get_direction());
	set_position(given_next_piece.position);
	inner.set_state(given_next_piece.inner.get_state());
	outer.set_state(given_next_piece.outer.get_state());
}