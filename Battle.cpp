#include "Battle.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

// unit1 refers to the attacking unit, and unit2 refers to the defending unit

Battle::Battle(){}

Battle::~Battle(){}

int Battle::getBattleAccuracy(int unitNum){ // Returns the battle accuracy based on the unitNum
	int batAcc;
	if (unitNum == 1)
	{
		batAcc = battleAccuracy1;
	}
	else
	{
		batAcc = battleAccuracy2;
	}
	return batAcc;
}

int Battle::getBattleCrit(int unitNum){ // Returns the battle crit rate based on the unitNum
	int batCrit;
	if (unitNum == 1)
	{
		batCrit = battleCrit1;
	}
	else
	{
		batCrit = battleCrit2;
	}
	return batCrit;
}

int Battle::getDamage(int unitNum){ // Returns the damage based on the unitNum
	int batDam;
	if (unitNum == 1)
	{
		batDam = damage1;
	}
	else
	{
		batDam = damage2;
	}
	return batDam;
}

void Battle::calcAttack(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2){ // Determines the attacking power
	if (weapon1->getWeaponType() == HOLYBOOK || SPACEINTERFERENCE){ // If the weapon type is TOME, MAG will be used to determine attack power
		attack1 = unit1->getStats(INT) + (weapon1->getWStats(MT) + weaponTriangle1);
	}
	else{ // All other weapon types use STR to determine attack power
		attack1 = unit1->getStats(STR) + (weapon1->getWStats(MT) + weaponTriangle1);
	}
	if (weapon2->getWeaponType() == HOLYBOOK || SPACEINTERFERENCE){
		attack2 = unit2->getStats(INT) + (weapon2->getWStats(MT) + weaponTriangle2);
	}
	else{
		attack2 = unit2->getStats(STR) + (weapon2->getWStats(MT) + weaponTriangle2);
	}
}

void Battle::calcDamage(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2) // Calculates damage done to both units
{
	if (weapon1->getWeaponType() == HOLYBOOK || SPACEINTERFERENCE){ // If the weapon type is TOME, RES will be used to decrease the damage
		damage1 = (attack1 - unit2->getStats(MAG_DEF)) * critCoeff;
	}
	else{ // All other weapon types will be decreased by DEF 
		damage1 = (attack1 - unit2->getStats(PHY_DEF)) * critCoeff;
	}
	if (weapon2->getWeaponType() == HOLYBOOK || SPACEINTERFERENCE){
		damage2 = (attack2 - unit1->getStats(MAG_DEF)) * critCoeff;
	}
	else{
		damage2 = (attack2 - unit1->getStats(PHY_DEF)) * critCoeff;
	}
	if (damage1 < 0){ // Sets minimum damage to 0
		damage1 = 0;
	}
	if (damage2 < 0){ // Sets minimum damage to 0
		damage2 = 0;
	}
}

void Battle::calcBattleCrit(Char* unit1, Char* unit2){ // Determine the critical hit chance
	battleCrit1 = unit1->getCritRate() - unit2->getStats(PER);
	battleCrit2 = unit2->getCritRate() - unit1->getStats(PER);
	if (battleCrit1 < 0){ // Sets battleCrit1 to 0 if it is below 0
		battleCrit1 = 0;
	}
	else if (battleCrit2 < 0){ // Sets battleCrit2 to 0 if it is below 0
		battleCrit2 = 0;
	}
}

void Battle::calcWeaponTriangle(Weapon* weapon1, Weapon* weapon2){ // Calculates weapon triangle advantage
	// The weapon triangle is like rock, paper, scissors. Swords beat axes, axes beat lances, and lances beat swords.
	// There is a magical weapon triangle. Anima beats light, light beats dark, and dark beats anima.
	if ((weapon1->getWStats(WEAPON_TYPE) == 0 && weapon2->getWStats(WEAPON_TYPE) == 1) || (weapon1->getWStats(WEAPON_TYPE) == 1 && weapon2->getWStats(WEAPON_TYPE) == 2) || (weapon1->getWStats(WEAPON_TYPE) == 2 && weapon2->getWStats(WEAPON_TYPE) == 0)){	
		weaponTriangle1 = 1;
		weaponTriangle2 = -1;
	}
	else if ((weapon1->getWStats(WEAPON_TYPE) == 1 && weapon2->getWStats(WEAPON_TYPE) == 0) || (weapon1->getWStats(WEAPON_TYPE) == 2 && weapon2->getWStats(WEAPON_TYPE) == 1) || (weapon1->getWStats(WEAPON_TYPE) == 0 && weapon2->getWStats(WEAPON_TYPE) == 2)){
		weaponTriangle1 = -1;
		weaponTriangle2 = 1;
	}
	else if ((weapon1->getWStats(MAGIC_TYPE) == 0 && weapon2->getWStats(MAGIC_TYPE) == 1) || (weapon1->getWStats(MAGIC_TYPE) == 1 && weapon2->getWStats(MAGIC_TYPE) == 2) || (weapon1->getWStats(MAGIC_TYPE) == 2 && weapon2->getWStats(MAGIC_TYPE) == 0)){
		weaponTriangle1 = 1;
		weaponTriangle2 = -1;
	}
	else if ((weapon1->getWStats(MAGIC_TYPE) == 1 && weapon2->getWStats(MAGIC_TYPE) == 0) || (weapon1->getWStats(MAGIC_TYPE) == 2 && weapon2->getWStats(MAGIC_TYPE) == 1) || (weapon1->getWStats(MAGIC_TYPE) == 0 && weapon2->getWStats(MAGIC_TYPE) == 2)){
		weaponTriangle1 = -1;
		weaponTriangle2 = 1;
	}
	else{
		weaponTriangle1 = weaponTriangle2 = 0;
	}
}

