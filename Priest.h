#pragma once
#include "CharacterSheet.h"

class Priest : public CharacterSheet {
public:
	Priest();
	Priest(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Priest();
};