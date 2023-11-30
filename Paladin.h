#pragma once
#include "CharacterSheet.h"

class Paladin : public CharacterSheet {
public:
	Paladin();
	Paladin(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Paladin();
};