void Battle::calcBattleAccuracy(Char* unit1, Char* unit2) { // Calculates the battle accuracy for both units
	battleAccuracy1 = unit1->getAccuracy() - unit2->getDodge() + 15 * weaponTriangle1;
	battleAccuracy2 = unit2->getAccuracy() - unit1->getDodge() + 15 * weaponTriangle2;
	if (battleAccuracy1 > 100){ // Sets battleAccuracy1 to 100 if it goes over 100
		battleAccuracy1 = 100;
	}
	else if (battleAccuracy2 > 100){ // Sets battleAccuracy2 to 100 if it goes over 100
		battleAccuracy2 = 100;
	}
}

void Battle::combatReport(Char* unit1, Char* unit2, Weapon* weapon1, Weapon* weapon2){ // Output a preview of combat
	critCoeff = 1;
	unit1->calcAttackSpeed(weapon1); // Calculates unit1's attack speed
	unit1->calcAccuracy(weapon1); // Calcultates unit1's accuracy
	unit1->calcDodge(); // Calculates unit1's avoid
	unit1->calcCritRate(weapon1); // Calculates unit1's crit rate
	unit2->calcAttackSpeed(weapon2); // Calculates unit2's attack speed
	unit2->calcAccuracy(weapon2); // Calculates unit2's accuracy
	unit2->calcDodge(); // Calculates unit2's avoid
	unit2->calcCritRate(weapon2); // Calculates unit2's crit rate
	canDouble(unit1, unit2); // Determines which unit can double attack
	calcWeaponTriangle(weapon1, weapon2); // Determines weapon triangle advantage
	calcBattleAccuracy(unit1, unit2); // Determines battle accuracy
	calcBattleCrit(unit1, unit2); // Determines battle crit rate
	calcAttack(unit1, unit2, weapon1, weapon2); // Determines attack of units
	calcDamage(unit1, unit2, weapon1, weapon2); // Determines damage of units

	std::cout << unit1->getName() << " vs " << unit2->getName() << endl; // Output the battle stats for unit1 and unit2
	std::cout << "HP: " << unit1->getStats(abs(HP)) << " vs " << unit2->getStats(abs(HP)) << endl;
	if (unit1Double){
		std::cout << "Mt: " << damage1 << " x 2 vs " << damage2 << endl;
	}
	else if (unit2Double){
		std::cout << "Mt: " << damage1 << " vs " << damage2 << " x 2" << endl;
	}
	else{
		std::cout << "Mt: " << damage1 << " vs " << damage2 << endl;
	}
	std::cout << "Hit: " << battleAccuracy1 << " vs " << battleAccuracy2 << endl;
	std::cout << "Crit: " << battleCrit1 << " vs " << battleCrit2 << endl;
	std::cout << "A) Continue B) Back" << endl;
}

void Battle::canDouble(Char* unit1, Char* unit2){ // Determine which, if either, units can double attack
	// If a unit's attack speed is 4 or more than its opponent's, then the unit can double
	if (unit1->getAttackSpeed() - unit2->getAttackSpeed() >= 4){
		unit1Double = true;
		unit2Double = false;
	}
	else if (unit2->getAttackSpeed() - unit1->getAttackSpeed() >= 4){
		unit2Double = true;
		unit1Double = false;
	}
	else{
		unit1Double = false;
		unit2Double = false;
	}
}

void Battle::setCritCoeff(int value){ // Set the critical damage multiplier
	critCoeff = value;
}