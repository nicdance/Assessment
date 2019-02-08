#include <iostream>

int main() {
	
	bool playOn = true;

	// Game Loop  Which exits if players do not want to play any more
	while (playOn) {

		std::cout << "TTTTTTTT TT  TTTTTT     TTTTTTTT     TT    TTTTTT    TTTTTTTT  TTTTTT  TTTTTT" << std::endl;
		std::cout << "   TT    TT  TT            TT       TTTT   TT           TT     TT  TT  TT" << std::endl;
		std::cout << "   TT    TT  TT            TT      TT  TT  TT           TT     TT  TT  TTTTTT" << std::endl;
		std::cout << "   TT    TT  TT            TT      TTTTTT  TT           TT     TT  TT  TT" << std::endl;
		std::cout << "   TT    TT  TTTTTT        TT      TT  TT  TTTTTT       TT     TTTTTT  TTTTTT" << std::endl;

		std::cout << std::endl << "Would you like to continue? " << std::endl;
		std::cout << "1. Yes " << std::endl;
		std::cout << "2. No" << std::endl << "-> ";

		int selection = 0;
		std::cin >> selection;

		if (selection == 1)		{
			std::cout << std::endl << "Starting game...." << std::endl << std::endl;

			// stop on end game condition or no more moves
			for (int i = 1; i < 10; i++)
			{
				std::cout << std::endl << "Turn "<< i << "..." << std::endl;
			}
		}else if (selection == 2)		{
			std::cout << "Thanks for playing. GOOD BYE!" << std::endl;
			playOn = false;
		}else 		{
			std::cout << "Invalid menu selection, please try again." << std::endl;
		}
		
	}


}