/*
/	@Author Nicole Dance
/   Assessment 2 - Battle Area Game
*/
#include <iostream>
//#include <random>
//#include <time.h>
#include <string>
#include "TeamMember.h"

const int NOERROR = 0;
const int WRONGSELECTION = 1;
const int INVALIDVALUE = 2;

// Headers
void PlayGame();

 int main() {
	bool playOn = true;
	int errorCode = NOERROR;
	while (playOn) {
		system("cls");
		int menuSelection = 0;
		
		switch(errorCode) {
			case WRONGSELECTION:
				std::cout << "ERROR -> Please enter ender a number between 1-2." << std::endl;
				break;
			case INVALIDVALUE:
				std::cout << "ERROR -> Please enter a numerical Value." << std::endl;
				break;
			default:
				break;
		}

		std::cout << "Menu" << std::endl;
		std::cout << "1. Start Game" << std::endl;
		std::cout << "2. Quit Game" << std::endl;
		std::cout << "-> ";

		std::cin >> menuSelection;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1);
			errorCode = INVALIDVALUE;
		}
		else {
			switch (menuSelection) {
				case 1:
					PlayGame();
					break;
				case 2:
					playOn = false;
					std::cout << "Thankyou for Playing. Good Bye" <<  std::endl;
					break;
				default:
					errorCode = WRONGSELECTION;
					break;
			}
		}
	}
	system("pause");
	return 0;
}

 void PlayGame() {
	 TeamMember teamOne[6];
	 TeamMember teamTwo[6];

	 teamOne[0].SetName("Iron Man");
	 teamOne[0].SetAttackName("Blaster"); 
	 teamOne[0].SetMaxAttack(10);
	 teamOne[0].SetMaxAttack(50);

	 teamOne[1].SetName("War Machine");
	 teamOne[1].SetAttackName("War");
	 teamOne[1].SetMaxAttack(10);
	 teamOne[1].SetMaxAttack(40);

	 teamOne[2].SetName("Black Widow");
	 teamOne[2].SetAttackName("kick");
	 teamOne[2].SetMaxAttack(15);
	 teamOne[2].SetMaxAttack(35);

	 teamOne[3].SetName("Black Panther");
	 teamOne[3].SetAttackName("Scratch");
	 teamOne[3].SetMaxAttack(25);
	 teamOne[3].SetMaxAttack(35);

	 teamOne[4].SetName("The Vision");
	 teamOne[4].SetAttackName("Zap");
	 teamOne[4].SetMaxAttack(30);
	 teamOne[4].SetMaxAttack(60);

	 teamOne[5].SetName("Spider-Man");
	 teamOne[5].SetAttackName("Web");
	 teamOne[5].SetMaxAttack(5);
	 teamOne[5].SetMaxAttack(25);

	 for (int i = 0; i < 6; i++)
	 {
		 std::cout << teamOne[i].GetName() << "/" << teamOne[i].GetAttackName() << "/" << teamOne[i].GetMaxAttack() << "/" << teamOne[i].GetMaxAttack() << std::endl;
	 }

	 system("pause");
	 //TeamMember* member = new TeamMember();
		 // Create 2 arrays  of TeamMember clases

		 // Member 1 of team 1 attacks random member of team 2
		 // Member 1 of team 2 attacks random member of team 1
		 // go thrugh all live team members 
		 // if member dies display msg to console

		 // Once end sort heros in decending health.

		 // Repeat until all team members in one team are dead
 }


 /*const int MAX = 10;
 std::default_random_engine dre(time(0));
 std::uniform_int_distribution<int> uid(0, MAX);

 uid(dre); // Generate random number

 // Second way
 srand(time(0));
 srand() % MAX;
  std::cout << "This is a Test"<< std::endl;
 */