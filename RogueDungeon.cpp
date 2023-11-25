#include "RogueDungeon.h"
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
void outcome() {
	while (playerUnitNum > 0 && enemyUnitNum > 0){
		Phase(playerUnits, enemyUnits, playerPhase); // Battle
		Phase(enemyUnits, playerUnits, enemyPhase); 
	}
	if (enemyUnitNum == 0){
		cout << "Player wins!\n";
		exit;
	}
	else if (playerUnitNum == 0){
		cout << "Enemy wins!\n";
		quick_exit;
	}
}
int main(){ //Introduction to game
	cout << "1. Start Game" << endl << "2. Quit" << endl;
	int option;
	cin >> option;
	if (option == 1) {	
		ChapterSetUp(); //Sets-up initial battle
		outcome();
		cout << "A. Continue Forward"<< endl; //Continue through the map
		string direction;
		cin >> direction;
		if (direction == "A") {
			ChapterSetUp(); //Sets-up next battle
			outcome(); 
			cout << "A. Continue Forward" << endl; //Continue to first fork in the route
			cin >> direction;
			if (direction == "A") {
				ChapterSetUp();
				outcome();
				cout << "A. Continue Foward" << endl << "B. Go to the Right" << endl; //choose path
				cin >> direction;
			}
			if (direction == "A") {
				ChapterSetUp();
				outcome();
				cout << "B. Return to main path" << endl;
					cin >> direction;
			}
			if (direction == "B") {
				ChapterSetUp();
				outcome();
				cout << "A. Advance Forward" << endl;
				cin >> direction;
				if (direction == "A") {
					ChapterSetUp();
					outcome();
					cout << "A. Advance Forward" << endl;
					cin >> direction;
					if (direction == "A") {
						ChapterSetUp();
						outcome();
						cout << "A. Advance Forward" << endl << "B. Turn Left" << endl; // second fork/choose path

						cin >> direction;
						if (direction == "B") {
							ChapterSetUp();
							outcome();
							cout << "A. Return to main path" << endl;
							cin >> direction;
						}
						if (direction == "A") {
							ChapterSetUp();
							outcome();
							cout << "A. Turn right" << endl;
							cin >> direction;
							if (direction == "A") {
								ChapterSetUp();
								outcome();
								cout << "CONGRATULATIONS! YOU HAVE COMPLETED ALL THAT IS AVAILABLE!" << endl;
							}
						}
					}
				}
			}
		}

		while (playerUnitNum > 0 && enemyUnitNum > 0){
			Phase(playerUnits, enemyUnits, playerPhase); // Player Phase
			Phase(enemyUnits, playerUnits, enemyPhase); // Enemy Phase
		}
		if (enemyUnitNum == 0){
			cout << "Player wins!\n";
		}
		else if (playerUnitNum == 0){
			cout << "Enemy wins!\n";
		}
	}
		else if(option == 2) {
		return 0;
	}
	
	}
