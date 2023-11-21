#pragma once
#include "CharacterSheet.h"

class Demon : public CharacterSheet {
public:
	Demon();
	Demon(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Demon();
};