#include "DxLib.h"
#include "externs.h"
#include "class.h"


NextPiece::NextPiece() {
	set_randomly();
}


void NextPiece::set_randomly() {
	int Number = GetRand(4) + 1;
	switch (Number) {
	case 0:
		inner = VACANT;
		break;
	case 1:
		inner = BLUE;
		break;
	case 2:
		inner = GREEN;
		break;
	case 3:
		inner = PURPLE;
		break;
	case 4:
		inner = RED;
		break;
	case 5:
		inner = YELLOW;
		break;
	case 6:
		inner = OJAMA;
		break;
	case 7:
		inner = OUTSIDE;
		break;
	}

	Number = GetRand(4) + 1;
	switch (Number) {
	case 0:
		outer = VACANT;
		break;
	case 1:
		outer = BLUE;
		break;
	case 2:
		outer = GREEN;
		break;
	case 3:
		outer = PURPLE;
		break;
	case 4:
		outer = RED;
		break;
	case 5:
		outer = YELLOW;
		break;
	case 6:
		outer = OJAMA;
		break;
	case 7:
		outer = OUTSIDE;
		break;
	}
}

enum State NextPiece::get_inner_state() {
	return inner;
}

enum State NextPiece::get_outer_state() {
	return outer;
}

void NextPiece::draw() {
	DrawGraph(NEXT_PIECE_BACKGROUND_DRAWPOS_PXL_X, NEXT_PIECE_BACKGROUND_DRAWPOS_PXL_Y, hImg_nextframe, FALSE); //NextPiece”wŒi‰æ‘œ‚ð•`‰æ

	switch (outer) {
	case State::VACANT:
		if (DebugFlag == true)DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y - Fcell::FCELL_HEIGHT, 1.0, 0, hImg_vacant, TRUE);
		break;
	case State::BLUE:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y - Fcell::FCELL_HEIGHT, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_blue, TRUE);
		break;
	case State::GREEN:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y - Fcell::FCELL_HEIGHT, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_green, TRUE);
		break;
	case State::PURPLE:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y - Fcell::FCELL_HEIGHT, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_purple, TRUE);
		break;
	case State::RED:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y - Fcell::FCELL_HEIGHT, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_red, TRUE);
		break;
	case State::YELLOW:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y - Fcell::FCELL_HEIGHT, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_yellow, TRUE);
		break;
	case State::OUTSIDE:
		if (DebugFlag == true)DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y - Fcell::FCELL_HEIGHT, 1.0, 0, hImg_outside, TRUE);
		break;
	}


	switch (inner) {
	case State::VACANT:
		if (DebugFlag == true)DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y, 1.0, 0, hImg_vacant, TRUE);
		break;
	case State::BLUE:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_blue, TRUE);
		break;
	case State::GREEN:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_green, TRUE);
		break;
	case State::PURPLE:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_purple, TRUE);
		break;
	case State::RED:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_red, TRUE);
		break;
	case State::YELLOW:
		DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y, Pcell::PCELL_DRAWSIZE_EXTRATE, 0, hImg_yellow, TRUE);
		break;
	case State::OUTSIDE:
		if (DebugFlag == true)DrawRotaGraph(NEXT_PIECE_DRAWPOS_PXL_X, NEXT_PIECE_DRAWPOS_PXL_Y, 1.0, 0, hImg_outside, TRUE);
		break;
	}
}