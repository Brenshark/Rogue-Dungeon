#include "CharacterSheet.h"

using namespace std;

CharacterSheet::CharacterSheet() {}
CharacterSheet::CharacterSheet(string name, unsigned int max_health, int str, int intel, int spd, int m_def, int p_def, int per) {
	setName(name); //name
	setStat(abs(MAX_HEALTH),max_health); //max health
	setStat(STR,str); //strength
	setStat(INT,intel); //intellegence
	setStat(SPD,spd); //speed
	setStat(MAG_DEF,m_def); //magic defense
	setStat(PHY_DEF,p_def); //physical defense
	setStat(PER,per); //perception
}
CharacterSheet::~CharacterSheet() {}

void CharacterSheet::setClassName(string name) {
	className = name;
}

void LevelUp(int exp, int max_exp, int level) { //levels up when reaching max experience
	if (exp = max_exp) {
		level++;
	}
}
