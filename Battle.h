#pragma once
#pragma once
#include "Character.h"
#include "Weapons.h"

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
	void calcAttack(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2); // Calculate the attack power
	void calcDamage(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2); // Calculate the damage
	void calcBattleCrit(Char* unit1, Char* unit2); // Determine the critical hit chance of an attack
	void calcBattleAccuracy(Char* unit1, Char* unit2); // Determine the hit chance of an attack
	void combatReport(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2); // Output a preview of combat
	void canDouble(Char* unit1, Char* unit2); // Determine which, if either, unit1 or unit2 can double 
	void setCritCoeff(int value); // Set the critical damage multiplier
private:
	int attack1, attack2; // Attack power of the units
	int damage1, damage2; // Damage of the units
	unsigned int battleAccuracy1, battleAccuracy2; // Accuracy of the units
	int battleCrit1, battleCrit2; // Critical rate of the units
	int critCoeff; // Critical damage multiplier
	bool unitRange[2]; // Whether or not two units are in range of each other
	bool unit1Double, unit2Double; // Whether or not unit1 or unit2 will be able to attack twice
};