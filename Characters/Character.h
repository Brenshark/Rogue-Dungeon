#pragma once
#include <vector>
#include "Character.h"
#include <string>
#include "C:\Users\Brens\source\repos\Rogue Dungeon\Weapons.h"

using namespace std;

enum STATS {
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
	Char(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~Char() {};
	bool getHidden() { return this->isHidden; }
	bool getDead() { return this->isDead; }
	int getStat(int stat) { return this->charStats[stat]; }
	string getName() { return this->name; }
	int getAttackSpeed() { return this->attackSpeed; }
	int getAccuracy() { return this->accuracy; }
	int getDodge() { return this->dodge; }
	int getCritRate() { return this->critRate; }
	int getLevel() { return this->level; }
	int getExperience() { return this->exp; }
	Weapon* getWeapon(int index) { return this->weaponInventory[index]; }
	void setHidden(bool hidden);
	void setStat(int stat, int value); // Set a stat
	void setName(string name); // Set the unit's name
	void setLevel(int lvl); // Set the unit's level
	void calcAttackSpeed(Weapon* weapon); // Calculate the unit's attack speed
	void calcAccuracy(Weapon* weapon); // Calculate the unit's accuracy
	void calcDodge(); // Calculate the unit's avoid
	void calcCritRate(Weapon* weapon); // Calculate the unit's critical hit rate
	void addWeapon(Weapon* weapon); // Add a weapon to the unit's inventory
	void setExperience(int value); // Set the experience of the unit
	void setDead(bool dead); // Set whether or not the unit is dead
protected:
	bool isHidden = false;
	bool isDead = false;
	_int8 charStats[8];
	string name;
	int attackSpeed; // Unit's attack speed
	int accuracy; // Unit's accuracy of attacking
	int dodge; // Unit's ability to dodge attacks
	unsigned int critRate; // Unit's chance of scoring a critical hit
	int level = 1; // Unit's level
	unsigned _int8 exp = 0; // Current amount of experience
	vector<Weapon*> weaponInventory; // Unit's inventory of weapons
};