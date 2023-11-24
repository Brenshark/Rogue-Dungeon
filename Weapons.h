#pragma once

enum WEAPONS {
	SWORDSHIELD,
	CROSSBOW,
	BOW,
	HAMMER,
	GREATHAMMER,
	POSSESS,
	BITE,
	DAMAGEPOTION,
	HEALINGPOTION,
	DAGGER,
	HOLYBOOK,
	SPACEINTERFERENCE
};

enum MAGIC {
	SPACE,
	HOLY,
	DARK
};

enum STATS {
	WGT,
	MT,
	ACC,
	CRT,
	DUR,
	WEAPON_TYPE,
	MAGIC_TYPE,
	RANGE
};

class Weapon {
public:
	Weapon();
	Weapon(const char* name, int wgt, int mt, int acc, int crit, int dur, int range, int weapon, int magic);
	~Weapon();
	const char* getWeaponName() { return this->nameWeapon; }
	int getWeaponType() { return this->weaponType; }
	int getMagicType() { return this->magicType; }
	int getWStats(int stat) { return this->stats[stat]; }
	void setWeaponName(const char* name);
	void setWeaponType(int weapon);
	void setMagicType(int magic);
	void setWStat(int stat, int value);
private:
	const char* nameWeapon; // Weapon's name
	int stats[8] = {WGT , MT , ACC, CRT, DUR, WEAPON_TYPE , MAGIC_TYPE , RANGE }; // Weapon stats
	int weaponType; // Weapon Type
	int magicType; // Magic Type
};