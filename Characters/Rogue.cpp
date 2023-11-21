#include "Rogue.h"

Rogue::Rogue() {
	setClassName("Rogue");
	useWeapon.push_back(Dagger);
}

Rogue::Rogue(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setClassName("Rogue");
	useWeapon.push_back(Dagger);
	setName(name);
	setStat(MAX_HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Rogue::~Rogue() {}