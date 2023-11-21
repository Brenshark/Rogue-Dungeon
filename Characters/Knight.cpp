#include "Knight.h"

Knight::Knight() {
	setClassName("Knight");
	useWeapon.push_back(SwordShield);
}

Knight::Knight(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setClassName("Knight");
	useWeapon.push_back(SwordShield);
	setName(name);
	setStat(MAX_HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Knight::~Knight() {}