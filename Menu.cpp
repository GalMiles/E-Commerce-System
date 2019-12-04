#include "Menu.h"

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