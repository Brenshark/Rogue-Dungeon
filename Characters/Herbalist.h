#pragma once
#include "CharacterSheet.h"

class Herbalist : public CharacterSheet {
public:
	Herbalist();
	Herbalist(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Herbalist();
};