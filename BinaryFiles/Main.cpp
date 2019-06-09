
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
int getMenuSelection(int max);
void displayListFields();
void displayMainMenu();
void displayListOfBooks(Book library[], int counter);
void printBook(Book book);
void flushInput();
void addANewBook(std::string fileName, Book library[], int maxLibraryRecords, int counter);
int addBookToEOF(std::string fileName, Book library[], int counter);
void updateRecordField(Book library[], int bookToUpdate, int fieldToUpdate);
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

		displayMainMenu();
		int menuSelection = 0;
		menuSelection = getMenuSelection(3);

		int bookToUpdate = 0;
		int fieldToUpdate = 0;
		
		switch (menuSelection) {				
		case 1:
			std::cout << "counter: "  << counter<<std::endl;
			addANewBook(fileName, library, maxLibraryRecords,counter);
			counter++;
			system("pause");
			break;
		case 2:
			std::cout << std::endl << "##### Display Book Details ########" << std::endl;
			displayListOfBooks(library, counter);
			menuSelection = getMenuSelection(counter);
			printBook(library[menuSelection - 1]);
			system("pause");
			break;
		case 3:
			std::cout << std::endl << "##### Update Book Details ########" << std::endl;
			displayListOfBooks(library, counter);
			bookToUpdate = getMenuSelection(counter);
			displayListFields();
			fieldToUpdate = getMenuSelection(4);
			updateRecordField(library, bookToUpdate, fieldToUpdate);
			std::cout << "bookToUpdate: " << bookToUpdate << std::endl;
			insertBookRecord(fileName, library, bookToUpdate);
			system("pause");
			break;
		case 0:
			keepGoing = false;
			std::cout << "Enjoy Your books. Good Bye" << std::endl;
			break;
		default:
			errorCode = WRONGSELECTION;
			break;
		}
		//}
	}
	
	system("pause");

	return 0;
}

/*
*	Displays the details of a specific book. Will only show borrowers details if satus is 2	
*/
void printBook(Book book) {
	std::cout << std::endl << "Call Number: " << book.callNumber << std::endl << "Book Title: " << book.bookTitle << std::endl
		<< "Author Name: " << book.authorName << std::endl << "Status:" << book.status << std::endl;
		if(strcmp(book.status, "2") == 0){
			std::cout << "Due Date: " << book.dueDate << std::endl << "Borrower Name: " << book.borrowerName << std::endl;
		}		
		std::cout<< std::endl;
}


/*
*	Based on the max number of options. this function retreives a valid menu selection from 0 to the max number
*/
int getMenuSelection(int max) {
	bool keepGoing = true;
	int errorCode = 0;
	while (keepGoing) {

		int menuSelection = 0;

		switch (errorCode) {
		case WRONGSELECTION:
			std::cout << "ERROR -> Please enter ender a number between 0-" << max <<"." << std::endl;
			std::cout << "Enter a number between 0-" << max << ": ";
			break;
		case INVALIDVALUE:
			std::cout << "ERROR -> Please enter a numerical Value." << std::endl;
			std::cout << "Enter a number between 0-" << max << ": ";
			break;
		default:
			break;
		}
		std::cin >> menuSelection;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1);
			errorCode = INVALIDVALUE;
		}
		else if(menuSelection<0 || menuSelection>max){
			errorCode = WRONGSELECTION;
		}
		else {
			return menuSelection;
		}
	}
	return 0;
}

