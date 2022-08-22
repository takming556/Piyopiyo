#pragma once
#include <valarray>
#include "enums.h"

using std::valarray;

//定数たち
const bool DebugFlag = false;                   //trueにすると「空」「外」などの表示がされる
const bool AutoPiyoFallFlag = true;             //falseにするとぴよは手動でのみ落下するようになる

const unsigned int SCREEN_RESOLUTION_X = 1024;      //画面解像度X
const unsigned int SCREEN_RESOLUTION_Y = 768;       //画面解像度Y

const valarray<int> upward{ 0,-1 };
const valarray<int> rightward{ 1,0 };
const valarray<int> downward{ 0,1 };
const valarray<int> leftward{ -1,0 };