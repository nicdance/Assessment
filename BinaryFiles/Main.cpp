
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

struct Book{
	char callNumber[11]="";
	char bookTitle[100]="";
	char authorName[100]="";
	char status[4]="";
	char dueDate[12]="";
	char borrowerName[100]="";

};

// All fucnctions
void printBook(Book book);
int copyFromTextToBinary(std::string txtFile, std::string binaryFile);
int loadDataFromBinary(std::string fileName, Book library[], int maxLibraryRecords);

int main()
{
	int const maxLibraryRecords = 10;
	Book library[maxLibraryRecords];
	int counter = 0;
	std::string fileName = "LibraryData.dat";
	std::ifstream openFile(fileName, std::ios::binary);

	if (openFile.is_open()) {
		openFile.close();
		std::cout << "In If" << std::endl;
		counter = loadDataFromBinary(fileName, library, maxLibraryRecords);
		if (counter == -1) {
			return -1;
		}

		for (int i = 0; i < counter; i++)
		{
			printBook(library[i]);
		}

		std::string temp = "New Title";
		strcpy_s(library[1].bookTitle, temp.c_str());
		std::ofstream fout;

		fout.open(fileName, std::ios::out | std::ios::binary || std::ios::app);
		fout.seekp(sizeof(Book) * 1);
		fout.write((char *)&library[1], sizeof(Book));
		//fout.write((char *)&library[1].bookTitle, sizeof(library[1].bookTitle));

		fout.close();


		for (int i = 0; i < counter; i++)
		{
			printBook(library[i]);
		}

	} else {
		openFile.close();
		if (copyFromTextToBinary("inputFile.txt", fileName) == -1) {
			return -1;
		}
	}

	system("pause");

	return 0;
}

void printBook(Book book) {
	std::cout << book.callNumber << std::endl << book.bookTitle << std::endl << book.authorName << std::endl << book.status << std::endl
		<< book.dueDate << std::endl << book.borrowerName << std::endl;
}

int loadDataFromBinary(std::string fileName, Book library[], int maxLibraryRecords) {
	int counter = 0;
	std::fstream fileInput(fileName, std::ios::in | std::ios::binary);
	if (!fileInput.good() || !fileInput.is_open()) {
		std::cout << "Error opening " << fileName << std::endl;
		return -1;
	}
	fileInput.seekg(0, std::ios::end);
	long size = fileInput.tellg();
	fileInput.seekg(0, std::ios::beg);
	std::cout << "side of file is: " << size << std::endl;
	std::cout << "side of book is: " << sizeof(Book) << std::endl;
	std::cout << "nmumber of books is: " << (size / sizeof(Book)) << std::endl;

	for (int i = 0; i < (size / sizeof(Book)); i++)
	{
		fileInput.read((char *)&library[i], sizeof(Book));
		counter++;
	}
	return counter;
}

/*
*	copyFromTextToBinary steps through the inputFile and adds each book reecord
*	and saves it to the library binary data file.
*/
int copyFromTextToBinary(std::string txtFile, std::string binaryFile) {
	std::ofstream fout;
	fout.open(binaryFile, std::ios::out | std::ios::binary);
	std::fstream file(txtFile);
	if (!file.good() || !file.is_open()) {
		std::cout << "Error opening inputfile.txt" << std::endl;
		return -1;
	}

	while (!file.eof()) {
		std::string number, title, author, status, dueDate, borrowerName;

		std::getline(file, number);
		std::getline(file, title);
		std::getline(file, author);
		std::getline(file, status);

		if (status == "2") {
			std::getline(file, dueDate);
			std::getline(file, borrowerName);
		}

		Book book;
		strcpy_s(book.callNumber, number.c_str());
		strcpy_s(book.bookTitle, title.c_str());
		strcpy_s(book.authorName, author.c_str());
		strcpy_s(book.status, status.c_str());
		strcpy_s(book.dueDate, dueDate.c_str());
		strcpy_s(book.borrowerName, borrowerName.c_str());

		std::cout << "Book added to system" << std::endl << "Details of Book Added" << std::endl;
		printBook(book);
		fout.write((char *)&book, sizeof(Book));
	}

	file.close();
	fout.close();
	return 0;
}



/*while (!fileInput.eof()) {

	fileInput.write((char *)book, sizeof(Book));
}*/