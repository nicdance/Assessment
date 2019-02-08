#include <iostream>

int SwapPlayer(int);
void PlayGame();

int main() {
	bool playOn = true;

	// Game Loop  Which exits if players do not want to play any more
	while (playOn) {
		std::cout << "TTTTTTTT TT  TTTTTT     TTTTTTTT     TT    TTTTTT    TTTTTTTT  TTTTTT  TTTTTT" << std::endl;
		std::cout << "   TT    TT  TT            TT       TTTT   TT           TT     TT  TT  TT" << std::endl;
		std::cout << "   TT    TT  TT            TT      TT  TT  TT           TT     TT  TT  TTTTTT" << std::endl;
		std::cout << "   TT    TT  TT            TT      TTTTTT  TT           TT     TT  TT  TT" << std::endl;
		std::cout << "   TT    TT  TTTTTT        TT      TT  TT  TTTTTT       TT     TTTTTT  TTTTTT" << std::endl;

		std::cout << std::endl << "Would you like to play a game? " << std::endl;
		std::cout << "1. Yes " << std::endl;
		std::cout << "2. No" << std::endl << "-> ";

		// Retreive selection menu selection input from player and determine action
		int selection = 0;
		std::cin >> selection;

		if (selection == 1)		
		{
			PlayGame();
		}
		else if (selection == 2)
		{
			std::cout << std::endl << "Thanks for playing. GOOD BYE!" << std::endl;
			playOn = false;
		}
		else 
		{
			std::cout << "Invalid menu selection, please try again." << std::endl;
		}
	}
}

void PlayGame() {

	int gridWidth = 3;
	int gridHeight = 3;
	int gameGrid[3][3];

	// set up default values in grid - these will be the options
	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++)
		{
			gameGrid[i][j] = 0;
		}
	}

	std::cout << std::endl << "Starting game...." << std::endl << std::endl;
	int playersTurn = 1;
	// stop on end game condition or no more moves
	for (int i = 1; i < 10; i++)
	{

		std::cout << std::endl << "Player " << playersTurn << " Turn.";
		std::cout << std::endl << "\t\t1\t\t2\t\t3\t" << std::endl;
		std::cout << std::endl << "\t-\t-\t-\t-\t-\t-\t-\t" << std::endl;
		for (int i = 0; i < gridWidth; i++)
		{
			std::cout << i + 1 << "\t";
			for (int j = 0; j < gridHeight; j++)
			{
				//std::cout << gameGrid[gridWidth][gridHeight] << "\t|\t";
				std::cout << "|\t" << gameGrid[i][j] <<"\t" ;
			}
			std::cout << "|\t" << std::endl << "\t-\t-\t-\t-\t-\t-\t-\t" << std::endl;
		}
		
		
		bool pickOption = true;
		while (pickOption)
		{
			std::cout << "Please select Row (1-3) -> " ;
			int rowChoice = 0;
			std::cin >> rowChoice;

			std::cout << "Please select Row (1-3) -> ";
			int colChoice = 0;
			std::cin >> colChoice;

			if (colChoice >=1 && colChoice <=3 && rowChoice >= 1 && rowChoice <= 3)
			{

				rowChoice--;
				colChoice--;
				if (gameGrid[rowChoice][colChoice] == 0) {
					if (playersTurn == 1)
					{
						gameGrid[rowChoice][colChoice] = 11;
					}
					else {
						gameGrid[rowChoice][colChoice] = 22;
					}
					pickOption = false;
				}
			}
			else {
				std::cout << "Invalid grid selection, please try again." << std::endl;
			}

		}
		
		playersTurn = SwapPlayer(playersTurn);
	}
	std::cout << std::endl;
}

int SwapPlayer(int player) {
	if (player == 1)
	{
		return 2;
	}
	return 1;
}

