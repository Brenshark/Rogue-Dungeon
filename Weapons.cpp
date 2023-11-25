#include "Weapons.h"

Weapon::Weapon() {}

Weapon::Weapon(const char* name, int wgt, int mt, int acc, int crit, int dur, int weapon, int magic, int range ) {
	setWeaponName(name); //name of weapon
	setWStat(WGT, wgt); //weight of weapon
	setWStat(MT, mt); //might of weapon
	setWStat(ACC, acc); //accuracy of weapon
	setWStat(CRT, crit); //critical chance of weapon
	setWStat(DUR, dur); //durability/ammo of weapon
	setWStat(WEAPON_TYPE, weapon); //melee weapon type
	setWStat(MAGIC_TYPE, magic); //magic weapon type
	setWStat(RANGE, range); //effective range of weapon
}

Weapon::~Weapon() {}

void Weapon::setWeaponName(const char* name) { //sets name
	nameWeapon = name;
}

void Weapon::setWeaponType(int weapon) { //sets melee type
	weaponType = weapon;
}

void Weapon::setMagicType(int magic) { //sets magic type
	magicType = magic;
}

void Weapon::setWStat(int stat, int value) { //sets each stat value in vector
	stats[stat] = value;
}
