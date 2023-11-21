#include <iostream>
#include <vector>
#include "CharacterSheet.h"
using namespace std;

CharacterSheet::CharacterSheet() {}
CharacterSheet::CharacterSheet(string name, int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setName(name);
	setStat(MAX_HP,max_health);
	setStat(STR,str);
	setStat(INT,intel);
	setStat(SPD,spd);
	setStat(MAG_DEF,m_def);
	setStat(PHY,p_def);
	setStat(PER,per);
}
CharacterSheet::~CharacterSheet() {}

void CharacterSheet::setClassName(string name) {
	className = name;
}

void CharacterSheet::LevelUp() {
}