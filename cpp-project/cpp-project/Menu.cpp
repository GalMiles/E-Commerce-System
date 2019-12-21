#include "Menu.h"

void Menu::printMenu()
{
	cout << endl;
	printSeperatorBlock('*');
	cout << "\nPlease select the desired option from the following:\n" << endl;
	for (int i = 0; i < OPTIONS_LENGTH; i++) { // TODO: move to an aux function - printOptions
		cout << "[" << i + 1 << "] " << options[i] << endl;
	}
	cout << endl;
	printSeperatorBlock('*');
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
	if (size <= 0) {
		cout << "No sellers present in system." << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "[" << i + 1 << "] " << sellerArr[i]->getName() << endl;
		}
	}
}

void Menu::printBuyers(Buyer **buyerArr, int size) {
	if (size <= 0) {
		cout << "No buyers present in system." << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "[" << i + 1 << "] " << buyerArr[i]->getName() << endl;
		}
	}
}

void Menu::printProducts(Seller **sellerArr, int size) {
	if (size <= 0) {
		cout << "There are no products present in the system." << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			int productsNum = sellerArr[i]->getProductsLogSize();
			if (productsNum <= 0) { // Seller has no products, no use in printing him/her
				continue;
			}
			printSeperatorBlock('-');
			cout << "[" << i + 1 << "] Seller: " << sellerArr[i]->getName() << endl;
			for (int j = 0; j < productsNum; j++) {
				cout << "\t[" << j + 1 << "] " << sellerArr[i]->getProducts()[j]->getName() << endl;
			}
			printSeperatorBlock('-');
			cout << endl;
		}
	}
}

void Menu::printSeperatorBlock(char sep) {
	for (int i = 0; i < SEPERATOR_BLOCK_LENGTH; i++) {
		cout << sep;
	}
	cout << endl;
}

void Menu::printProductsWithName(Seller **sellerArr, int size) {
	char findName[MAX_LENGTH];
	bool found = false;
	if (size <= 0) {
		cout << "There are no products present in the system." << endl;
	}
	else {
		cout << "Please enter product name to search for (case-sensitive): ";
		cin.ignore();
		cin.getline(findName, MAX_LENGTH + 1);
		cout << endl << endl;
		for (int i = 0; i < size; i++) {
			int productsNum = sellerArr[i]->getProductsLogSize();
			if (productsNum <= 0) { // Seller has no products, no use in printing him/her
				continue;
			}
			for (int j = 0; j < productsNum; j++) {
				if (strcmp(findName, sellerArr[i]->getProducts()[j]->getName()) == 0) {
					found = true;
					printSeperatorBlock('-');
					sellerArr[i]->getProducts()[j]->show();
					printSeperatorBlock('-');
				}
			}
		}
		if (!found)
			cout << "No products found with that name." << endl;
	}
}

void Menu::addProductToSeller(char* productName, double& price, Product::eCategory& categoryChoice)
{
	//ask which seller do you want to add product to?
	//run on system's sellers' arr and check if it exists bool(Seller *s); 

	cin.ignore();

	cout << "Please enter the product's name: ";
	cin.getline(productName, 20);

	cout << "\nPlease Enter the product's price: ";
	cin >> price;

	cout << "\nPlease select the product's category:" << endl;
	for (int i = 1; i <= 4; i++) {
		cout << "(" << i << ") " << Product::categories[i - 1] << endl;
	}
	categoryChoice = Product::eCategory::HOME;
}