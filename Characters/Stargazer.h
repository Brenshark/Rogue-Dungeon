#pragma once
#include "CharacterSheet.h"

class Stargazer : public CharacterSheet {
public:
	Stargazer();
	Stargazer(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Stargazer();
};