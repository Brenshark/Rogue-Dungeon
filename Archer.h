#pragma once
#include "CharacterSheet.h"

class Archer : public CharacterSheet {
public:
	Archer();
	Archer(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Archer();
};