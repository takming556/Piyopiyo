#include "DxLib.h"
#include "class.h"

VanishEffect::VanishEffect() {
	int now_count = GetNowCount();
	time_elapsed_from_started_vanishing = GetNowCount() - now_count;
}


void VanishEffect::draw() {
	int 
}