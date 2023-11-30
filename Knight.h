#pragma once
#include "CharacterSheet.h"

class Knight : public CharacterSheet {
public:
	Knight();
	Knight(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Knight();
};