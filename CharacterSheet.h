#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Character.h"
#include "C:\Users\Brens\source\repos\Rogue Dungeon\Weapons.h"

using namespace std;

class CharacterSheet : public Char {
public:
	CharacterSheet();
	CharacterSheet(string name, unsigned int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~CharacterSheet();
	string getClassName() { return className; };
	void setClassName(string name);
protected:
	string className;
	vector<int> useWeapon;
};