#include "Archer.h"

Archer::Archer() {
	setClassName("Archer");
	useWeapon.push_back(BOW);
}

Archer::Archer(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setClassName("Archer");
	useWeapon.push_back(BOW);
	setName(name);
	setStat(MAX_HEALTH, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Archer::~Archer() {}