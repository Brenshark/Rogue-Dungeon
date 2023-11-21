#include "Herbalist.h"

Herbalist::Herbalist() {
	setClassName("Herbalist");
	useWeapon.push_back(DamagePotion);
	useWeapon.push_back(HealingPotion);
}

Herbalist::Herbalist(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setClassName("Herbalist");
	useWeapon.push_back(DamagePotion);
	useWeapon.push_back(HealingPotion);
	setName(name);
	setStat(MAX_HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Herbalist::~Herbalist() {}