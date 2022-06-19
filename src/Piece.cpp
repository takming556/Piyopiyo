#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

Piece::Piece() {
	compass = INITIAL_PIECE_DIRECTION;
	setPosition(INITIAL_PIYO_POS_CEL_X, INITIAL_PIYO_POS_CEL_Y);
	inner.setPosition(Position);
	outer.setPosition(Position, compass.direction);
	//switch (compass.direction) {
	//case UP:
	//	outer
	//	outer.PositionX = inner.PositionX;
	//	outer.PositionY = inner.PositionY - 1;
	//	break;
	//case RIGHT:
	//	outer.PositionX = inner.PositionX + 1;
	//	outer.PositionY = inner.PositionY;
	//	break;
	//case DOWN:
	//	outer.PositionX = inner.PositionX;
	//	outer.PositionY = inner.PositionY + 1;
	//	break;
	//case LEFT:
	//	outer.PositionX = inner.PositionX - 1;
	//	outer.PositionY = inner.PositionY;
	//	break;
	//}
	inner.setRandomState();
	outer.setRandomState();
	inner.master_piece = this;
	outer.master_piece = this;
}

void Piece::draw() {
	inner.draw(FIELD_POS_PXL_X + CELL_WIDTH * inner.Position[0], FIELD_POS_PXL_Y + CELL_HEIGHT * inner.Position[1]);
	outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * outer.Position[0], FIELD_POS_PXL_Y + CELL_HEIGHT * outer.Position[1]);

	//switch (compass.direction) {
	//case UP:
	//	outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * PositionX, FIELD_POS_PXL_Y + CELL_HEIGHT * (PositionY - 1));
	//	break;
	//case RIGHT:
	//	outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * (PositionX + 1), FIELD_POS_PXL_Y + CELL_HEIGHT * PositionY);
	//	break;
	//case DOWN:
	//	outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * PositionX, FIELD_POS_PXL_Y + CELL_HEIGHT * (PositionY + 1));
	//	break;
	//case LEFT:
	//	outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * (PositionX - 1), FIELD_POS_PXL_Y + CELL_HEIGHT * PositionY);
	//	break;
	//}
}

void Piece::drop_onestep() {
	//PositionY += 1;
	//inner.PositionY += 1;
	//outer.PositionY += 1;

	Position += downward;
	inner.Position += downward;
	outer.Position += downward;
	inner.setSurrounder(inner.Position);
	outer.setSurrounder(outer.Position);
}

void Piece::move_right() {
	//PositionX += 1;
	//inner.PositionX += 1;
	//outer.PositionX += 1;

	Position += rightward;
	inner.Position += rightward;
	outer.Position += rightward;
	inner.setSurrounder(inner.Position);
	outer.setSurrounder(outer.Position);
}

void Piece::move_left() {
	//PositionX += -1;
	//inner.PositionX += -1;
	//outer.PositionX += -1;

	Position += leftward;
	inner.Position += leftward;
	outer.Position += leftward;
	inner.setSurrounder(inner.Position);
	outer.setSurrounder(outer.Position);
}

void Piece::rotate_forwardclockwise() {
	compass++;
	outer.setPosition(inner.Position, compass.direction);
	outer.setSurrounder(outer.Position);

	//compass += 1;
	//compass = compass + 1;


	//switch (compass.direction) {
	//case UP:
	//	compass.direction = RIGHT;
	//	outer.PositionX = inner.PositionX + 1;
	//	outer.PositionY = inner.PositionY;
	//	break;
	//case RIGHT:
	//	compass.direction = DOWN;
	//	outer.PositionX = inner.PositionX;
	//	outer.PositionY = inner.PositionY + 1;
	//	break;
	//case DOWN:
	//	compass.direction = LEFT;
	//	outer.PositionX = inner.PositionX - 1;
	//	outer.PositionY = inner.PositionY;
	//	break;
	//case LEFT:
	//	compass.direction = UP;
	//	outer.PositionX = inner.PositionX;
	//	outer.PositionY = inner.PositionY - 1;
	//	break;
	//}
}

void Piece::rotate_counterclockwise() {
	compass--;
	outer.setPosition(inner.Position, compass.direction);
	outer.setSurrounder(outer.Position);

	//compass -= 1;
	//compass = compass - 1;
	// 
	//switch (compass.direction) {
	//case UP:
	//	compass.direction = LEFT;
	//	outer.PositionX = inner.PositionX - 1;
	//	outer.PositionY = inner.PositionY;
	//	break;
	//case RIGHT:
	//	compass.direction = UP;
	//	outer.PositionX = inner.PositionX;
	//	outer.PositionY = inner.PositionY - 1;
	//	break;
	//case DOWN:
	//	compass.direction = RIGHT;
	//	outer.PositionX = inner.PositionX + 1;
	//	outer.PositionY = inner.PositionY;
	//	break;
	//case LEFT:
	//	compass.direction = DOWN;
	//	outer.PositionX = inner.PositionX;
	//	outer.PositionY = inner.PositionY + 1;
	//	break;
	//}
}

void Piece::setPosition(int given_x, int given_y) {
	valarray<int> newPosition = { given_x, given_y };
	Position = newPosition;
}
