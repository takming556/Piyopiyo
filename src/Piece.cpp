#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

Piece::Piece(Field* given_master_field_ptr) : inner(this), outer(this) {
	master_field = given_master_field_ptr;
	compass = INITIAL_PIECE_DIRECTION;
	setPosition(INITIAL_PIYO_POS_CEL_X, INITIAL_PIYO_POS_CEL_Y);
	inner.setPosition(Position);
	outer.setPosition(Position, compass.direction);
	//inner.master_piece = this;
	//outer.master_piece = this;
	inner.setSurrounder(inner.Position);
	outer.setSurrounder(outer.Position);
}

//Piece::Piece() {
//	compass = INITIAL_PIECE_DIRECTION;
//	setPosition(INITIAL_PIYO_POS_CEL_X, INITIAL_PIYO_POS_CEL_Y);
//	inner.setPosition(Position);
//	outer.setPosition(Position, compass.direction);
//	inner.master_piece = this;
//	outer.master_piece = this;
//	inner.setSurrounder(inner.Position);
//	outer.setSurrounder(outer.Position);
//}

void Piece::draw() {
	inner.draw(FIELD_POS_PXL_X + CELL_WIDTH * inner.Position[0], FIELD_POS_PXL_Y + CELL_HEIGHT * inner.Position[1]);
	outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * outer.Position[0], FIELD_POS_PXL_Y + CELL_HEIGHT * outer.Position[1]);
}

void Piece::drop_onestep() { //Pieceを1段落とす
	Position += downward;
	inner.Position += downward;
	outer.Position += downward;
	inner.setSurrounder(inner.Position);
	outer.setSurrounder(outer.Position);
}

void Piece::move_right() { //Pieceを右に動かす
	Position += rightward;
	inner.Position += rightward;
	outer.Position += rightward;
	inner.setSurrounder(inner.Position);
	outer.setSurrounder(outer.Position);
}

void Piece::move_left() { //Pieceを左に動かす
	Position += leftward;
	inner.Position += leftward;
	outer.Position += leftward;
	inner.setSurrounder(inner.Position);
	outer.setSurrounder(outer.Position);
}

void Piece::rotate_forwardclockwise() { //Pieceを順時計回りに回す
	compass++;
	//compass += 1;
	//compass = compass + 1;
	outer.setPosition(inner.Position, compass.direction);
	outer.setSurrounder(outer.Position);
}

void Piece::rotate_counterclockwise() { //Pieceを反時計回りに回す
	compass--;
	//compass -= 1;
	//compass = compass - 1;
	outer.setPosition(inner.Position, compass.direction);
	outer.setSurrounder(outer.Position);
}

void Piece::setPosition(int given_x, int given_y) { //与えられたx,y座標にPieceのPositionをセットする
	valarray<int> newPosition = { given_x, given_y };
	Position = newPosition;
	inner.setPosition(newPosition);
	outer.setPosition(newPosition, compass.direction);
}
