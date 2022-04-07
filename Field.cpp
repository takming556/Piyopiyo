#include "DxLib.h"
#include "consts.h"
#include "class.h"
#include "enums.h"


Field::Field() {
	for (int width = 0; width < FIELD_WIDTH; width++) {
		for (int height = 0; height < FIELD_HEIGHT; height++) {
			int address_offset = height * width + width;
			new(cellcontainer + address_offset)Cell(initFieldState[width][height]);
		}
	}
}
