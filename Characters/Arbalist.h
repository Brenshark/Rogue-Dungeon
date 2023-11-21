#pragma once
#include "CharacterSheet.h"

class Arbalist : public CharacterSheet {
public:
	Arbalist();
	Arbalist(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Arbalist();
};