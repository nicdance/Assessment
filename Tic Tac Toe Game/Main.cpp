/* 
/	@Author Nicole Dance
/   Assessment 1 - Tic Tac Toe
*/


#include <iostream>

// Constant Values
const int gridSize = 3;

// Functions
int SwapPlayer(int);
void PlayGame();
void DrawGrid(char[gridSize][gridSize]);
void PopulateGrid(char[gridSize][gridSize]);
char  CheckWinner(char gameGrid[gridSize][gridSize]);
int CheckSquare(char square1, char square2);
void DrawLine();


// Starts program and sets up Menu
int main() {
	bool playOn = true;
	int errorcode = 0;
	// Game Loop  Which exits if players do not want to play any more
	while (playOn) {
		system("cls");
		std::cout << " ################################################################################### " << std::endl;
		std::cout << "###                                                                               ###" << std::endl;
		std::cout << "##  TTTTTTTT TT  TTTTTT     TTTTTTTT     TT    TTTTTT    TTTTTTTT  TTTTTT  TTTTTT  ##" << std::endl;
		std::cout << "##     TT    TT  TT            TT       TTTT   TT           TT     TT  TT  TT      ##" << std::endl;
		std::cout << "##     TT    TT  TT            TT      TT  TT  TT           TT     TT  TT  TTTTTT  ##" << std::endl;
		std::cout << "##     TT    TT  TT            TT      TTTTTT  TT           TT     TT  TT  TT      ##" << std::endl;
		std::cout << "##     TT    TT  TTTTTT        TT      TT  TT  TTTTTT       TT     TTTTTT  TTTTTT  ##" << std::endl;
		std::cout << "###                                                                               ###" << std::endl;
		std::cout << " ################################################################################### " << std::endl;

		if (errorcode == 1) {
			std::cout << std::endl << "*** Error: Please ensure you enter a numeral value ***" << std::endl;
		}
		else if (errorcode == 2) {
			std::cout << std::endl << "*** Error: Please ensure you select a valid number from the list ***" << std::endl;
		}
		std::cout << std::endl << "Would you like to play a game? " << std::endl;
		std::cout << "1. Yes " << std::endl;
		std::cout << "2. No" << std::endl << "-> ";

		// Retreive selection menu selection input from player and determine action
		int selection = 0;
		std::cin >> selection;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1);
			errorcode = 1;
		}
		else if (selection == 1)
		{
			PlayGame();
			errorcode = 0;
		}
		else if (selection == 2)
		{
			std::cout << std::endl << "Thanks for playing. GOOD BYE!" << std::endl;
			playOn = false;
			errorcode = 0;
		}
		else
		{
			std::cin.ignore(1);
			std::cout << "Invalid menu selection, please try again." << std::endl;
			errorcode = 2;
		}
	}
	return 0;
}


// Executed when PLayer Opts to play a game
void PlayGame() {

	system("cls");
	char gameGrid[gridSize][gridSize];

	// set up default values in grid - these will be the options
	PopulateGrid(gameGrid);


	std::cout << std::endl << "Starting game...." << std::endl << std::endl;
	int playersTurn = 1;
	char winner = ' ';
	// Loops until no more moves
	for (int i = 1; i < 10; i++)
	{
		int errorCode = 0;
		std::cout << std::endl << "Player " << playersTurn << " Turn.";
		DrawGrid(gameGrid);

		bool pickOption = true;
		while (pickOption)
		{
			if (errorCode == 1) {
				std::cout << std::endl << "*** Error: Please ensure you enter a numeral value ***" << std::endl << std::endl;
			}
			else if (errorCode == 2) {
				std::cout << std::endl << "*** Error: Please ensure you select a valid number from the list ***" << std::endl << std::endl;
			}
			else if (errorCode == 3) {
				std::cout << std::endl << "*** Error: Square already Taken. Try again ***" << std::endl << std::endl;
			}
			errorCode = 0;
			std::cout << "Please enter Row (1-" << gridSize << " ) -> ";
			int rowChoice = 0;
			int colChoice = 0;
			std::cin >> rowChoice;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				errorCode = 1;
			}
			else {
				std::cout << "Please enter Column (1-" << gridSize << ") -> ";
				std::cin >> colChoice;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					errorCode = 1;
				}
			}
			
			if (errorCode != 1){
				if ((colChoice >= 1 && colChoice <= gridSize) && (rowChoice >= 1 && rowChoice <= gridSize))
				{

					rowChoice--;
					colChoice--;

					if (gameGrid[rowChoice][colChoice] == ' ') {
						if (playersTurn == 1)
						{
							gameGrid[rowChoice][colChoice] = 'O';
						}
						else {
							gameGrid[rowChoice][colChoice] = 'X';
						}
						pickOption = false;
					}
					else {
						errorCode = 3;
					}
				}
				else {
					errorCode = 2;
				}
			}

		}
		winner = CheckWinner(gameGrid);
		//std::cout << "Check Winner result is " << winner << std::endl;
		if (winner != ' ') {
			i = 10;
		}
		else {
			playersTurn = SwapPlayer(playersTurn);
		}
	}
	DrawGrid(gameGrid);
	std::cout << "The Winner is Player " << winner << std::endl;
	system("pause");
}


