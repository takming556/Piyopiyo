//#include "class.h"
//
//Container::Container(Field* given_master_field) {
//	//2ŽŸŒ³”z—ñcellcontainer‚ð“®“IŠm•Û
//	fcells = new FCell * [FIELD_WIDTH];
//	for (int i = 0; i < FIELD_WIDTH; ++i) {
//		fcells[i] = new FCell[FIELD_HEIGHT];
//	}
//
//	for (int width = 0; width < FIELD_WIDTH; width++) {
//		for (int height = 0; height < FIELD_HEIGHT; height++) {
//			//FCell** memptr = &(&cellcontainer[width])[height];
//			//new(memptr) FCell(this);
//
//			fcells[width][height].master_field = given_master_field;
//			fcells[width][height].state = initFieldCellState[width][height];
//			fcells[width][height].VanishScheduledFlag = false;
//			fcells[width][height].setPosition(width, height);
//
//
//			//cellcontainer[width][height].state = initFieldCellState[width][height];
//			//cellcontainer[width][height].master_field = this;
//
//			if (height == 0) fcells[width][height].upper = nullptr;
//			else fcells[width][height].upper = &fcells[width][height - 1];
//
//			if (width == FIELD_WIDTH - 1) fcells[width][height].righter = nullptr;
//			else fcells[width][height].righter = &fcells[width + 1][height];
//
//			if (height == FIELD_HEIGHT - 1) fcells[width][height].downer = nullptr;
//			else fcells[width][height].downer = &fcells[width][height - 1];
//
//			if (width == 0) fcells[width][height].lefter = nullptr;
//			else fcells[width][height].lefter = &fcells[width - 1][height];
//		}
//	}
//
//}