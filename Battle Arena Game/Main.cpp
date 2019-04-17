/*
/	@Author Nicole Dance
/   Assessment 2 - Battle Area Game
*/
#include <iostream>
//#include <random>
//#include <time.h>
//#include <string>
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
		std::cout << " ################################################################################# " << std::endl;
		std::cout << "###                                                                             ###" << std::endl;
		std::cout << "##     BBBB   AAA  TTTTT TTTTT L     EEEEE      AAA  RRRR  EEEEE N   N  AAA      ##" << std::endl;
		std::cout << "##     B   B A   A   T     T   L     E         A   A R  RR E     NN  N A   A     ##" << std::endl;
		std::cout << "##     BBBB  AAAAA   T     T   L     EEEEE     AAAAA RRRR  EEEEE N N N AAAAA     ##" << std::endl;
		std::cout << "##     B   B A   A   T     T   L     E         A   A R  R  E     N  NN A   A     ##" << std::endl;
		std::cout << "##     BBBB  A   A   T     T   LLLLL EEEEE     A   A R   R EEEEE N   N A   A     ##" << std::endl;
		std::cout << "###                                                                             ###" << std::endl;
		std::cout << " ################################################################################ " << std::endl;

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

	 teamOne[0] = TeamMember("Iron Man", "Blaster", 10, 50, 100);
	 teamOne[1] = TeamMember("War Machine", "War", 10, 40, 100);
	 teamOne[2] = TeamMember("Black Widow", "kick", 15, 35, 100);
	 teamOne[3] = TeamMember("Black Panther", "Scratch", 25, 35, 100);
	 teamOne[4] = TeamMember("The Vision", "Zap", 30, 60, 100);
	 teamOne[5] = TeamMember("Spider-Man", "Web", 5, 25, 100);


	 teamTwo[0] = TeamMember("Iron Man", "Blaster", 10, 50, 100);
	 teamTwo[1] = TeamMember("War Machine", "War", 10, 40, 100);
	 teamTwo[2] = TeamMember("Black Widow", "kick", 15, 35, 100);
	 teamTwo[3] = TeamMember("Black Panther", "Scratch", 25, 35, 100);
	 teamTwo[4] = TeamMember("The Vision", "Zap", 30, 60, 100);
	 teamTwo[5] = TeamMember("Spider-Man", "Web", 5, 25, 100);



	 for (int i = 0; i < 6; i++)
	 {
		 std::cout << teamOne[i].GetName() << "/" << teamOne[i].GetAttackName() << "/" << teamOne[i].GetMaxAttack() << "/" << 
			 teamOne[i].GetMaxAttack() << "/" <<  teamOne[i].GetHealth() << "/" << teamOne[i].GetMaxHealth() << std::endl;
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