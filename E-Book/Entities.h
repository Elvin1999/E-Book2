#pragma once



struct Admin {
	char* username;
	char* password;
};


struct Book {
	char* title;
	double price;
};


struct Date {
	int day;
	int month;
	int year;
};

struct Rent {
	char* username;
	Book book;
	Date takedate;
	int days;
	double totalPayment;
};

struct Database {
	Admin** admins;
	int admin_count = 0;
	Book** books;
	int book_count = 0;
	Rent** rents;
	int rent_count = 0;
};