/*
*	Displays the Main Menu
*/
void displayMainMenu() {
	system("cls");
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


/*
*	Displays a numbered list of fields to update.
*/
void displayListFields() {
	std::cout << "##### Select Field To Update ########" << std::endl;
	std::cout << "1. Call Number" << std::endl;
	std::cout << "2. Title" << std::endl;
	std::cout << "3. Author" << std::endl;
	std::cout << "4. Status" << std::endl;
	std::cout << "0. Exit" << std::endl << std::endl;
	std::cout << "Enter a number between 0-4: ";
}

/*
*	Displays a numbered list of book titles.
*/
void displayListOfBooks(Book library[], int counter) {
	for (int i = 0; i < counter; i++)
	{
		std::cout<< (i+1) << ". " << library[i].bookTitle << std::endl;
	}
	std::cout << "0. Back" << std::endl << std::endl;
	std::cout << "Enter a number between 0-" << counter << ": ";
}

/*
*	Flushes the inpout stream cin  so that getline will work correctly.
*/
void flushInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*
*	Prompts the user for details of the new book to add to the system
*/
void addANewBook(std::string fileName, Book library[], int maxLibraryRecords, int counter) {
	std::string callNumber, title, author, status;
	status = "1";
	Book book;

	flushInput();
	std::cout << "Please enter the book Details" << std::endl;
	std::cout << "Call Number : ";
	getline(std::cin, callNumber);
	std::cout << "Title : ";
	getline(std::cin, title);
	std::cout << "Author : ";
	getline(std::cin, author);

	strcpy_s(book.callNumber, callNumber.c_str());
	strcpy_s(book.bookTitle, title.c_str());
	strcpy_s(book.authorName, author.c_str());
	strcpy_s(book.status, status.c_str());

	library[counter] = book;

	addBookToEOF(fileName, library, counter);
}


/*
*	This function appends a new entry to an exisiting binary file
*/
int addBookToEOF(std::string fileName, Book library[], int counter) {
	std::ofstream fout;

	fout.open(fileName, std::ios::out | std::ios::binary || std::ios::app);
	fout.seekp(sizeof(Book) * counter);
	fout.write((char *)&library[counter], sizeof(Book));

	fout.close();
	return 0;
}

/*
*	This function overrides a given book entry in the binary file
*/
int insertBookRecord(std::string fileName, Book library[], int positionToInsertAt) {
	std::ofstream fout;

	fout.open(fileName, std::ios::out | std::ios::binary || std::ios::app);
	fout.seekp(sizeof(Book) * (positionToInsertAt-1));
	fout.write((char *)&library[positionToInsertAt-1], sizeof(Book));
	
	fout.close();
	return 0;
}

/*
*	This function retreives requests input from the user for the field they have opted to update.
*	This value is stored in the array
*/
void updateRecordField(Book library[], int bookToUpdate, int fieldToUpdate) {
	std::string callNumber, title, author, status, dueDate, borrowerName;
	flushInput();
	switch (fieldToUpdate)
	{
		case 1:
			std::cout << "Please enter Call Number: ";
			getline(std::cin, callNumber);
			strcpy_s(library[bookToUpdate-1].callNumber, callNumber.c_str());
			break;
		case 2:
			std::cout << "Please enter Title: ";
			getline(std::cin, title);
			strcpy_s(library[bookToUpdate - 1].bookTitle, title.c_str());
			break;
		case 3:
			std::cout << "Please enter Author Name: ";
			getline(std::cin, author);
			strcpy_s(library[bookToUpdate - 1].authorName, author.c_str());
			break;
		case 4:
			std::cout << "Please enter Status: ";
			std::cin >> status;
			strcpy_s(library[bookToUpdate - 1].status, status.c_str());
			if (strcmp(library[bookToUpdate - 1].status, "2") == 0) {
				flushInput();
				std::cout << "Please enter dueDate: ";
				getline(std::cin, dueDate);
				strcpy_s(library[bookToUpdate - 1].dueDate, dueDate.c_str());
				std::cout << "Please enter Borrower Name: ";
				getline(std::cin, borrowerName);
				strcpy_s(library[bookToUpdate - 1].borrowerName, borrowerName.c_str());
			}
			break;
		default:
			break;
	}
}

// This function to used to Load each entry in the binary file into an array
int loadDataFromBinary(std::string fileName, Book library[], int maxLibraryRecords) {
	int counter = 0;
	std::fstream fileInput(fileName, std::ios::in | std::ios::binary);
	if (!fileInput.good() || !fileInput.is_open()) {
		std::cout << "Error opening " << fileName << std::endl;
		return -1;
	}

	// The next 3 changes the seek point to determine the size of the file and then resets it 
	// so that we are looking at te begining of the file again
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
		std::cout << "Unable to load inputfile.txt" << std::endl;
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
		count++;
	}

	file.close();
	return count;
}