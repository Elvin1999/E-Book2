#pragma once


#include<iostream>
#include "Functions.h"
using namespace std;


void HomeMenu() {
	cout << "Admin  [1]" << endl;
	cout << "Client [2]" << endl;
}

void AdminMenu() {
	cout << "Show Books   [1]" << endl;
	cout << "Add Book       [2]" << endl;
	cout << "Show All Rents    [3]" << endl;
}
void ClientMenu() {
	cout << "Show Books" << endl;
	cout << "Take Book" << endl;
}

void StartApp() {
	Init();
	while (true)
	{
		HomeMenu();
		int select = 0;
		cin >> select;
		system("cls");

		if (select == 1) {
			cin.ignore();
			cin.clear();
			cout << "Enter usrename: ";
			char* username = new char[30]{};
			cin.getline(username, 30);
			
			cout << "Enter password: ";
			char* password = new char[30]{};
			cin.getline(password, 30);

			auto admin = getAdmin(username, password);
			system("cls");
			if (admin == nullptr) {
				AdminMenu();
				cin >> select;
				if (select == 1) {
					ShowAllBooks();
				}
				else if (select == 2) {
					cin.ignore();
					cin.clear();
					auto book = getNewObj();
				   AddBook(database,book);
				}
				else if (select == 3) {
					ShowAllRents();
				}
			}

		}
		else if (select == 2) {
			ClientMenu();
			cin >> select;
			system("cls");
			if (select == 1) {
				ShowAllBooks();
			}
			else if (select == 2) {
			
				ShowAllBooks();
				int no = 0;
				cout << "Enter book no : " << endl;
				cin >> no;
				auto book = getBookByIndex(no);
				if (book != nullptr) {
					cin.ignore();
					cin.clear();
					char* username = new char[40]{};
					cout << "Enter username : " << endl;
					cin.getline(username, 40);

					cout << "Start day : " << endl;
					int day = 0;
					cin >> day;
					cout << "Start month : " << endl;
					int month;
					cin >> month;
					cout << "Start year : " << endl;
					int year;
					cin >> year;

					cout << "How many days you want ? " << endl;
					int count = 0;
					cin >> count;

					RentBook(username, book, day, month, year, count);

				}
				else {
					cout << "There is no book with this no : " << no << endl;
				}

			}
		}
		else {
			cout << "Wrong input" << endl;
		}
	}

}