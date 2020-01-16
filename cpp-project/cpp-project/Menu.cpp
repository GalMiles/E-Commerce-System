#include "Menu.h"

void Menu::printMenu()
{
	cout << endl;
	printSeperatorBlock('*');
	cout << "\nPlease select the desired option from the following:\n" << endl;
	for (int i = 0; i < OPTIONS_LENGTH; i++) {
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

	while (choice < 1 || choice > optionsLength) { //if the choice is not valid
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

bool Menu::validateDate(char* date) { //make sure the submitted date is in DD/MM/YYYY format
	const char s[2] = "/"; // Date is delimited by / (e.g. 18/12/2019)
	char *token;

	// Get day
	token = strtok(date, s);
	// Day must be 2 chars within 01-31 (e.g. 18)
	if (token == NULL || strlen(token) != 2 || atoi(token) < 1 || atoi(token) > 31) {
		cout << "Invalid day entered!" << endl;
		return false;
	}
	// Get month
	token = strtok(NULL, s);
	// Month must be 2 chars within 01-12 (e.g. 12)
	if (token == NULL || strlen(token) != 2 || atoi(token) < 1 || atoi(token) > 12) {
		cout << "Invalid month entered!" << endl;
		return false;
	}
	// Get year
	token = strtok(NULL, s);
	// Year must be 4 chars (e.g. 2019)
	if (token == NULL || strlen(token) != 4) {
		cout << "Invalid year entered!" << endl;
		return false;
	}
	return true;
}

void Menu::getFeedbackFromUser(char* feedBack, int feedBackSize, char* date) {
	cin.ignore();
	bool isDateValid = false;
	do {
		cout << "\nPlease enter feedback date (DD/MM/YYYY format, e.g. 08/02/2019): ";
		cin.getline(date, DATE_LENGTH);
		isDateValid = validateDate(date);
	} while (!isDateValid);
	cout << "\nPlease enter your feedback (Maximum " << feedBackSize << " characters): " << endl;
	cin.getline(feedBack, feedBackSize);
}

void Menu::printSellers(User **userArr, int size) {
	if (size <= 0) {
		cout << "No sellers present in system." << endl;
	}
	else {
		int sellersIndex = 0;
		for (int i = 0; i < size; i++) {
			if ((typeid(*(userArr[i])) == typeid(Seller)) || (typeid(*(userArr[i])) == typeid(SellerBuyer))) {
				cout << "[" << sellersIndex + 1 << "] " << *(userArr[i]) << endl;
				sellersIndex++;
			}
		}
	}
}

void Menu::printBuyers(User **userArr, int size) {
	if (size <= 0) {
		cout << "No buyers present in system." << endl;
	}
	else {
		int buyersIndex = 0;
		for (int i = 0; i < size; i++) {
			if ((typeid(*(userArr[i])) == typeid(Buyer)) || (typeid(*(userArr[i])) == typeid(SellerBuyer))) {
				cout << "[" << buyersIndex + 1 << "] " << *(userArr[i]) << endl;
				buyersIndex++;
			}
		}
	}
}

bool Menu::printProducts(User **userArr, int size) {
	bool foundProducts = false; // If there are sellers but no products whatsoever, should stay false
	if (size <= 0) {
		cout << "There are no sellers present in the system." << endl;
	}
	else {
		int sellersIndex = 0;
		for (int i = 0; i < size; i++)
		{
			if ((typeid(*(userArr[i])) == typeid(Seller)) || (typeid(*(userArr[i])) == typeid(SellerBuyer)))
			{
				int productsNum = dynamic_cast<Seller*>(userArr[i])->getProductsLogSize();
				if (productsNum <= 0) { // Seller has no products, no use in printing him/her
					continue;
				}
				foundProducts = true; // Some seller has some products
				printSeperatorBlock('-');
				cout << "[" << sellersIndex + 1 << "] Seller: " << dynamic_cast<Seller*>(userArr[i])->getName() << endl;
				sellersIndex++;

				for (int j = 0; j < productsNum; j++) {
					cout << "\t[" << j + 1 << "] " << dynamic_cast<Seller*>(userArr[i])->getProducts()[j]->getName() << endl;
				}
				printSeperatorBlock('-');
				cout << endl;
			}
		}
	}
	return foundProducts;
}

void Menu::printSeperatorBlock(char sep) {
	for (int i = 0; i < SEPERATOR_BLOCK_LENGTH; i++) {
		cout << sep;
	}
	cout << endl;
}

void Menu::printProductsWithName(User **userArr, int size) {
	char findName[MAX_LENGTH];
	bool found = false; //bool to indicate whether we found matching products or not
	if (size <= 0) { //if there are no products in the system
		cout << "There are no products present in the system." << endl;
	}
	else { //get input from the user and search for the item they are looking for
		cout << "Please enter product name to search for (case-sensitive): ";
		cin.ignore();
		cin.getline(findName, MAX_LENGTH + 1);
		cout << endl << endl;
		for (int i = 0; i < size; i++) { //this loop runs on every seller
			if ((typeid(userArr[i]) == typeid(Seller)) || (typeid(*(userArr[i])) == typeid(SellerBuyer))) {
				int productsNum = dynamic_cast<Seller*>(userArr[i])->getProductsLogSize(); //how many products the current seller has
				if (productsNum <= 0) { // Seller has no products, no use in printing him/her
					continue;
				}
				for (int j = 0; j < productsNum; j++) { //this loop prints every product in the current seller's stock
					if (strcmp(findName, dynamic_cast<Seller*>(userArr[i])->getProducts()[j]->getName()) == 0) {
						found = true;
						printSeperatorBlock('-');
						dynamic_cast<Seller*>(userArr[i])->getProducts()[j]->show();
						printSeperatorBlock('-');
					}
				}
			}
		}
		if (!found)
			cout << "No products found with that name." << endl;
	}
}

void Menu::addProductToSeller(char* productName, double& price, Product::eCategory& categoryChoice)
{
	cin.ignore();

	cout << "Please enter the product's name: ";
	cin.getline(productName, 20);

	cout << "\nPlease Enter the product's price: ";
	cin >> price;

	cout << "\nPlease select the product's category:" << endl;
	for (int i = 1; i <= 4; i++) {
		cout << "(" << i << ") " << Product::categories[i - 1] << endl;
	}
	categoryChoice = (Product::eCategory)(getUserChoice(NUM_OF_CATEGORIES) - 1);
}