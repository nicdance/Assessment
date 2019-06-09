
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

struct Book{
	char callNumber[25]="";
	char bookTitle[100]="";
	char authorName[100]="";
	char status[4]="";
	char dueDate[20]="";
	char borrowerName[100]="";

};

// Error Code Values
const int NOERROR = 0;
const int WRONGSELECTION = 1;
const int INVALIDVALUE = 2;

// All fucnctions
void displayMainMenu();
void printBook(Book book);
void flushInput();
void addANewBook(std::string fileName, Book library[], int maxLibraryRecords, int counter);
int addBookToEOF(std::string fileName, Book library[], int counter);
int insertBookRecord(std::string fileName, Book library[], int positionToInsertAt);
int copyAllBooksToBinary(std::string binaryFile, Book library[], int numberOfBooks);
int copyFromTextToArray(std::string binaryFile, Book library[]);
int loadDataFromBinary(std::string fileName, Book library[], int maxLibraryRecords);

int main()
{
	bool keepGoing = true;		// Used to detemine if menu loop should continue
	int errorCode = NOERROR;	// Checked to detemine error messages
	int const maxLibraryRecords = 10;
	Book library[maxLibraryRecords];
	int counter = 0;

	std::string fileName = "LibraryData.dat";
	std::ifstream openFile(fileName, std::ios::binary);

	if (openFile.is_open()) {
		openFile.close();
		counter = loadDataFromBinary(fileName, library, maxLibraryRecords);
		if (counter == -1) {
			return -1;
		}
	} else {
		openFile.close();
		counter = copyFromTextToArray("inputFile.txt", library);
		if (counter == -1) {
			return -1;
		}
		copyAllBooksToBinary(fileName, library, counter);
	}

	while (keepGoing) {

		int menuSelection = 0;

		switch (errorCode) {
		case WRONGSELECTION:
			std::cout << "ERROR -> Please enter ender a number between 0-3." << std::endl;
			break;
		case INVALIDVALUE:
			std::cout << "ERROR -> Please enter a numerical Value." << std::endl;
			break;
		default:
			break;
		}
		displayMainMenu();
		std::cin >> menuSelection;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1);
			errorCode = INVALIDVALUE;
		}
		else {
			switch (menuSelection) {				
			case 1:
				std::cout << "counter: "  << counter<<std::endl;
				//std::cout << std::endl << "1. Add a new book" << std::endl;
				addANewBook(fileName, library, maxLibraryRecords,counter);
				counter++;
				break;
			case 2:
				std::cout << std::endl << "2. Display books" << std::endl;

				break;
			case 3:
				std::cout << std::endl << "3. Update book details" << std::endl;

				break;
			case 0:
				keepGoing = false;
				std::cout << "Enjoy Your books. Good Bye" << std::endl;
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

void printBook(Book book) {
	std::cout << book.callNumber << std::endl << book.bookTitle << std::endl << book.authorName << std::endl << book.status << std::endl
		<< book.dueDate << std::endl << book.borrowerName << std::endl;
}

void displayMainMenu() {
	std::cout << "###################################" << std::endl;
	std::cout << "#####                      ########" << std::endl;
	std::cout << "##### Binary File Exercise ########" << std::endl;
	std::cout << "#####                      ########" << std::endl;
	std::cout << "###################################" << std::endl;
	std::cout << "1. Add a new book" << std::endl;
	std::cout << "2. Display books" << std::endl;
	std::cout << "3. Update book details" << std::endl;
	std::cout << "0. Exit" << std::endl << std::endl;
	std::cout << "Enter a number between 0-3: ";
}

void flushInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addANewBook(std::string fileName, Book library[], int maxLibraryRecords, int counter) {
	std::string callNumber, title, author;
	Book book;
	std::cout << "Please enter the book Details" << std::endl;
	std::cout << "Call Number : ";
	flushInput();
	getline(std::cin, callNumber);
	std::cout << "Title : ";
	//flushInput();
	getline(std::cin, title);
	std::cout << "Author : ";
	//flushInput();
	getline(std::cin, author);

	strcpy_s(book.callNumber, callNumber.c_str());
	strcpy_s(book.bookTitle, title.c_str());
	strcpy_s(book.authorName, author.c_str());

	library[counter] = book;

	insertBookRecord(fileName, library, counter);
}


/*
*	This function overrides a given book entry in the binary file
int addBookToEOF(std::string fileName, Book library[], int counter) {
	std::ofstream fout;

	fout.open(fileName, std::ios::out | std::ios::binary || std::ios::app);
	fout.seekp(sizeof(Book) * counter);
	fout.write((char *)&library[counter], sizeof(Book));

	fout.close();
	return 0;
}
*/

/*
*	This function overrides a given book entry in the binary file
*/
int insertBookRecord(std::string fileName, Book library[], int positionToInsertAt) {
	std::ofstream fout;

	fout.open(fileName, std::ios::out | std::ios::binary || std::ios::app);
	fout.seekp(sizeof(Book) * positionToInsertAt);
	fout.write((char *)&library[positionToInsertAt], sizeof(Book));
	
	fout.close();
	return 0;
}

// This function to used to Load each entry in the binary file into an array
int loadDataFromBinary(std::string fileName, Book library[], int maxLibraryRecords) {
	int counter = 0;
	std::fstream fileInput(fileName, std::ios::in | std::ios::binary);
	if (!fileInput.good() || !fileInput.is_open()) {
		std::cout << "Error opening " << fileName << std::endl;
		return -1;
	}

	// The next 3 changes the seek point to determine the size of the file and then resets it so that we are looking at te begining of the file again
	fileInput.seekg(0, std::ios::end);
	long size = fileInput.tellg();
	fileInput.seekg(0, std::ios::beg);

	for (int i = 0; i < (size / sizeof(Book)); i++)
	{
		fileInput.read((char *)&library[i], sizeof(Book));
		counter++;
	}
	for (int i = 0; i < counter; i++)
	{
		printBook(library[i]);
	}
	return counter;
}

/*
*	copyAllBooksToBinary steps through the array and adds each book reecord
*	to the Library dat file.
*/
int copyAllBooksToBinary(std::string binaryFile, Book library[], int numberOfBooks) {
	std::ofstream fout;
	fout.open(binaryFile, std::ios::out | std::ios::binary | std::ios::app);
	int counter = 0;

	
	for(int i = 0; i< numberOfBooks; i++)
	{
		fout.seekp(sizeof(Book) * i);
		fout.write((char *)&library[i], sizeof(Book));
	}

	fout.close();

	return counter;
}

/*
*	copyFromTextToBinary steps through the inputFile and adds each book reecord
*	to the Library Array.
*/
int copyFromTextToArray(std::string txtFile, Book library[]) {
	std::fstream file(txtFile);
	if (!file.good() || !file.is_open()) {
		std::cout << "Error opening inputfile.txt" << std::endl;
		return -1;
	}
	int count = 0;
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

		library[count] = book;
		std::cout << "Book added to system" << std::endl << "Details of Book Added" << std::endl;
		printBook(library[count]);
		count++;
	}

	file.close();
	return count;
}



/*while (!fileInput.eof()) {

	fileInput.write((char *)book, sizeof(Book));
}


	fileInput.seekg(0, std::ios::end);
	long size = fileInput.tellg();
	fileInput.seekg(0, std::ios::beg);


		std::string temp = "BOOOOOOOOOOOOKIE";
	strcpy_s(library[1].bookTitle, temp.c_str());


	insertBookRecord(fileName, library, 1);


	for (int i = 0; i < counter; i++)
	{
		printBook(library[i]);
	}

*/