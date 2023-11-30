#pragma once
#include "CharacterSheet.h"

class Rogue : public CharacterSheet {
public:
	Rogue();
	Rogue(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Rogue();
};