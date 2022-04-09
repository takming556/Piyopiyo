#include "consts.h"
#include "class.h"

Piece::Piece() {
	direction = UP;
	PositionX = INITIAL_PIYO_POS_CEL_X;
	PositionY = INITIAL_PIYO_POS_CEL_Y;
	inner.setRandomState();
	outer.setRandomState();
}
