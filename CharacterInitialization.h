#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Battle.h"
#include "Weapons.h"
#include "Characters/Archer.h"
#include "Characters/Arbalist.h"
#include "Characters/Blacksmith.h"
#include "Characters/Knight.h"
#include "Characters/Priest.h"
#include "Characters/Demon.h"
#include "Characters/Paladin.h"
#include "Characters/Stargazer.h"
#include "Characters/Rogue.h"

using namespace std;

bool playerPhase = true; // Determines whether or not it is player phase
bool enemyPhase = false; // Determnies whether or not it is enemy phase
Battle* battle = new Battle; // Create Battle object
// Create units of different classes 
//max health, strength, intellegence, speed, magic defence, physical defense, perception
CharacterSheet* Arbalist = new Arbalist("Arbalist", 16, 7, 0, 4, 6, 5, 3);
CharacterSheet* Archer = new Archer("Archer", 13, 4, 0, 7, 6, 4, 3);
CharacterSheet* Blacksmith = new Blacksmith("Blacksmith", 20, 9, 0, 4, 8, 8, 4);
CharacterSheet* Demon = new Demon("Demon", 25, 10, 5, 7, 5, 5, 1);
CharacterSheet* Knight = new Knight("Knight", 25, 8, 0, 5, 8, 10, 4);
CharacterSheet* Paladin = new Paladin("Paladin", 20, 9, 5, 6, 12, 9, 3);
CharacterSheet* Rogue = new Rogue("Rogue", 15, 4, 0, 10, 5, 5, 3, 8);
CharacterSheet* Stargazer = new Stargazer("Stargazer", 17, 5, 9, 7, 9, 7, 4);
CharacterSheet* Priest = new Priest("Priest", 17, 3, 12, 7, 9, 7, 4);
// Create weapons
//Weight, mt, accuracy, critical, durability, weapon type, magic type, range
Weapon* Sword_and_Shield = new Weapon("Sword and Shield", 1, 5, 5, 90, 0, 46, 0, 1);
Weapon* Holy_Book = new Weapon("Holy Book", 1, 10, 8, 75, 0, 45, 1, 3);
Weapon* Crossbow = new Weapon("Crossbow", 1, 8, 7, 80, 0, 45, 2, 3);
Weapon* Bow = new Weapon("Bow", 2, 5, 6, 85, 0, 45, 3, 3);
Weapon* Dagger = new Weapon("Dagger", 2, 4, 5, 90, 0, 40, 4, 0);
Weapon* Great_Hammer = new Weapon("Great Hammer", 2, 4, 5, 90, 0, 40, 4, 0);
Weapon* Hammer = new Weapon("Hammer", 2, 4, 5, 90, 0, 40, 4, 0);
Weapon* Possess = new Weapon("Possession", 2, 4, 5, 90, 0, 40, 4, 0);
vector<CharacterSheet*> playerUnits = { Arbalist, Knight, Rogue, Priest }; // Stores the units on the player team
vector<CharacterSheet*> enemyUnits = { Paladin, Blacksmith, Archer, Demon }; // Stores the units on the enemy team
vector<CharacterSheet*> inRangeUnits; // Stores the units in range of a specific unit
int playerUnitNum = playerUnits.size(); // Number of player units alive
int enemyUnitNum = enemyUnits.size(); // Number of enemy units alive

	void ChapterSetUp() { // Sets up the units' initial position and gives each unit a weapon
		Arbalist->addWeapon(Crossbow);
		Knight->addWeapon(Sword_and_Shield);
		Rogue->addWeapon(Dagger);
		Priest->addWeapon(Holy_Book);
		Paladin->addWeapon(Great_Hammer);
		Blacksmith->addWeapon(Hammer);
		Archer->addWeapon(Bow);
		Demon->addWeapon(Possess);
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

	void battleMenu(int& select) { // Outputs the menu of possible unit actions
		std::cout << "1) Move" << endl << "2) Attack" << endl << "3) View Stats" << endl << "4) Wait" << endl;
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
			unit1->setStat(HP, unit1->getStats(HP) - battle->getDamage(2));
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
		else if (battle->getUnit2Double()) { // Checks to see if unit2 gets to attack twice
			unit2Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit1Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit2Attack(unit1, unit2, weapon1, weapon2, hit, crit);
		}
		else {
			unit1Attack(unit1, unit2, weapon1, weapon2, hit, crit);
			unit2Attack(unit1, unit2, weapon1, weapon2, hit, crit);
		}
		if (unitNum == playerUnitNum){ // Checks to see if the player is attacking
			if (unit1->getStats(HP) <= 0) // Checks to see if the attacking unit has less than 0 HP
			{
				unit1->setDead(true); // Marks unit1 as dead
				playerUnitNum--; // Decreases the number of alive player units
				unit2->setExperience(unit2->getExperience() + battle->calcLethalExperience(unit2, unit1)); // Adds experience for killing a unit
			}
			if (unit2->getStats(HP) <= 0){ // Checks to see if the defending unit has less than 0 HP
				unit2->setDead(true); // Marks unit2 as dead
				enemyUnitNum--; // Decreases the number of alive player units
				unit1->setExperience(unit1->getExperience() + battle->calcLethalExperience(unit1, unit2)); // Adds experience for killing a unit
			}
			else{
				unit1->setExperience(unit1->getExperience() + battle->calcNonlethalExperience(unit1, unit2)); // Adds experience for damaging a unit
				unit2->setExperience(unit2->getExperience() + battle->calcNonlethalExperience(unit2, unit1)); // Adds experience for damaging a unit
			}
		}
		else if (unitNum == enemyUnitNum){ // Checks to see if the enemy is attacking
			if (unit1->getStats(HP) <= 0){
				unit1->setDead(true);
				enemyUnitNum--;
				unit2->setExperience(unit2->getExperience() + battle->calcLethalExperience(unit2, unit1));
			}
			if (unit2->getStats(HP) <= 0) {
				unit2->setDead(true);
				playerUnitNum--;
				unit1->setExperience(unit1->getExperience() + battle->calcLethalExperience(unit1, unit2));
			}
			else {
				unit1->setExperience(unit1->getExperience() + battle->calcNonlethalExperience(unit1, unit2));
				unit2->setExperience(unit2->getExperience() + battle->calcNonlethalExperience(unit2, unit1));
			}
		}
		if (unit1->getExperience() >= 100) { // Checks to see if unit1 has reached the necessary 100 exp in order to level up{
			unit1->LevelUp(); // Unit1 levels up
			unit1->setExperience(unit1->getExperience() - 100); // Resets unit1's experience 
			std::cout << unit1->getName() << " leveled up to level " << unit1->getLevel() << endl;
		}
		if (unit2->getExperience() >= 100) { // Checks to see if unit2 has reached the necessary 100 exp in order to level up
			unit2->LevelUp(); // Unit2 levels up
			unit2->setExperience(unit1->getExperience() - 100); // Resets unit2's experience
			std::cout << unit2->getName() << " leveled up to level " << unit2->getLevel() << endl;
		}
	}

	void viewStats(Char * unit, Weapon * weapon) { // Output the unit's stats and their weapon's stats
		std::cout << endl;
		std::cout << unit->getName() << endl;
		std::cout << "HP: " << unit->getStats(HP) << "/" << unit->getStats(MAX_HEALTH) << endl;
		std::cout << "Strength: " << unit->getStats(STR) << endl;
		std::cout << "Magic: " << unit->getStats(INT) << endl;
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
			if (phase == playerPhase) {
				std::cout << "Player Phase\n";
			}
			else {
				std::cout << "Enemy Phase\n";
			}
			for (int i = 0; i < units.size(); i++) { // Cycles through each of the units in the units vector
				if (!units[i]->getDead()) { // Checks to see if the unit at units[i] is dead
					switchPhase();
				}
			}
		}
	}