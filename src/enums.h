#pragma once
enum State {
	VACANT,     //�҂悪����
	BLUE,       //�҂�
	GREEN,      //�΂҂�
	PURPLE,     //���҂�
	RED,        //�Ԃ҂�
	YELLOW,     //���҂�
	OJAMA,      //������܂҂�(�����I�Ɏ������邩���H)
	OUTSIDE     //�O�g�i�ǂƂ����j
};

enum Scene {
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

enum Dimension {
	X,
	Y,
	Z
};