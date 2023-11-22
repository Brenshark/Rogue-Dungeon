#include "Weapons.h"

Weapon::Weapon() {}

Weapon::Weapon(const char* name, int wgt, int mt, int acc, int crit, int dur, int range, int weapon, int magic) {
	setWeaponName(name);
	setWStat(WGT, wgt);
	setWStat(MT, mt);
	setWStat(ACC, acc);
	setWStat(CRT, crit);
	setWStat(DUR, dur);
	setWStat(WEAPON_TYPE, weapon);
	setWStat(MAGIC_TYPE, magic);
	setWStat(RANGE, range);
}

Weapon::~Weapon() {}

void Weapon::setWeaponName(const char* name) {
	nameWeapon = name;
}

void Weapon::setWeaponType(int weapon) {
	weaponType = weapon;
}

void Weapon::setMagicType(int magic) {
	magicType = magic;
}

void Weapon::setWStat(int stat, int value) {
	stats[stat] = value;
}
