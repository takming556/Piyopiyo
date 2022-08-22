#pragma once
#include <valarray>
#include "enums.h"

using std::valarray;

//�萔����
const bool DebugFlag = false;                   //true�ɂ���Ɓu��v�u�O�v�Ȃǂ̕\���������
const bool AutoPiyoFallFlag = true;             //false�ɂ���Ƃ҂�͎蓮�ł̂ݗ�������悤�ɂȂ�

const unsigned int SCREEN_RESOLUTION_X = 1024;      //��ʉ𑜓xX
const unsigned int SCREEN_RESOLUTION_Y = 768;       //��ʉ𑜓xY

const valarray<int> upward{ 0,-1 };
const valarray<int> rightward{ 1,0 };
const valarray<int> downward{ 0,1 };
const valarray<int> leftward{ -1,0 };