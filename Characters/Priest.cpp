#include "Priest.h"

Priest::Priest() {
	setClassName("Priest");
	useWeapon.push_back(HolyBook);
}

Priest::Priest(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setClassName("Priest");
	useWeapon.push_back(HolyBook);
	setName(name);
	setStat(MAX_HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Priest::~Priest() {}