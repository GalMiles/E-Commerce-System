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
	cin.clear();
	cout << "\nChoice: ";
	int choice;
	cin >> choice;
	cout << endl;

	while (choice < 1 || choice > optionsLength) { //if the choice is not valid
		cout << "Invalid option. Please select an option between 1 and " << optionsLength << endl;
		cout << "\nChoice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}

	return choice;
}

void Menu::getUserInfoFromUser(string& userName, string& password, string& country, string& city, string& street, int& homeNumber, int maxLength) {
	cin.ignore();
	cout << "Please enter user name: ";
	getline(cin, userName);

	cout << "\nPlease enter password: ";
	getline(cin, password);

	cout << "\nPlease enter your address:" << endl;
	cout << "Country: ";
	getline(cin, country);
	cout << "\nCity: ";
	getline(cin, city);
	cout << "\nStreet: ";
	getline(cin, street);
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

void Menu::getFeedbackFromUser(string& feedBack, string& date) {
	cin.ignore();
	bool isDateValid = false;
	do {
		cout << "\nPlease enter feedback date (DD/MM/YYYY format, e.g. 08/02/2019): ";
		getline(cin, date);
		//isDateValid = validateDate(date);
	} while (!isDateValid);
	cout << "\nPlease enter your feedback: " << endl;
	getline(cin, feedBack);
}

void Menu::printSellers(const list<User*>& userArr, int numOfKind) {
	if (numOfKind <= 0) {
		cout << "No sellers present in system." << endl;
	}
	else {
		list<User*>::const_iterator itr = userArr.begin();
		list<User*>::const_iterator itrEnd = userArr.end();
		int sellersIndex = 0;
		for ( ; itr != itrEnd; ++itr) {
			if (isSeller(**itr)) {
				cout << "[" << sellersIndex + 1 << "] "<< (*itr) <<endl;
				sellersIndex++;
			}
		}
	}
}

void Menu::printBuyers(const list<User*>& userArr, int numOfKind) {
	if (numOfKind <= 0) {
		cout << "No buyers present in system." << endl;
	}
	else {
		list<User*>::const_iterator itr = userArr.begin();
		list<User*>::const_iterator itrEnd = userArr.end();
		int buyersIndex = 0;
		for (; itr != itrEnd; ++itr) {
			if (isBuyer(**itr)) {
				cout << "[" << buyersIndex + 1 << "] " << (*itr) << endl;
				buyersIndex++;
			}
		}
	}
}

void Menu::printSellerBuyers(const list<User*>& userArr, int numOfKind) {
	if (numOfKind <= 0) {
		cout << "No Sellers who are also Buyers present in system." << endl;
	}
	else {
		list<User*>::const_iterator itr = userArr.begin();
		list<User*>::const_iterator itrEnd = userArr.end();
		int buyersIndex = 0;
		for (; itr != itrEnd; ++itr) {
			if (isSellerBuyer(**itr)) {
				cout << "[" << buyersIndex + 1 << "] " << (*itr) << endl;
				buyersIndex++;
			}
		}
	}
}

bool Menu::printProducts(list<User*>& userArr, int size) {
	bool foundProducts = false; // If there are sellers but no products whatsoever, should stay false
	if (size <= 0) {
		cout << "There are no sellers present in the system." << endl;
	}
	else {
		list<User*>::const_iterator itr = userArr.begin();
		list<User*>::const_iterator itrEnd = userArr.end();
		int sellersIndex = 0;
		for ( ; itr != itrEnd ; ++itr)
		{
			if (isSeller(**itr))
			{
				int productsNum = dynamic_cast<Seller*>(*itr)->getProducts().size();
				if (productsNum <= 0) { // Seller has no products, no use in printing him/her
					continue;
				}
				foundProducts = true; // Some seller has some products
				printSeperatorBlock('-');
				cout << "[" << sellersIndex + 1 << "] Seller: " << dynamic_cast<Seller*>(*itr)->getName() << endl;
				sellersIndex++;

				list<Product*>::iterator productItr = dynamic_cast<Seller*>(*itr)->getProducts().begin();
				list<Product*>::iterator productItrEnd = dynamic_cast<Seller*>(*itr)->getProducts().end();
				int j = 1;
				for ( ; productItr != productItrEnd; ++productItr) {
					cout << "\t[" << j << "] " << (*productItr)->getName() << endl;
					j++;
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

void Menu::printProductsWithName(list<User*>& userArr, int sellerCount) {
	string findName;
	bool found = false; //bool to indicate whether we found matching products or not
	if (sellerCount <= 0) { //if there are no products in the system
		cout << "There are no products present in the system." << endl;
	}
	else { //get input from the user and search for the item they are looking for
		cout << "Please enter product name to search for (case-sensitive): ";
		cin.ignore();
		getline(cin, findName);
		cout << endl << endl;
		list<User*>::const_iterator itr = userArr.begin();
		list<User*>::const_iterator itrEnd = userArr.end();

		for (; itr != itrEnd; ++itr) { //this loop runs on every seller
			if (isSeller(**itr)) 
			{
				int productsNum = dynamic_cast<Seller*>(*itr)->getProducts().size(); //how many products the current seller has
				if (productsNum <= 0) { // Seller has no products, no use in printing him/her
					continue;
				}
				list<Product*>::iterator productItr = dynamic_cast<Seller*>(*itr)->getProducts().begin();
				list<Product*>::iterator productItrEnd = dynamic_cast<Seller*>(*itr)->getProducts().end();
				for ( ; productItr != productItrEnd; ++productItr) { //this loop prints every product in the current seller's stock
					if (findName == (*productItr)->getName()) {
						found = true;
						printSeperatorBlock('-');
						(*productItr)->show();
						printSeperatorBlock('-');
					}
				}
			}
		}
		if (!found)
			cout << "No products found with that name." << endl;
	}
}

void Menu::addProductToSeller(string& productName, double& price, Product::eCategory& categoryChoice)
{
	cin.ignore();

	cout << "Please enter the product's name: ";
	getline(cin, productName);

	cout << "\nPlease Enter the product's price: ";
	cin >> price;

	cout << "\nPlease select the product's category:" << endl;
	for (int i = 1; i <= 4; i++) {
		cout << "(" << i << ") " << Product::categories[i - 1] << endl;
	}
	categoryChoice = (Product::eCategory)(getUserChoice(NUM_OF_CATEGORIES) - 1);
}

void Menu::printSellersNames(const list<User*>& userArr, int numOfKind)
{
	if (numOfKind <= 0) {
		cout << "No sellers present in system." << endl;
	}
	else {
		list<User*>::const_iterator itr = userArr.begin();
		list<User*>::const_iterator itrEnd = userArr.end();
		int sellersIndex = 0;
		for (; itr != itrEnd; ++itr) {
			if (isSeller(**itr)) {
				cout << "[" << sellersIndex + 1 << "] " << (*itr)->getUserName() << endl;
				sellersIndex++;
			}
		}
	}
}

void Menu::printBuyersNames(const list<User*>& userArr, int numOfKind)
{
	if (numOfKind <= 0) {
		cout << "No buyers present in system." << endl;
	}
	else {
		list<User*>::const_iterator itr = userArr.begin();
		list<User*>::const_iterator itrEnd = userArr.end();
		int buyersIndex = 0;
		for (; itr != itrEnd; ++itr) {
			if (isBuyer(**itr)) {
				cout << "[" << buyersIndex + 1 << "] " << (*itr)->getUserName() << endl;
				buyersIndex++;
			}
		}
	}
}

void Menu::getStrFromUser(string& input) {
	cin.ignore();
	getline(cin, input);
}


bool isSeller(User& user) {
	return (typeid(user) == typeid(Seller)) || (typeid(user) == typeid(SellerBuyer));
}

bool isBuyer(User& user) {
	return (typeid(user) == typeid(Buyer)) || (typeid(user) == typeid(SellerBuyer));
}

bool isSellerBuyer(User& user) {
	return ((typeid(user) == typeid(SellerBuyer)));
}