//#include "DxLib.h"
//#include <math.h>
//
//#pragma warning(disable:4996)
//
//using namespace std;
//
//bool Debugmode = FALSE; //TRUEにすると「空」「外」などの表示がされる
//bool AutoFallPiyo = TRUE; //FALSEにするとぴよは手動でしか落下しなくなる
//
//#define PW 3 //PieceWidth  ぴよPieceのセル幅
//#define PH 3 //PieceHeight ぴよPieceのセル高
//
//#define FW 8  //FieldWidth  ゲームフィールドのセル幅
//#define FH 14 //FieldHeight ゲームフィールドのセル高
//
//#define CW 48 //CellWidth セルのピクセル幅
//#define CH 48 //CellHeight セルのピクセル高
//double piyosize_extrate = (double)CW / (double)333 * 1.5; // ぴよ表示サイズ倍率
//int piyopos_offset = 24;
//
//#define VACANT 0 //ぴよは無い
//#define BLUE 1   //青ぴよ
//#define GREEN 2  //緑ぴよ
//#define PURPLE 3 //紫ぴよ
//#define RED 4    //赤ぴよ
//#define YELLOW 5 //黄ぴよ
//#define OJAMA 6　//おじゃまぴよ
//#define OUTSIDE 7 //地面
//
//#define VANISH_THRESHOLD 4  //ぴよ消し閾値
//
////GameStatus
//#define GAMEOVER 1
//#define OPERATING_PIYO 2
//#define VANISHING_PIYO 3
//#define DROPPING_PIYO 4
//#define INPUT_TICKETNUMBER 5
//#define INPUT_NICKNAME 6
//#define TITLE 7
//#define INSTRUCTION 8
//char GameStatus = TITLE;
//
//#define FIELD_PX_POS_X 96 //ゲームフィールドのピクセル位置X座標
//#define FIELD_PX_POS_Y 48  //ゲームフィールドのピクセル位置Y座標
//
//#define NEXT_PX_POS_X 504 //NextぴよPieceの表示ピクセル位置X座標
//#define NEXT_PX_POS_Y 96  //NextぴよPieceの表示ピクセル位置Y座標
//#define OFFSET_NEXTFRAME_POS_X -48
//#define OFFSET_NEXTFRAME_POS_Y 0
//
//#define INITIAL_POSX 3 //ぴよPieceの初期セル位置X座標
//#define INITIAL_POSY 1 //ぴよPieceの初期セル位置Y座標
//
//unsigned int frame = 0; //現在進行中のゲームの通算経過フレーム数
//double dropfreq = 2;
//
//#define VANISH_DURATION 60 //爆殺演出の長さ(単位はフレーム)
//unsigned int vanish_frame; //爆殺演出経過フレーム数
//
//bool AlreadyScanned[FW][FH] = {};
//bool ToBeVanished[FW][FH] = {};
//
//char Piece[PW][PH]; //移動中のピースの色が格納される3x3の2次元配列
//char PosX; //移動中のピースの中心セルX座標が格納される
//char PosY; //移動中のピースの中心セルY座標が格納される
//char Field[FW][FH]; //各マスの色が格納される8x14の2次元配列
//char Next[PW][PH]; // 次のピースの色が格納される3x3の2次元配列
//
////char Cursor_Position; //いろんなカーソルの位置を入れとく変数
//int draw_pos_x;
//int draw_pos_y;
//
//unsigned int operate_time_milisec; //ゲーム経過時間(ミリ秒)
//unsigned int operate_frame; //現在進行中のゲームのOPERATING_PIYOだけの通算フレーム数
//unsigned long long int totalscore;
//unsigned long int timescore;
//unsigned char combo;
//unsigned long long int comboscore;
//int StartTime; //ゲーム開始時刻(OS起動時刻から起算した通算ミリ秒)
//
//#define POS_KEYPAD_X 400
//#define POS_KEYPAD_Y 384
//#define BETWEEN_NUMKEY 48
//
//#define POS_NUMBER_INDICATOR_X 300
//#define POS_NUMBER_INDICATOR_Y 150
//
//int hImg_title;
//int hImg_background;
//int hImg_field;
//int hImg_nextframe;
//int hImg_blue;
//int hImg_green;
//int hImg_purple;
//int hImg_red;
//int hImg_yellow;
//int hImg_vacant;
//int hImg_vacant_piece;
//int hImg_outside;
//int hImg_explode;
//int hImg_num0;
//int hImg_num1;
//int hImg_num2;
//int hImg_num3;
//int hImg_num4;
//int hImg_num5;
//int hImg_num6;
//int hImg_num7;
//int hImg_num8;
//int hImg_num9;
//int hImg_cursor;
//
//bool IsKeyLeftPushed = FALSE;
//bool IsKeyRightPushed = FALSE;
//bool IsKeyDownPushed = FALSE;
//bool IsKeyUpPushed = FALSE;
//bool IsKeyZPushed = FALSE;
//bool IsKeyXPushed = FALSE;
//bool IsKeySpacePushed = FALSE;
//bool IsKeyEnterPushed = FALSE;
//
//bool IsThereToBeVanished;
//
//bool IsConfirming;
//
////Song sugoi_song;
//
//void swap_char(char* a, char* b) {
//	char temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//	return;
//}
//
//void InitializeAlreadyScanned(void) {
//	for (char y = 0; y <= 13; y++) {
//		for (char x = 0; x <= 7; x++) {
//			AlreadyScanned[x][y] = FALSE;
//		}
//	}
//}
//
//void InitializeToBeVanished(void) {
//	for (char y = 0; y <= 13; y++) {
//		for (char x = 0; x <= 7; x++) {
//			ToBeVanished[x][y] = FALSE;
//		}
//	}
//}
//
//void RotatePiyoAnticlockwise(void) {
//	//Pieceを反時計回りに90度回転した2次元配列RotatedPieceを用意する
//	char RotatedPiece[3][3] = { { VACANT,VACANT,VACANT },
//						{VACANT,VACANT,VACANT},
//						{VACANT,VACANT,VACANT} };
//	for (char y = 0; y <= 2; y++) {
//		for (char x = 0; x <= 2; x++) {
//			RotatedPiece[x][y] = Piece[y][x];
//		}
//	}
//	swap_char(&RotatedPiece[0][0], &RotatedPiece[0][2]);
//	swap_char(&RotatedPiece[1][0], &RotatedPiece[1][2]);
//	swap_char(&RotatedPiece[2][0], &RotatedPiece[2][2]);
//
//	//RotatedPieceが既存ぴよ、壁、地面にぶつかっていないか判定
//	bool touchflag = FALSE;
//	for (char y = -1; y <= 1; y++) {
//		for (char x = -1; x <= 1; x++) {
//			if (RotatedPiece[x + 1][y + 1] != VACANT) {
//				if (Field[PosX + x][PosY + y] != VACANT) {
//					touchflag = TRUE;
//				}
//			}
//		}
//	}
//	if (touchflag == FALSE) { //ぶつかっていなければ
//		for (char y = 0; y <= 2; y++) {
//			for (char x = 0; x <= 2; x++) {
//				Piece[x][y] = RotatedPiece[x][y]; //通常通り反時計回りに90度回転させる
//			}
//		}
//	}
//}
//
//void RotatePiyoClockwise(void) {
//	//Pieceを時計回りに90度回転した2次元配列RotatedPieceを用意する
//	char RotatedPiece[3][3] = { { VACANT,VACANT,VACANT },
//						{VACANT,VACANT,VACANT},
//						{VACANT,VACANT,VACANT} };
//	for (char y = 0; y <= 2; y++) {
//		for (char x = 0; x <= 2; x++) {
//			RotatedPiece[x][y] = Piece[y][x];
//		}
//	}
//	swap_char(&RotatedPiece[0][0], &RotatedPiece[2][0]);
//	swap_char(&RotatedPiece[0][1], &RotatedPiece[2][1]);
//	swap_char(&RotatedPiece[0][2], &RotatedPiece[2][2]);
//
//	//RotatedPieceが既存ぴよ、壁、地面にぶつかっていないか判定
//	bool touchflag = FALSE;
//	for (char y = -1; y <= 1; y++) {
//		for (char x = -1; x <= 1; x++) {
//			if (RotatedPiece[x + 1][y + 1] != VACANT) {
//				if (Field[PosX + x][PosY + y] != VACANT) {
//					touchflag = TRUE;
//				}
//			}
//		}
//	}
//	if (touchflag == FALSE) { //ぶつかっていなければ
//		for (char y = 0; y <= 2; y++) {
//			for (char x = 0; x <= 2; x++) {
//				Piece[x][y] = RotatedPiece[x][y]; //通常通り時計回りに90度回転させる
//			}
//		}
//	}
//}
//
//void DrawField(void) {
//	for (char y = 0; y <= 13; y++) {
//		for (char x = 0; x <= 7; x++) {
//			draw_pos_x = FIELD_PX_POS_X + CW * x + piyopos_offset;
//			draw_pos_y = FIELD_PX_POS_Y + CH * y + piyopos_offset;
//			switch (Field[x][y]) {
//			case VACANT:
//				if (Debugmode)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_vacant, TRUE);
//				break;
//			case BLUE:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_blue, TRUE);
//				break;
//			case GREEN:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_green, TRUE);
//				break;
//			case PURPLE:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_purple, TRUE);
//				break;
//			case RED:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_red, TRUE);
//				break;
//			case YELLOW:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_yellow, TRUE);
//				break;
//			case OUTSIDE:
//				if (Debugmode)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_outside, TRUE);
//				break;
//			}
//		}
//	}
//}
//
//void DrawPiece(void) {
//	for (char y = -1; y <= 1; y++) {
//		for (char x = -1; x <= 1; x++) {
//			draw_pos_x = FIELD_PX_POS_X + CW * (PosX + x) + piyopos_offset;
//			draw_pos_y = FIELD_PX_POS_Y + CH * (PosY + y) + piyopos_offset;
//			switch (Piece[x + 1][y + 1]) {
//			case VACANT:
//				//if (Debugmode)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_vacant_piece, TRUE);
//				break;
//			case BLUE:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_blue, TRUE);
//				break;
//			case GREEN:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_green, TRUE);
//				break;
//			case PURPLE:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_purple, TRUE);
//				break;
//			case RED:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_red, TRUE);
//				break;
//			case YELLOW:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_yellow, TRUE);
//				break;
//			}
//		}
//	}
//}
//
//void DrawNext(void) {
//	for (char y = 0; y <= 2; y++) {
//		for (char x = 0; x <= 2; x++) {
//			draw_pos_x = NEXT_PX_POS_X + OFFSET_NEXTFRAME_POS_X + CW * x + piyopos_offset;
//			draw_pos_y = NEXT_PX_POS_Y + OFFSET_NEXTFRAME_POS_Y + CH * y + piyopos_offset;
//			switch (Next[x][y]) {
//			case VACANT:
//				//if (Debugmode)DrawRotaGraph(draw_pos_x, draw_pos_y, 1.0, 0, hImg_vacant_piece, TRUE);
//				break;
//			case BLUE:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_blue, TRUE);
//				break;
//			case GREEN:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_green, TRUE);
//				break;
//			case PURPLE:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_purple, TRUE);
//				break;
//			case RED:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_red, TRUE);
//				break;
//			case YELLOW:
//				DrawRotaGraph(draw_pos_x, draw_pos_y, piyosize_extrate, 0, hImg_yellow, TRUE);
//				break;
//			}
//		}
//	}
//}
//
//void DrawScoreboard(void) {
//	DrawFormatString(700, 370, GetColor(255, 255, 0), "StartTime = %d [ms]", StartTime);
//	//DrawFormatString(700, 390, GetColor(255, 255, 0), "ticket_num = %c%c%c%c", place_number[0], place_number[1], place_number[2], place_number[3]);
//
//	DrawFormatString(700, 430, GetColor(255, 255, 0), "frame = %d", frame);
//	DrawFormatString(700, 450, GetColor(255, 255, 0), "operate_time_milisec = %d [ms]", operate_time_milisec);
//	DrawFormatString(700, 470, GetColor(255, 255, 0), "operate_frame = %d", operate_frame);
//	DrawFormatString(700, 490, GetColor(255, 255, 0), "vanish_frame = %d", vanish_frame);
//	DrawFormatString(700, 510, GetColor(255, 255, 0), "timescore = %ld", timescore);
//	DrawFormatString(700, 530, GetColor(255, 255, 0), "comboscore = %lld", comboscore);
//	DrawFormatString(700, 550, GetColor(255, 255, 0), "totalscore = %lld", totalscore);
//	DrawFormatString(700, 570, GetColor(255, 255, 0), "combo = %d", combo);
//	DrawFormatString(700, 590, GetColor(255, 255, 0), "dropfreq = %lf", dropfreq);
//}
//
//void PrepareNextPiyo() {
//	for (char y = 0; y <= 2; y++) {
//		for (char x = 0; x <= 2; x++) {
//			Piece[x][y] = Next[x][y];
//		}
//	}
//	PosX = INITIAL_POSX, PosY = INITIAL_POSY;
//
//	char upper_piyo = GetRand(4) + 1;
//	char lower_piyo = GetRand(4) + 1;
//	Next[0][0] = VACANT, Next[1][0] = upper_piyo, Next[2][0] = VACANT;
//	Next[0][1] = VACANT, Next[1][1] = lower_piyo, Next[2][1] = VACANT;
//	Next[0][2] = VACANT, Next[1][2] = VACANT, Next[2][2] = VACANT;
//
//	if (Field[INITIAL_POSX][INITIAL_POSY - 1] != VACANT || Field[INITIAL_POSX][INITIAL_POSY] != VACANT) { //これにあてはまったらゲームオーバーである。
//		GameStatus = GAMEOVER;
//	}
//	return;
//}
//
//void DropHoveringPiyo(void) {
//	for (char x = 1; x <= 6; x++) {
//		for (char y = 1; y<=11 ; y++) {
//			if (Field[x][y] != VACANT && Field[x][y + 1] == VACANT) {
//				for (char a = y + 1; a >= 1; a--) {
//					if (a == 0) {
//						Field[x][a] = VACANT;  //不可視な最上段にぴよが積もり、それが正常に自由落下するか確認せよ
//					}
//					else {
//						Field[x][a] = Field[x][a - 1];
//					}
//				}
//			}
//		}
//	}
//}
//
//void CountChain(char x, char y, char color, char* chain) {
//	AlreadyScanned[x][y] = TRUE;
//	(*chain)++;
//	if (AlreadyScanned[x + 1][y] == FALSE && Field[x + 1][y] == color)CountChain(x + 1, y, color, chain);
//	if (AlreadyScanned[x][y + 1] == FALSE && Field[x][y + 1] == color)CountChain(x, y + 1, color, chain);
//	if (AlreadyScanned[x - 1][y] == FALSE && Field[x - 1][y] == color)CountChain(x - 1, y, color, chain);
//	if (AlreadyScanned[x][y - 1] == FALSE && Field[x][y - 1] == color)CountChain(x, y - 1, color, chain);
//}
//
//void VanishPiyo(void) {
//	for (char y = 0; y <= 12; y++) {
//		for (char x = 1; x <= 6; x++) {
//			if (ToBeVanished[x][y] == TRUE) {
//				Field[x][y] = VACANT;
//			}
//		}
//	}
//}
//
//void VanishCheck(void) {
//	InitializeToBeVanished();
//	for (char y = 0; y <= 12; y++) {
//		for (char x = 1; x <= 6; x++) {
//			if (ToBeVanished[x][y] == FALSE && Field[x][y] != VACANT) {
//				char chain = 0;
//				CountChain(x, y, Field[x][y], &chain);
//				if (chain >= VANISH_THRESHOLD) {
//					for (char b = 0; b <= 13; b++) {
//						for (char a = 0; a <= 7; a++) {
//							ToBeVanished[x][y] = (AlreadyScanned[x][y] == TRUE || ToBeVanished[x][y] == TRUE);
//						}
//					}
//				}
//				InitializeAlreadyScanned();
//			}
//		}
//	}
//
//	//爆殺確定ぴよがあれば爆殺演出に移行
//	IsThereToBeVanished = FALSE;
//	for (char y = 0; y <= 12; y++) {
//		for (char x = 1; x <= 6; x++) {
//			if (ToBeVanished[x][y] == TRUE)IsThereToBeVanished = TRUE;
//		}
//	}
//	if (IsThereToBeVanished == TRUE) {
//		GameStatus = VANISHING_PIYO;
//		combo += 1;
//	}
//	else{
//		if (combo >= 1) {
//			comboscore += pow(7, combo - 1) * 10000;
//		}
//		GameStatus = OPERATING_PIYO;
//	}
//}
//
//void AttemptFallOneStep(void) {
//	//操作中ぴよが既存ぴよもしくは地面に接触してしまうか否かの判定
//	bool touchflag = FALSE;
//	for (char y = -1; y <= 1; y++) {
//		for (char x = -1; x <= 1; x++) {
//			if (Piece[x + 1][y + 1] != VACANT) {
//				if (Field[PosX + x][PosY + y + 1] != VACANT) {
//					touchflag = TRUE;
//				}
//			}
//		}
//	}
//	if (touchflag == TRUE) { //地面もしくは既存ぷよとの接触によりこれ以上落ちることができない場合
//		for (char y = -1; y <= 1; y++) {
//			for (char x = -1; x <= 1; x++) {
//				if (Piece[x + 1][y + 1] != VACANT) {
//					Field[PosX + x][PosY + y] = Piece[x + 1][y + 1]; //操作中ぴよの位置を確定させて既存ぴよとする
//				}
//			}
//		}
//		DropHoveringPiyo();
//		combo = 0;
//		VanishCheck();
//		if (GameStatus == OPERATING_PIYO)PrepareNextPiyo();
//	}
//	if (touchflag == FALSE) {
//		PosY++;
//	}
//
//}
//
//void InitializeTitle(void) {
//	GameStatus = TITLE;
//	frame = 0;
//	IsKeyEnterPushed = FALSE;
//}
//
//void InitializeInstruction() {
//	GameStatus = INSTRUCTION;
//	IsKeyEnterPushed = FALSE;
//}
//
//void InitializeGameover(void) {
//	IsKeySpacePushed = FALSE;
//}
//
//void InitializeGame(void) {
//	GameStatus = OPERATING_PIYO;
//
//	for (char y = 0; y <= 13; y++) {
//		Field[0][y] = OUTSIDE;
//	}
//	for (char y = 0; y <= 13; y++) {
//		Field[7][y] = OUTSIDE;
//	}
//	for (char x = 1; x <= 6; x++) {
//		for (char y = 0; y <= 12; y++) {
//			Field[x][y] = VACANT;
//		}
//	}
//	for (char x = 1; x <= 6; x++) {
//		Field[x][13] = OUTSIDE;
//	}
//	//Field[FW][FH] = { {OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE},
//	//						{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//	//						{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//	//						{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//	//						{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//	//						{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//	//						{ VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,VACANT,OUTSIDE },
//	//						{OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE,OUTSIDE} };
//	PosX = INITIAL_POSX;
//	PosY = INITIAL_POSY;
//
//	StartTime = GetNowCount();
//	operate_frame = 0;
//	operate_time_milisec = 0;
//	vanish_frame = 0; //爆殺演出経過フレーム数
//	totalscore = 0;
//	timescore = 0;
//	combo = 0;
//	comboscore = 0;
//
//	IsKeyLeftPushed = FALSE;
//	IsKeyRightPushed = FALSE;
//	IsKeyDownPushed = FALSE;
//	IsKeyUpPushed = FALSE;
//	IsKeyZPushed = FALSE;
//	IsKeyXPushed = FALSE;
//
//	char upper_piyo = GetRand(4) + 1;
//	char lower_piyo = GetRand(4) + 1;
//	Next[0][0] = VACANT, Next[1][0] = upper_piyo, Next[2][0] = VACANT;
//	Next[0][1] = VACANT, Next[1][1] = lower_piyo, Next[2][1] = VACANT;
//	Next[0][2] = VACANT, Next[1][2] = VACANT, Next[2][2] = VACANT;
//	PrepareNextPiyo(); // 最初のぴよと次のぴよの初期準備
//}
//
//// プログラムは WinMain から始まります
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	ChangeWindowMode(TRUE); //ウィンドウ表示オン
//	SetGraphMode(1024, 768, 32); //画面解像度1024x768, 24ビットカラーに設定
//	SetDrawMode(DX_DRAWMODE_BILINEAR);
//	DxLib_Init(); // ＤＸライブラリ初期化処理
//	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に設定
//
//	hImg_title = LoadGraph("sprite/title.png");
//	hImg_background = LoadGraph("sprite/background.png");
//	hImg_field = LoadGraph("sprite/field.png");
//	hImg_nextframe = LoadGraph("sprite/next_piyo_frame.png");
//
//	hImg_blue = LoadGraph("sprite/piyo_blue.png");
//	hImg_green = LoadGraph("sprite/piyo_green.png");
//	hImg_purple = LoadGraph("sprite/piyo_purple.png");
//	hImg_red = LoadGraph("sprite/piyo_red.png");
//	hImg_yellow = LoadGraph("sprite/piyo_yellow.png");
//
//	hImg_vacant = LoadGraph("sprite/vacant.png");
//	hImg_vacant_piece = LoadGraph("sprite/vacant_piece.png");
//	hImg_outside = LoadGraph("sprite/outside.png");
//	hImg_explode = LoadGraph("sprite/explode.png");
//	hImg_num0 = LoadGraph("sprite/0.png");
//	hImg_num1 = LoadGraph("sprite/1.png");
//	hImg_num2 = LoadGraph("sprite/2.png");
//	hImg_num3 = LoadGraph("sprite/3.png");
//	hImg_num4 = LoadGraph("sprite/4.png");
//	hImg_num5 = LoadGraph("sprite/5.png");
//	hImg_num6 = LoadGraph("sprite/6.png");
//	hImg_num7 = LoadGraph("sprite/7.png");
//	hImg_num8 = LoadGraph("sprite/8.png");
//	hImg_num9 = LoadGraph("sprite/9.png");
//	hImg_cursor = LoadGraph("sprite/cursor.png");
//
//	//get_sqlconf();
//	InitializeTitle();
//	
//
//	while (TRUE) {
//		if (ProcessMessage() != 0) { //ウィンドウの閉じるボタンが押されるとループを抜ける
//			break;
//		}
//		frame++;
//		ClearDrawScreen();
//
//		if (GameStatus == TITLE) {
//			DrawRotaGraph(511, 383, 0.71, 0, hImg_title, TRUE);
//			if (IsKeyEnterPushed == FALSE && CheckHitKey(KEY_INPUT_RETURN)) {
//				IsKeyEnterPushed = TRUE;
//				InitializeGame();
//				//InitializeInstruction();
//				//InitializeInputTicketNumber();
//			}
//		}
//
//		if (GameStatus == OPERATING_PIYO) {
//			DrawGraph(0, 0, hImg_background, TRUE); //背景画像を表示
//			DrawGraph(144, 96, hImg_field, FALSE);  //ゲームフィールドの画像を表示
//			DrawGraph(NEXT_PX_POS_X, NEXT_PX_POS_Y, hImg_nextframe, FALSE); //Nextぴよピース枠を表示
//			DrawFormatString(0, 740, GetColor(255, 255, 0), "←→でぴよ移動　Zで左回転　Xで右回転");
//
//			//Fieldを表示
//			DrawField();
//
//			//Pieceを表示
//			DrawPiece();
//
//			//Nextを表示
//			DrawNext();
//
//			operate_frame += 1;
//			operate_time_milisec = (double)1 / (double)60 * 1000 * operate_frame;
//			timescore = pow((double)operate_time_milisec / 200, 2);
//			totalscore = timescore + comboscore;
//			dropfreq = sqrt((double)16 / (double)360000 * operate_time_milisec);
//
//
//			DrawScoreboard();
//
//			//左矢印キーが押されたとき
//			if (IsKeyLeftPushed == FALSE && CheckHitKey(KEY_INPUT_LEFT)) {
//				IsKeyLeftPushed = TRUE;
//				bool touchflag = FALSE;
//				for (char y = -1; y <= 1; y++) {
//					for (char x = -1; x <= 1; x++) {
//						if (Piece[x + 1][y + 1] != VACANT) {
//							if (Field[PosX + x - 1][PosY + y] != VACANT) {
//								touchflag = TRUE;
//							}
//						}
//					}
//				}
//				//操作中のPieceが1マス左にずれても問題ないことを確認したら
//				if (touchflag == FALSE) {
//					PosX += -1;
//				}
//			}
//			if (IsKeyLeftPushed == TRUE && !CheckHitKey(KEY_INPUT_LEFT)) {
//				IsKeyLeftPushed = FALSE;
//			}
//
//			//右矢印キーが押されたとき
//			if (IsKeyRightPushed == FALSE && CheckHitKey(KEY_INPUT_RIGHT)) {
//				IsKeyRightPushed = TRUE;
//				bool touchflag = FALSE;
//				for (char y = -1; y <= 1; y++) {
//					for (char x = -1; x <= 1; x++) {
//						if (Piece[x + 1][y + 1] != VACANT) {
//							if (Field[PosX + x + 1][PosY + y] != VACANT) {
//								touchflag = TRUE;
//							}
//						}
//					}
//				}
//				//操作中のPieceが1マス右にずれても問題ないことを確認したら
//				if (touchflag == FALSE) {
//					PosX += 1;
//				}
////sugoi_song.nothing();
////DrawFormatString(512, 384, GetColor(255, 0, 0), sugoi_song.get_album().c_str());
//			}
//			if (IsKeyRightPushed == TRUE && !CheckHitKey(KEY_INPUT_RIGHT)) {
//				IsKeyRightPushed = FALSE;
//			}
//
//			//下矢印キーが押されたとき
//			if (IsKeyDownPushed == FALSE && CheckHitKey(KEY_INPUT_DOWN)) {
//				IsKeyDownPushed = TRUE;
//				AttemptFallOneStep();
//			}
//			if (IsKeyDownPushed == TRUE && !CheckHitKey(KEY_INPUT_DOWN)) {
//				IsKeyDownPushed = FALSE;
//			}
//
//			//Zキーが押されたとき
//			if (IsKeyZPushed == FALSE && CheckHitKey(KEY_INPUT_Z)) {
//				IsKeyZPushed = TRUE;
//				RotatePiyoAnticlockwise();
//			}
//			if (IsKeyZPushed == TRUE && !CheckHitKey(KEY_INPUT_Z)) {
//				IsKeyZPushed = FALSE;
//			}
//
//			//Xキーが押されたとき
//			if (IsKeyXPushed == FALSE && CheckHitKey(KEY_INPUT_X)) {
//				IsKeyXPushed = TRUE;
//				RotatePiyoClockwise();
//			}
//			if (IsKeyXPushed == TRUE && !CheckHitKey(KEY_INPUT_X)) {
//				IsKeyXPushed = FALSE;
//			}
//
//			//30フレーム毎に操作中ぴよを1段落とそうとする
//			if (frame % (int)((double)60 / dropfreq) == 1 && AutoFallPiyo == TRUE) {
//				AttemptFallOneStep();
//			}
//		}
//
//		if (GameStatus == VANISHING_PIYO) {
//			DrawGraph(0, 0, hImg_background, TRUE); //背景画像を表示
//			DrawGraph(144, 96, hImg_field, FALSE);  //ゲームフィールドの画像を表示
//			DrawGraph(NEXT_PX_POS_X, NEXT_PX_POS_Y, hImg_nextframe, FALSE); //Nextぴよピース枠を表示
//			DrawFormatString(0, 740, GetColor(255, 255, 0), "←→でぴよ移動　Zで左回転　Xで右回転");
//
//			//Fieldを表示
//			DrawField();
//			DrawNext();
//			DrawScoreboard();
//
//			//「爆」を表示
//			for (char y = 0; y <= 13; y++) {
//				for (char x = 0; x <= 7; x++) {
//					if (ToBeVanished[x][y] == TRUE) {
//						DrawGraph(FIELD_PX_POS_X + CW * x, FIELD_PX_POS_Y + CH * (y), hImg_explode, TRUE);
//					}
//				}
//			}
//
//			if (vanish_frame >= VANISH_DURATION) {
//				vanish_frame = 0;
//				GameStatus = OPERATING_PIYO;
//				VanishPiyo();
//				DropHoveringPiyo();
//				VanishCheck();
//				if (GameStatus == OPERATING_PIYO)PrepareNextPiyo();
//			}
//			else {
//				vanish_frame++;
//			}
//		}
//
//		if (GameStatus == GAMEOVER) {
//			DrawFormatString(400, 384, GetColor(255, 0, 0), "GAME OVER");
//			DrawFormatString(0, 740, GetColor(255, 255, 0), "SPACEキーでタイトルに戻る");
//			DrawScoreboard();
//			//if (CheckHitKey(KEY_INPUT_SPACE))InitializeInputNickname();
//			if (CheckHitKey(KEY_INPUT_SPACE))InitializeTitle();
//
//		}
//
//		DrawFormatString(0, 0, GetColor(0, 0, 0), "%02d", frame % 60);
//		ScreenFlip(); //裏画面を表画面に反映
//	}
//
//	InitGraph(); //グラフィックハンドルが占有していたメモリ領域を解放
//	DxLib_End();				// ＤＸライブラリ使用の終了処理
//
//	return 0;				//プログラムの終了 
//}