#pragma once
enum CellState {
	VACANT,     //�҂悪����
	BLUE,       //�҂�
	GREEN,      //�΂҂�
	PURPLE,     //���҂�
	RED,        //�Ԃ҂�
	YELLOW,     //���҂�
	OJAMA,      //������܂҂�(�����I�Ɏ������邩���H)
	OUTSIDE     //�O�g�i�ǂƂ����j
};

enum GameScene {
	TITLE,
	INSTRUCTION,
	GAME,
	GAMEOVER,
	RESULT
};

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};
