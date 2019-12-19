#include "Menu.h"

void Menu::printMenu()
{
	cout << "\nPlease select the desired option from the following:\n" << endl;
	for (int i = 0; i < OPTIONS_LENGTH; i++) { // TODO: move to an aux function - printOptions
		cout << "[" << i + 1 << "] " << options[i] << endl;
	}
}

int Menu::getUserChoice()
{
	cout << "\nChoice: ";
	int choice;
	cin >> choice;
	cout << endl;

	while (choice < 1 || choice > OPTIONS_LENGTH) {
		cout << "Invalid option. Please select an option between 1 and " << OPTIONS_LENGTH << endl;
		cout << "\nChoice: ";
		cin >> choice;
	}

	return choice;
}


void Menu::getBuyerInfoFromUser(char* userName, char* password, char*country, char* city, char* street, int& homeNumber, int maxLength) {
	cin.ignore();
	cout << "Please enter user name: ";
	cin.getline(userName, maxLength + 1);

	cout << "\nPlease enter password: ";
	cin.getline(password, maxLength + 1);

	cout << "\nPlease enter your address:" << endl;
	cout << "Country: ";
	cin.getline(country, maxLength + 1);
	cout << "\nCity: ";
	cin.getline(city, maxLength + 1);
	cout << "\nStreet: ";
	cin.getline(street, maxLength + 1);
	cout << "\nHome number: ";
	cin >> homeNumber;
}