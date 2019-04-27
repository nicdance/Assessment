/*
/	@Author Nicole Dance
/   Assessment 3 - Number Guessing Game
*/
#include <iostream>

const int MAXNUMBER = 100;
const int NOERROR = 0;
const int WRONGSELECTION = 1;
const int INVALIDVALUE = 2;

// Function Headers
void PlayGame();
void PrintHeading();
void CheckError(int errorCode, int max);

int main() {
	bool playOn = true;
	int errorCode = NOERROR;
	int menuSelection = 0;


	// Game Menu Loop
	while (playOn) {
		system("cls");

		PrintHeading();
		CheckError(errorCode, 2);

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
				std::cout << "Thankyou for Playing. Good Bye" << std::endl;
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

// The core game mechanics.
void PlayGame() {
	system("cls");

	PrintHeading();

	bool checkNumber = true;
	int errorCode = NOERROR;
	int menuSelection = 0;

	std::cout << "Think of a number between 1 and " << MAXNUMBER << "." << std::endl << std::endl;
	system("pause");
	int currentGuess = MAXNUMBER/2;
	int upper = MAXNUMBER + 1;
	int lower = 1;

	// Loops while still guessing number
	while (checkNumber) {
		CheckError(errorCode, 3);

		std::cout << std::endl << "Is your number " << currentGuess << "? " << std::endl;
		std::cout << "1. Lower" << std::endl;
		std::cout << "2. higher" << std::endl;
		std::cout << "3. CORRECT" << std::endl;
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
				upper = currentGuess;
				currentGuess = lower + (upper - lower) / 2;
				if ((upper - lower == 1)) {
					checkNumber = false;
				}
				break;
			case 2:
				lower = currentGuess;
				currentGuess = lower + (upper - lower) / 2;
				if (((upper - lower)-1) == 1) {
					checkNumber = false;
				}
				break;
			case 3:
				checkNumber = false;
				break;
			default:
				errorCode = WRONGSELECTION;
				break;
			}
		}
	}
	std::cout << "Your number is " << currentGuess << std::endl;
	system("pause");
}


// Prints out the heading
void PrintHeading() {
	std::cout << " ############################################################################################" << std::endl;
	std::cout << "###                                                                                         ###" << std::endl;
	std::cout << "##     N   N U   U M   M BBBB  EEEEE RRRR     GGG  U   U EEEEE SSSSS SSSSS I N   N  GGG     ##" << std::endl;
	std::cout << "##     NN  N U   U M   M B   B E     R   R   G   G U   U E     S     S     I NN  N G   G    ##" << std::endl;
	std::cout << "##     N N N U   U MM MM BBBB  EEEEE RRRR    G     U   U EEEEE SSSSS SSSSS I N N N G        ##" << std::endl;
	std::cout << "##     N  NN U   U M M M B   B E     R  R    G  GG U   U E         S     S I N  NN G  GG    ##" << std::endl;
	std::cout << "##     N   N  UUU  M   M BBBB  EEEEE R   R    GGG   UUU  EEEEE SSSSS SSSSS I N   N  GGG     ##" << std::endl;
	std::cout << "###                                                                                        ###" << std::endl;
	std::cout << " ############################################################################################" << std::endl;
}

// Displays error where appropriate
void CheckError(int errorCode, int max) {
	switch (errorCode) {
	case WRONGSELECTION:
		std::cout << "ERROR -> Please enter ender a number between 1 and " << max <<"." << std::endl;
		break;
	case INVALIDVALUE:
		std::cout << "ERROR -> Please enter a numerical Value." << std::endl;
		break;
	default:
		break;
	}
}