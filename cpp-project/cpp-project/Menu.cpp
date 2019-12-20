#include "Menu.h"

void Menu::printMenu()
{
	cout << "\nPlease select the desired option from the following:\n" << endl;
	for (int i = 0; i < OPTIONS_LENGTH; i++) { // TODO: move to an aux function - printOptions
		cout << "[" << i + 1 << "] " << options[i] << endl;
	}
}

int Menu::getUserChoice(int optionsLength)
{
	cout << "\nChoice: ";
	int choice;
	cin >> choice;
	cout << endl;

	while (choice < 1 || choice > optionsLength) {
		cout << "Invalid option. Please select an option between 1 and " << optionsLength << endl;
		cout << "\nChoice: ";
		cin >> choice;
	}

	return choice;
}


void Menu::getUserInfoFromUser(char* userName, char* password, char*country, char* city, char* street, int& homeNumber, int maxLength) {
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

void Menu::getFeedbackFromUser(char* feedBack, int feedBackSize) {
	cin.ignore();
	cout << "\nPlease enter your feedback (Maximum " << feedBackSize << " characters): " << endl;
	cin.getline(feedBack, feedBackSize);
}

void Menu::printSellers(Seller **sellerArr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << i + 1 << "] " << sellerArr[i]->getName() << endl;
	}
}

void Menu::printBuyers(Buyer **buyerArr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << i + 1 << "] " << buyerArr[i]->getName() << endl;
	}
}