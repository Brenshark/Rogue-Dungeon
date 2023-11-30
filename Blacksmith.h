#pragma once
#include "CharacterSheet.h"

class Blacksmith : public CharacterSheet {
public:
	Blacksmith();
	Blacksmith(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Blacksmith();
};