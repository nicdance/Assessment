#include <iostream>

int main() {
	
	bool restartMenu = true;

	while (restartMenu) {
		
		for (int i = 0; i < 11; i++)
		{
			std::cout << i << "..." << std::endl;
		}

		std::cout << "Would you like to continue? " << std::endl;
		std::cout << "1. Yes " << std::endl;
		std::cout << "2. No" << std::endl;

		int selection = 0;
		std::cin >> selection;

		if (selection == 1)		{
			std::cout << selection << " Pressed" << std::endl;
		}else if (selection == 2)		{
			std::cout << selection << " Pressed" << std::endl;
			restartMenu = false;
		}else 		{
			std::cout << selection << " Pressed" << std::endl;
		}
		
	}
}