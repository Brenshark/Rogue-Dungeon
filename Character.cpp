#include "Character.h"

Char::Char() {}

Char::Char(string name, unsigned int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setName(name);
	setStat(abs(MAX_HEALTH), max_health);
	setStat(HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Char::~Char() {}

void Char::setStat(int stat, int value) {
	charStats[stat] = value;
}

void Char::setName(string charName) {
	name = charName;
}

void Char::calcAttackSpeed(Weapon* weapon){
	int weaponAffect = weapon->getWStats(WGT) - getStats(STR);
	if (weaponAffect < 0)
	{
		weaponAffect = 0;
	}
	attackSpeed = getStats(SPD) - weaponAffect;
}

void Char::calcAccuracy(Weapon* weapon){
	accuracy = weapon->getWStats(ACC) + 3 * getStats(PER);
}

void Char::calcDodge(){
	dodge =  getStats(PER) + getStats(SPD);
}

void Char::calcCritRate(Weapon* weapon){
	critRate = weapon->getWStats(CRT) + .5 * getStats(PER);
}

void Char::addWeapon(Weapon* weapon){
	weaponInventory.push_back(weapon);
}

void Char::setDead(bool dead){
	isDead = dead;
}