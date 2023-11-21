#include "Character.h"

Char::Char() {}

Char::Char(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setName(name);
	setStat(MAX_HEALTH, max_health);
	setStat(HP, max_health);
	setStat(STR, str);
	setStat(INT, intel);
	setStat(SPD, spd);
	setStat(MAG_DEF, m_def);
	setStat(PHY_DEF, p_def);
	setStat(PER, per);
}

Char::~Char() {}

void Char::setHidden(bool hidden) {
	isHidden = hidden;
}

void Char::setStat(int stat, int value) {
	charStats[stat] = value;
}

void Char::setName(string charName) {
	name = charName;
}

void Char::setLevel(int lvl) {
	level = lvl;
}

void Char::calcAttackSpeed(Weapon* weapon){
	int weaponAffect = weapon->getProperty(WGT) - getStat(STR);
	if (weaponAffect < 0)
	{
		weaponAffect = 0;
	}
	attackSpeed = getStat(SPD) - weaponAffect;
}

void Char::calcAccuracy(Weapon* weapon){
	accuracy = weapon->getProperty(ACC) + 2 * getStat(PER);
}

void Char::calcAvoid(){
	avoid = 2 * attackSpeed + getStat(PER);
}

void Char::calcCritRate(Weapon* weapon){
	critRate = weapon->getProperty(CRT) + .5 * getStat(PER);
}

void Char::addWeapon(Weapon* weapon){
	weaponInventory.push_back(weapon);
}

void Char::setExperience(int value){
	exp = value;
}

void Char::setDead(bool dead){
	isDead = dead;
}