#pragma once


enum State {
	VACANT,     //ぴよが無い
	BLUE,       //青ぴよ
	GREEN,      //緑ぴよ
	PURPLE,     //紫ぴよ
	RED,        //赤ぴよ
	YELLOW,     //黄ぴよ
	OJAMA,      //おじゃまぴよ(将来的に実装するかも？)
	OUTSIDE     //外枠（壁とか床）
};

enum Scene {
	TITLE,			//タイトル画面
	INSTRUCTION,	//操作説明画面
	GAME,			//ゲームプレイ画面
	GAMEOVER,		//ゲームオーバー画面
	RESULT			//結果表示画面
};

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

enum Dimension {
	X,
	Y
};