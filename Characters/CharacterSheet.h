#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class CharacterSheet : public Unit {
public:
	CharacterSheet();
	CharacterSheet(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per);
	~CharacterSheet();
	string getClassName() { return className; };
	void setClassName(string name);
	void LevelUp();
protected:
	string className;
	vector<int> useWeapon;
};