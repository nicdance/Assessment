
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

void printBook(Book book) {
	std::cout << book.callNumber << std::endl << book.bookTitle << std::endl << book.authorName << std::endl << book.status << std::endl 
		<< book.dueDate << std::endl << book.borrowerName << std::endl;
}

int main()
{
	// from 3hrs
	int check = true;
	if(check){
		Book book = {"","","","","",""};
		Book newBook = { "","","","","","" };
		std::fstream file;
		std::cout << "Size of Book: " << sizeof(Book);
		file.open("binary.dat", std::ios::in | std::ios::binary);
		file.read((char *)&book, sizeof(Book));
		std::cout << "Size of Book: " << sizeof(Book);
		printBook(book);

		file.close();
	}
	
	if (!check) {
		std::ofstream fout;
		fout.open("binary.dat", std::ios::out | std::ios::binary);
		if (fout.good() && !fout.is_open()) {
			std::cout << "In If" << std::endl;

		}
		else {
			std::fstream file("inputFile.txt");
			//if (!file.good() || !file.is_open()) {
		//		return -1;
		//	}

			std::string number = "";
			std::string title = "";
			std::string author = "";
			std::string status = "";
			std::string dueDate = "11 01 1984";
			std::string borrowerName = "Bob the Builder";

			std::getline(file, number);
			std::getline(file, title);
			std::getline(file, author);
			std::getline(file, status);
			file.close();

		//	Book book = { number, title, author, status, "none", "none" };
			Book book;
			std::cout << "Size of Book: " << sizeof(Book);
			strcpy_s(book.callNumber, number.c_str());
			std::cout << "callNumber: '" << book.callNumber << "'" <<std::endl;
			strcpy_s(book.bookTitle, title.c_str());
			std::cout << "bookTitle: '" << book.bookTitle << "'" << std::endl;
			strcpy_s(book.authorName, author.c_str());
			std::cout << "authorName: '" << book.authorName << "'" << std::endl;
			strcpy_s(book.status, status.c_str());
			std::cout << "status: '" << book.status << "'" << std::endl;
			strcpy_s(book.dueDate, dueDate.c_str());
			std::cout << "dueDate: '" << book.dueDate << "'" << std::endl;
			strcpy_s(book.borrowerName, borrowerName.c_str());
			std::cout << "borrowerName: '" << book.borrowerName << "'" << std::endl;
				

			std::cout << "Size of Book: " << sizeof(Book);
			printBook(book);
			fout.write((char *)&book, sizeof(Book));

			std::cout << "Size of Book: " << sizeof(Book);
			fout.close();
		}
	}
	

	
	system("pause");

	/*
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		std::cout << line << std::endl;
	}
	int numbers[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::ofstream fout;
	fout.open("binary.dat", std::ios::out | std::ios::binary);

	if (fout.good() && !fout.is_open()) {
		for (int i = 0; i < 10; i++)
		{
			std::cout << numbers[i] << ", ";
			fout.write((char *)&numbers[i], sizeof(int));
		}
	}
	*/
	return 0;
}
