#pragma once
#include "CharacterSheet.h"

class Hound : public CharacterSheet {
public:
	Hound();
	Hound(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Hound();
};