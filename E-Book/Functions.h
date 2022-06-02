#pragma once
#include "Entities.h"
#include<iostream>
using namespace std;


Database database;


void AddBook(Database& db, Book* book) {
	auto newbooks = new Book * [db.book_count + 1]{};
	for (size_t i = 0; i < db.book_count; i++)
	{
		newbooks[i] = db.books[i];
	}
	newbooks[db.book_count] = book;
	db.books = newbooks;
	db.book_count++;
	newbooks = nullptr;
}

void AddAdmin(Database& db, Admin* admin) {
	auto newadmins = new Admin * [db.admin_count + 1]{};
	for (size_t i = 0; i < db.admin_count; i++)
	{
		newadmins[i] = db.admins[i];
	}
	newadmins[db.admin_count] = admin;
	db.admins = newadmins;
	db.admin_count++;
	newadmins = nullptr;
}

void AddRent(Database& db, Rent* rent) {
	auto newrents = new Rent * [db.rent_count + 1]{};
	for (size_t i = 0; i < db.rent_count; i++)
	{
		newrents[i] = db.rents[i];
	}
	newrents[db.rent_count] = rent;
	db.rents = newrents;
	db.rent_count++;
	newrents = nullptr;
}


void ShowBook(const Book* book) {
	cout << "Book Title : " << book->title << endl;
	cout << "Book Price : " << book->price << endl;
}

void ShowAllBooks() {
	for (size_t i = 0; i < database.book_count; i++)
	{
		cout << "NO : " << i + 1 << endl;
		ShowBook(database.books[i]);
		cout << "=================================" << endl;
	}
}

void RentBook(char* username, const Book* book, int day, int month, int year, int day_count) {
	Rent* rent = new Rent;
	rent->book = *book;
	rent->days = day_count;

	Date date{ day,month,year };

	rent->takedate = date;
	rent->username = username;
	rent->totalPayment = book->price * day_count;


	AddRent(database, rent);
	cout << "You rent book : " << book->title << " successfully" << endl;
	cout << "You have to pay : " << rent->totalPayment << "$" << endl;
}



void ShowRent(const Rent* rent) {
	cout << "User : " << rent->username << endl;
	ShowBook(new Book(rent->book));
	cout << "Date start : " << rent->takedate.day << "/" << rent->takedate.month << "/" << rent->takedate.year << endl;
	cout << "Total Payments : " << rent->totalPayment << "$" << endl;
}
void ShowAllRents() {
	for (size_t i = 0; i < database.rent_count; i++)
	{
		ShowRent(database.rents[i]);
	}
}

Admin* getAdmin(const char* username, const char* password) {
	for (size_t i = 0; i < database.admin_count; i++)
	{

		if (strcmp(username, database.admins[i]->username) && strcmp(password, database.admins[i]->username)) {
			return database.admins[i];
		}
	}
	return nullptr;
}

Book* getBookByIndex(int no) {
	int index = no - 1;
	if (index >= 0 && index < database.book_count) {
		return database.books[index];
	}
	return nullptr;
}

Book* getNewObj() {
	cout << "Enter title: ";
	char* title = new char[30]{};
	cin.getline(title, 30);

	cout << "Enter price: ";
	double price = 0;
	cin >> price;

	return new Book{ title,price };

}

void Init() {
	Book* b1 = new Book{ new char[30] {"Tom sawyer"},12 };
	Book* b2 = new Book{ new char[30] {"C# Nutshell"},30 };
	Book* b3 = new Book{ new char[30] {"Algorithms"},50 };

	AddBook(database, b1);
	AddBook(database, b2);
	AddBook(database, b3);

	Admin* admin = new Admin{ new char[30] {"admin"},new char[30] {"admin"} };

	AddAdmin(database, admin);

}