#include "System.h"


System::System() : theMenu()
{

}

void System::initSystem()
{
	cout << "Welcome to " << STORE_NAME << endl;
	theMenu.printMenu();
	performChoice(theMenu.getUserChoice());

}

void System::performChoice(int choice)
{
	switch (choice) {
	case 1:
		addBuyer();
		break;
	}
}

void System::addBuyer() {
	char userName[MAX_LENGTH];
	char password[MAX_LENGTH];
	char country[MAX_LENGTH];
	char city[MAX_LENGTH];
	char street[MAX_LENGTH];
	int homeNumber;

	theMenu.getBuyerInfoFromUser(userName, password, country, city, street, homeNumber, MAX_LENGTH);
}