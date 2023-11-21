#include "Stargazer.h"

Stargazer::Stargazer() {
	setClassName("Stargazer");
	useWeapon.push_back(Space Communicator);
}

Stargazer::Stargazer(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setClassName("Stargazer");
	useWeapon.push_back(Space Communicator);
	setName(name);
	setStat(MAX_HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Stargazer::~Stargazer() {}