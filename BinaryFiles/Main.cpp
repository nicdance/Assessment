// BinaryFiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// up to 1 hr 52
	std::fstream file("inputFile.txt");
	if (!file.good() || !file.is_open()) {
		return -1;
	}

	
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		std::cout << line << std::endl;
	}

	int numbers[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::fstream fout;
	fout.open("binary.dat", std::ios::out | std::ios::binary);

	if (fout.good() && !fout.is_open()) {
		for (int i = 0; i < 10; i++)
		{
			fout.write((char *)&numbers[i], sizeof(int));
		}
	}

	return 0;
}
