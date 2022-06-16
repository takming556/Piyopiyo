#include "DxLib.h"
#include "externs.h"
#include "consts.h"
#include "enums.h"
#include "class.h"

Piece::Piece() {
	direction = UP;
	PositionX = INITIAL_PIYO_POS_CEL_X;
	PositionY = INITIAL_PIYO_POS_CEL_Y;
	inner.setRandomState();
	outer.setRandomState();
}

void Piece::draw() {
	inner.draw(FIELD_POS_PXL_X + CELL_WIDTH * PositionX, FIELD_POS_PXL_Y + CELL_HEIGHT * PositionY);

	switch (direction) {
	case UP:
		outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * PositionX, FIELD_POS_PXL_Y + CELL_HEIGHT * (PositionY - 1));
		break;
	case RIGHT:
		outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * (PositionX + 1), FIELD_POS_PXL_Y + CELL_HEIGHT * PositionY);
		break;
	case DOWN:
		outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * PositionX, FIELD_POS_PXL_Y + CELL_HEIGHT * (PositionY + 1));
		break;
	case LEFT:
		outer.draw(FIELD_POS_PXL_X + CELL_WIDTH * (PositionX - 1), FIELD_POS_PXL_Y + CELL_HEIGHT * PositionY);
		break;
	}
}

void Piece::drop_onestep() {
	PositionY += 1;
}