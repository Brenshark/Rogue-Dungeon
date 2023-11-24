#pragma once
#pragma once
#include "C:\Users\Brens\source\repos\Rogue Dungeon\Characters\Character.h"
#include "Weapons.h"

// Any variable with a 1 refers to the attacking unit, and any variable with a 2 refers to the defending unit
class Battle
{
public:
	Battle(); // Default Constructor
	~Battle(); // Deconstructor
	bool getUnit1Double() { return unit1Double; }
	bool getUnit2Double() { return unit2Double; }
	int getBattleAccuracy(int unitNum);
	int getBattleCrit(int unitNum);
	int getDamage(int unitNum);
	int calcNonlethalExperience(Char* unit1, Char* unit2); // Calculate the experience gained from damaging an enemy
	int calcLethalExperience(Char* unit1, Char* unit2); // Calculate the experience gained from killing an enemy
	void calcAttack(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2); // Calculate the attack power of unit1 and unit2
	void calcDamage(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2); // Calculate the damage from unit1 and unit2
	void calcBattleCrit(Char* unit1, Char* unit2); // Determine the critical hit chance of an attack
	void calcWeaponTriangle(Weapon* weapon1, Weapon* weapon2); // Determine who has the weapon triangle advantage
	void calcBattleAccuracy(Char* unit1, Char* unit2); // Determine the hit chance of an attack
	void combatReport(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2); // Output a preview of combat
	void canDouble(Char* unit1, Char* unit2); // Determine which, if either, unit1 or unit2 can double 
	void setCritCoeff(int value); // Set the critical damage multiplier
private:
	int attack1, attack2; // Attack power of the units
	int damage1, damage2; // Damage of the units
	unsigned int battleAccuracy1, battleAccuracy2; // Accuracy of the units
	int battleCrit1, battleCrit2; // Critical rate of the units
	int weaponTriangle1, weaponTriangle2; // Weapon Triangle advantage of the units
	int critCoeff; // Critical damage multiplier
	int distance; // Distance between two units
	bool unitRange[2]; // Whether or not two units are in range of each other
	bool unit1Double, unit2Double; // Whether or not unit1 or unit2 will be able to attack twice
};