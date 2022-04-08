#include "DxLib.h"
#include "class.h"

Cell::Cell() {
	state = VACANT;
	VanishScheduledFlag = false;
}
Cell::Cell(enum State init_state) {
	state = init_state;
	VanishScheduledFlag = false;
}
void Cell::setState(enum State given_state) {
	state = given_state;
}
void Cell::setRandomState() {
	int Number = GetRand(4) + 1;
	switch (Number) {
	case 0:
		state = VACANT;
		break;
	case 1:
		state = BLUE;
		break;
	case 2:
		state = GREEN;
		break;
	case 3:
		state = PURPLE;
		break;
	case 4:
		state = RED;
		break;
	case 5:
		state = YELLOW;
		break;
	case 6:
		state = OJAMA;
		break;
	case 7:
		state = OUTSIDE;
		break;
	}
}
