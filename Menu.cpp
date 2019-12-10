#include "Menu.h"
#include "Buyer.h"
#include "Feedback.h"
#include "Seller.h"

int Menu::initMenu() {
	int choice;
	cout << "Welcome to storeName" << endl;
	cout << "\nPlease select the desired option from the following:\n" << endl;
	for (int i = 0; i < OPTIONS_LENGTH; i++) {
		cout << "[" << i + 1 << "] " << options[i] << endl;
	}
	cout << "\nChoice: ";
	cin >> choice;
	while (choice > 11 || choice < 1) {
		cout << "\nInvalid choice!\nPlease select an option between 1 and " << OPTIONS_LENGTH << endl;
		cout << "\nChoice: ";
		cin >> choice;
	}
	return choice;
}

void Menu::choiceCases(int choice)
{
	switch (choice) {
	case 1:
		addBuyer();

	case 2:
		addSeller();
	case 11:
		cout << "GoodbyeMessage\n"; //TODO
		return;
	}
}

void Menu::addBuyer()
{
	cin.ignore();
	char userName[20];
	cout << "Please enter user name: ";
	cin.getline(userName, 20);

	char password[20];
	cout << "\nPlease enter password: ";
	cin.getline(password, 20);

	char country[50];
	char city[50];
	char street[50];
	int homeNumber;

	cout << "\nPlease enter your address:" << endl;
	cout << "Country: ";
	cin.getline(country, 50);
	cout << "\nCity: ";
	cin.getline(city, 50);
	cout << "\nStreet: ";
	cin.getline(street, 50);
	cout << "\nHome number: ";
	cin >> homeNumber;

	Address userAdd(country, city, street, homeNumber);
	User newUser(userName, password, &userAdd, User::BUYER);
	Buyer newBuyer(&newUser);

	initMenu();
}

void Menu::addSeller()
{
	cin.ignore();
	char userName[20];
	cout << "Please enter user name: ";
	cin.getline(userName, 20);

	char password[20];
	cout << "\nPlease enter password: ";
	cin.getline(password, 20);

	char country[50];
	char city[50];
	char street[50];
	int homeNumber;

	cout << "\nPlease enter your address:" << endl;
	cout << "Country: ";
	cin.getline(country, 50);
	cout << "\nCity: ";
	cin.getline(city, 50);
	cout << "\nStreet: ";
	cin.getline(street, 50);
	cout << "\nHome number: ";
	cin >> homeNumber;

	Address userAdd(country, city, street, homeNumber);
	User newUser(userName, password, &userAdd, User::SELLER);
	Seller newSeller(&newUser);

	initMenu();
}

void Menu::addFeedback()
{
	char userName[20];
	cout << "Please enter your user name: " << endl;
	cin.getline(userName, 20);

	char sellerName[20];
	cout << "Please enter the seller name: " << endl;
	cin.getline(sellerName, 20);

	char content[100];
	cout << "Please enter your feedback: " << endl;
	cin.getline(content, 100);

	Feedback feedback(userName, content);
}
