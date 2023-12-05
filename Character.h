#pragma once
#include <vector>
#include "Character.h"
#include <string>
#include "Weapons.h"

using namespace std;

enum CHARSTATS {
	MAX_HEALTH,
	HP,
	STR,
	INT,
	SPD,
	MAG_DEF,
	PHY_DEF,
	PER
};

class Char {
public:
	Char();
	Char(string name, unsigned int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Char();
	bool getDead() { return this->isDead; }
	int getStats(int stat) { return this->charStats[stat]; }
	string getName() { return this->name; }
	int getAttackSpeed() { return this->attackSpeed; }
	int getAccuracy() { return this->accuracy; }
	int getDodge() { return this->dodge; }
	int getCritRate() { return this->critRate; }
	Weapon* getWeapon(int index) { return this->weaponInventory[index]; }
	void setStat(int stat, int value); // Set a stat
	void setName(string name); // Set the unit's name
	void calcAttackSpeed(Weapon* weapon); // Calculate the unit's attack speed
	void calcAccuracy(Weapon* weapon); // Calculate the unit's accuracy
	void calcDodge(); // Calculate the unit's dodge chance
	void calcCritRate(Weapon* weapon); // Calculate the unit's critical hit rate
	void addWeapon(Weapon* weapon); // Add a weapon to the unit's inventory
	void setDead(bool dead); // Set whether or not the unit is dead
protected:
	bool isDead = false;
	_int8 charStats[8];
	string name;
	int attackSpeed; // Unit's attack speed
	int accuracy; // Unit's accuracy of attacking
	int dodge; // Unit's ability to dodge attacks
	unsigned int critRate; // Unit's chance of scoring a critical hit
	vector<Weapon*> weaponInventory; // Unit's inventory of weapons
};