// Simple function to swap players turn.
int SwapPlayer(int player) {
	if (player == 1)
	{
		return 2;
	}
	return 1;
}

void DrawLine() {
	std::cout << std::endl << "\t-";

	for (int i = 0; i < gridSize; i++)
	{
		std::cout << "\t-\t-";
	}
	std::cout << std::endl;
}

// Draws the grid to the console
void DrawGrid(char gameGrid[gridSize][gridSize]) {

	std::cout << std::endl;
	for (int i = 0; i < gridSize; i++)
	{
		std::cout << "\t\t" << (i + 1);
	}

	DrawLine();

	for (int i = 0; i < gridSize; i++)
	{
		std::cout << i + 1 << "\t";
		for (int j = 0; j < gridSize; j++)
		{
			std::cout << "|\t" << gameGrid[i][j] << "\t";
		}
		std::cout << "|\t" << std::endl;
		DrawLine();
	}
}


// Populates grid with default values to remove garbage
void PopulateGrid(char gameGrid[gridSize][gridSize]) {
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			gameGrid[i][j] = ' ';
		}
	}
}


// This function will check for a winner and return 1 or 2 if a player and  0 if no winner yet
char  CheckWinner(char gameGrid[gridSize][gridSize]) {
	// Check Horizontal
	int win = 1;
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 1; j < gridSize; j++)
		{
			if (((gameGrid[i][j] != gameGrid[i][j - 1]) && CheckSquare(gameGrid[i][j], gameGrid[i][j - 1])) || !CheckSquare(gameGrid[i][j], gameGrid[i][j - 1])) {

				win = 0;
				j = gridSize;
			}
		}
		if (win == 1) {
			return gameGrid[i][1];
		}
		win = 1;
	}
	win = 1;

	// Check Vertically
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 1; j < gridSize; j++)
		{
			if (((gameGrid[j][i] != gameGrid[j - 1][i]) && CheckSquare(gameGrid[j][i], gameGrid[j - 1][i])) || !CheckSquare(gameGrid[j][i], gameGrid[j - 1][i])) {

				win = 0;
				j = gridSize;
			}
		}
		if (win == 1) {
			return gameGrid[1][i];
		}
		win = 1;
	}
	win = 1;

	// Check Diaganoly left to right
	for (int i = 1; i < gridSize; i++)
	{
		if (((gameGrid[i][i] != gameGrid[i - 1][i - 1]) && CheckSquare(gameGrid[i][i], gameGrid[i - 1][i - 1])) || !CheckSquare(gameGrid[i][i], gameGrid[i - 1][i - 1])) {

			win = 0;
			i = gridSize;
		}
	}
	if (win == 1) {
		return gameGrid[0][0];
	}

	win = 1;

	// Check Diaganoly right to left
	int j = gridSize - 2;
	for (int i = gridSize - 2; i >= 0; i--)
	{
		if (((gameGrid[j][i] != gameGrid[j - 1][i + 1]) && CheckSquare(gameGrid[j][i], gameGrid[j - 1][i + 1])) || !CheckSquare(gameGrid[j][i], gameGrid[j - 1][i + 1])) {
			win = 0;
			j = gridSize;
		}
		j++;
	}

	if (win == 1) {
		return gameGrid[0][gridSize - 1];
	}

	return ' ';
}

int CheckSquare(char square1, char square2) {
	if ((square1 == 'O' || square1 == 'X') && (square2 == 'O' || square2 == 'X')) {
		return true;
	}
	return false;
}