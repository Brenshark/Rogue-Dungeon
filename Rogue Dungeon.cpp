#include "Rogue Dungeon.h"
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "Characters/Character.h"
#include "Weapons.h"
#include "Characters/CharacterSheet.h"
#include "Battle.h"
#include "Map.h"
#include "CharacterInitialization.h"
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

int main(){
	cout << "1. Start Game" << endl << "2. Quit";
	int option;
	cin >> option;
	if (option == 1) {
		ChapterSetUp();
		while (playerUnitNum > 0 && enemyUnitNum > 0)
		{
			Phase(playerUnits, enemyUnits, playerPhase); // Player Phase
			Phase(enemyUnits, playerUnits, enemyPhase); // Enemy Phase
		}
		if (enemyUnitNum == 0)
		{
			cout << "Player wins!\n";
		}
		else if (playerUnitNum == 0)
		{
			cout << "Enemy wins!\n";
		}
	}
		else if(option == 2) {
		fclose;
	}
	
	}
