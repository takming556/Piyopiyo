#include "consts.h"
#include "class.h"
#include "enums.h"


Field::Field() : cellcontainer(FIELD_WIDTH, vector<Cell>(FIELD_HEIGHT)) {
	int address_offset;
	for (int width = 0; width < FIELD_WIDTH; width++) {
		for (int height = 0; height < FIELD_HEIGHT; height++) {
			cellcontainer[width][height].setState(initFieldState[width][height]);
		}
	}
}
