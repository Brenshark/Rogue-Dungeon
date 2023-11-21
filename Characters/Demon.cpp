#include "Demon.h"

Demon::Demon() {
	setClassName("Demon");
	useWeapon.push_back(Possess);
}

Demon::Demon(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setClassName("Demon");
	useWeapon.push_back(Possess);
	setName(name);
	setStat(MAX_HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Demon::~Demon() {}