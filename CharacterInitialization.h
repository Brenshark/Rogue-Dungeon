#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Battle.h"
#include "Weapons.h"
#include "Archer.h"
#include "Arbalist.h"
#include "Blacksmith.h"
#include "Knight.h"
#include "Priest.h"
#include "Demon.h"
#include "Paladin.h"
#include "Stargazer.h"
#include "Rogue.h"

using namespace std;

bool playerPhase = true; // Determines whether or not it is player phase
bool enemyPhase = false; // Determnies whether or not it is enemy phase
Battle* battle = new Battle; // Create Battle object
// Create units of different classes 
//max health, strength, intellegence, speed, magic defence, physical defense, perception
CharacterSheet* CrossbowMan = new Arbalist("Arbalist", 11, 10, 0, 4, 6, 5, 3);
CharacterSheet* BowMan = new Archer("Archer", 8, 8, 0, 5, 4, 3, 3);
CharacterSheet* Smithy = new Blacksmith("Blacksmith", 13, 14, 0, 4, 6, 6, 4);
CharacterSheet* Daem = new Demon("Demon", 15, 12, 5, 7, 4, 4, 1);
CharacterSheet* Night = new Knight("Knight", 15, 10, 0, 5, 6, 8, 4);
CharacterSheet* Aladin = new Paladin("Paladin", 13, 11, 5, 6, 12, 9, 3);
CharacterSheet* Rouge = new Rogue("Rouge", 7, 6, 0, 10, 3, 3, 5);
CharacterSheet* SpaceWalker = new Stargazer("Stargazer", 10, 7, 9, 7, 7, 5, 6);
CharacterSheet* Holy = new Priest("Priest", 10, 5, 12, 7, 7, 5, 6);
// Create weapons
//Weight, might, accuracy, critical, durability, weapon type, magic type, range
Weapon* Sword_and_Shield = new Weapon("Sword and Shield", 10, 5, 90, 0, 0,1, 1,2);
Weapon* Holy_Book = new Weapon("Holy Book", 5, 8, 85, 0, 1, 3, 3,4);
Weapon* Crossbow = new Weapon("Crossbow", 8, 7, 85, 0, 45, 2, 3,5);
Weapon* Bow = new Weapon("Bow", 5, 6, 85, 0, 45, 3, 3, 4);
Weapon* Dagger = new Weapon("Dagger", 4, 5, 90, 0, 40, 4, 0,1);
Weapon* Great_Hammer = new Weapon("Great Hammer",4, 5, 90, 0, 40, 4, 0,3);
Weapon* Hammer = new Weapon("Hammer",4, 5, 90, 0, 40, 4, 0, 2);
Weapon* Possess = new Weapon("Possession", 4, 5, 90, 0, 40, 4, 0, 4);
vector<CharacterSheet*> playerUnits = { CrossbowMan, Night, Rouge, Holy }; //Set User Characters
vector<CharacterSheet*> enemyUnits = { Aladin, Smithy, BowMan, Daem }; //Set Enemy Characters
vector<CharacterSheet*> inRangeUnits; // Stores the units in range of a specific unit
int playerUnitNum = playerUnits.size(); // Number of player units alive
int enemyUnitNum = enemyUnits.size(); // Number of enemy units alive

	void ChapterSetUp() { // Gives each unit a weapon
		CrossbowMan->addWeapon(Crossbow);
		Night->addWeapon(Sword_and_Shield);
		Rouge->addWeapon(Dagger);
		Holy->addWeapon(Holy_Book);
		Aladin->addWeapon(Great_Hammer);
		Smithy->addWeapon(Hammer);
		BowMan->addWeapon(Bow);
		Daem->addWeapon(Possess);
	}

	void switchPhase() { // Switches between player phase and enemy phase
		if (playerPhase){
			playerPhase = false;
			enemyPhase = true;
		}
		else if (enemyPhase){
			enemyPhase = false;
			playerPhase = true;
		}
	}

	void battleMenu(int& select) { // Outputs the possible unit actions
		std::cout << "1) Repeat Dialogue" << endl << "2) Attack" << endl << "3) View Stats" << endl << "4) Wait" << endl;
		cin >> select;
	}

	void unit1Attack(Char * unit1, Char * unit2, Weapon * weapon1, Weapon * weapon2, int acc, int crit){ // Determines whether unit1 hits and how much damage they do to unit2
		acc = 1 + (rand() % 100); // Generates a random number for the hit
		if (acc <= battle->getBattleAccuracy(1)){ // Checks to see if the hit number is less than or equal to the accuracy of the attack
			crit = 1 + (rand() % 100); // Generates a random number for the crit
			if (crit <= battle->getBattleCrit(1)){ // Checks to see if the crit number is less than or equal to the critical chance of the attack
				battle->setCritCoeff(3); // Sets the critical multiplier to 3
				battle->calcDamage(unit1, unit2, weapon1, weapon2);
			}
			unit2->setStat(HP, unit2->getStats(HP) - battle->getDamage(1));
			std::cout << unit1->getName() << " hit " << unit2->getName() << " for " << battle->getDamage(1) << " damage.\n";
			battle->setCritCoeff(1);
		}
		else{
			std::cout << unit1->getName() << " missed.\n";
		}
	}

	void unit2Attack(Char * unit1, Char * unit2, Weapon * weapon1, Weapon * weapon2, int hit, int crit){ // Determines whether unit2 hits and how much damage it does to unit1
		hit = 1 + (rand() % 100); // Generates a random number for the hit
		if (hit <= battle->getBattleAccuracy(2)){ // Checks to see if the crit number is less than or equal to the critical chance of the attack
			crit = 1 + (rand() % 100); // Generates a random number for the crit
			if (crit <= battle->getBattleCrit(2)){ // Checks to see if the crit number is less than or equal to the critical chance of the attack
				battle->setCritCoeff(3); // Sets the critical multiplier to 3
				battle->calcDamage(unit1, unit2, weapon1, weapon2);
			}
			unit1->setStat(abs(MAX_HEALTH), unit1->getStats(HP) - battle->getDamage(2));
			std::cout << unit2->getName() << " hit " << unit1->getName() << " for " << battle->getDamage(2) << " damage.\n";
			battle->setCritCoeff(1);
		}
		else{
			std::cout << unit2->getName() << " missed.\n";
		}
	}

	void unitAttack(CharacterSheet * unit1, CharacterSheet * unit2, Weapon * weapon1, Weapon * weapon2){ // Goes through combat, determines experience points, and which units die
		int hit = 0;
		int crit = 0;
		int unitNum = playerUnitNum;
		for (int i = 0; i < enemyUnitNum; i++) {
			if (unit1 == enemyUnits[i]) // Checks to see if the player or the enemy is attacking
			{
				unitNum = enemyUnitNum;
			}
		}
		srand((unsigned)time(NULL)); // Creates a new seed for rand()
		std::cout << endl;
		if (battle->getUnit1Double()) { // Checks to see if unit1 gets to attack twice
			unit1Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit2Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit1Attack(unit1, unit2, weapon1, weapon2, hit, crit);
		}
		else if (battle->getUnit2Double()) { //Checks to see if unit2 gets to attack twice
			unit2Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit1Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit2Attack(unit1, unit2, weapon1, weapon2, hit, crit);
		}
		else {
			unit1Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit2Attack(unit1, unit2, weapon1, weapon2, hit, crit);
		}
		if (unitNum == playerUnitNum) { //Checks to see if the player is attacking
			if (unit1->getStats(HP) <= 0) //Checks to see if the attacking unit has less than 0 HP
			{
				unit1->setDead(true); //Marks unit1 as dead
				playerUnitNum--; //Decreases the number of alive player units
			}
			if (unit2->getStats(HP) <= 0) { //Checks to see if the defending unit has less than 0 HP
				unit2->setDead(true); //Marks unit2 as dead
				enemyUnitNum--; //Decreases the number of alive player units
			}
		}
		else if (unitNum == enemyUnitNum){ //Checks to see if the enemy is attacking
			if (unit1->getStats(HP) <= 0){
				unit1->setDead(true);
				enemyUnitNum--;
			}
			if (unit2->getStats(HP) <= 0) {
				unit2->setDead(true);
				playerUnitNum--;
			}
		}
	}

	void viewStats(Char * unit, Weapon * weapon) { // Output the unit's stats and their weapon's stats
		std::cout << endl;
		std::cout << unit->getName() << endl;
		std::cout << "HP: " << unit->getStats(HP) << "/" << unit->getStats(abs(MAX_HEALTH)) << endl;
		std::cout << "Strength: " << unit->getStats(STR) << endl;
		std::cout << "Intellect: " << unit->getStats(INT) << endl;
		std::cout << "Speed: " << unit->getStats(SPD) << endl;
		std::cout << "Physical Defense: " << unit->getStats(PHY_DEF) << endl;
		std::cout << "Magic Defense: " << unit->getStats(MAG_DEF) << endl;
		std::cout << "Perception: " << unit->getStats(PER) << endl;
		std::cout << weapon->getWeaponName() << endl;
		std::cout << "Weight: " << weapon->getWStats(1) << endl;
		std::cout << "Might: " << weapon->getWStats(2) << endl;
		std::cout << "Hit: " << weapon->getWStats(3) << endl;
		std::cout << "Crit: " << weapon->getWStats(4) << endl;
		std::cout << endl;
	}

	void Phase(vector<CharacterSheet*> units, vector<CharacterSheet*> other_units, bool phase) { // Controls the phase
		int menuSelect = 0;
		CharacterSheet* target;
		char confirm;
		int unitNum;
		if (phase) {
			for (int i = 0; i < units.size(); i++){//Cycles through each of the units in the units vector

				if (!units[i]->getDead()){ //Checks to see if the unit at units[i] is dead
					menuSelect = 0;
					if (menuSelect != 1 || 2 || 3 || 4) {
						exit;
						cout << "Enter a valid number." << endl;
					}
					while (!(menuSelect == 2 || menuSelect == 4)){ // Checks to see that the unit hasn't attacked or waited
						std::cout << endl << units[i]->getName() << endl;
						battleMenu(menuSelect);
						switch (menuSelect){
						case 2:
							if (target = enemyUnits[i]){ // Checks to see that the target is not null
								battle->combatReport(units[i], target, units[i]->getWeapon(0), target->getWeapon(0)); // Output a preview of the battle
								cin >> confirm;
								while (!(confirm == 'A' || confirm == 'B')){ // Checks to see if the confirmation is valid
									std::cout << "Please confirm with A or back out with B.\n";
									cin >> confirm;
								}
								if (confirm == 'B'){
									menuSelect = 5; // Allows the unit to pick a different action
									inRangeUnits.clear(); // Clears the units that are in attacking range
									break;
								}
								unitAttack(units[i], target, units[i]->getWeapon(0), target->getWeapon(0));
							}
							inRangeUnits.clear(); // Clears the units that are in attacking range
							break;
						case 3:
							viewStats(units[i], units[i]->getWeapon(0));
							break;
						case 4:
							break;
						}
					}
					if (playerUnitNum == 0 || enemyUnitNum == 0){ // Checks to see if one side is completely defeated
						break;
					}
				}
			}
			switchPhase();
		}

	}