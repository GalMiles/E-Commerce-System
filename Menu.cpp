#include "Menu.h"

int Menu::initMenu() {
	int choice;
	cout << "Welcome to storeName" << endl; //TODO: change store name
	cout << "\nPlease select the desired option from the following:\n" << endl;
	for (int i = 0; i < OPTIONS_LENGTH; i++) { // TODO: move to an aux function - printOptions
		cout << "[" << i + 1 << "] " << options[i] << endl;
	}
	cout << "\nChoice: ";
	cin >> choice;
	while (choice > 11 || choice < 1) { //TODO: move to an aux function
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
		break;

	case 2:
		addSeller();
		break;

	case 3:
		addProductToSeller();
		break;

	case 4:
		addFeedback();
		break;

	case 11:
		cout << "GoodbyeMessage\n"; //TODO: change message
		break;
	}
}

void Menu::addBuyer() //TODO: ALL constraints should be const
{
	cin.ignore();
	char userName[20];
	cout << "Please enter user name: "; //TODO: aux function - readUserName
	cin.getline(userName, 20);

	char password[20];
	cout << "\nPlease enter password: "; //TODO: aux function - readPassword
	cin.getline(password, 20);

	char country[50];
	char city[50];
	char street[50];
	int homeNumber;

	cout << "\nPlease enter your address:" << endl; //TODO: aux function - readAddress
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
	ShoppingCart newUserShoppingCart;
	Buyer newBuyer(&newUser, &newUserShoppingCart);
	this->system->addBuyerToArr(&newBuyer);//add buyer to buyersArr
	
	initMenu();
}

void Menu::addSeller()
{
	cin.ignore();
	char userName[20]; //TODO: aux function - readUserName
	cout << "Please enter user name: ";
	cin.getline(userName, 20);

	char password[20];
	cout << "\nPlease enter password: "; //TODO: aux function - readPassword
	cin.getline(password, 20);

	char country[50];
	char city[50];
	char street[50];
	int homeNumber;

	cout << "\nPlease enter your address:" << endl; //TODO: aux function - readAddress
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
	this->system->addSellerToArr(&newSeller);

	initMenu();

}

void Menu::addFeedback()
{
	//TODO: make sure the buyer has actually purchased from this seller
	cin.ignore();
	char userName[20]; //TODO: aux function - readUserName
	cout << "Please enter your user name: " << endl;
	cin.getline(userName, 20);
	//check if the buyer exist in buyerArr

	//buyer.sellerArr - print the array+cases that he will choose
	char sellerName[20]; //TODO: aux function - readSeller's name
	cout << "Please enter the seller's name: " << endl;
	cin.getline(sellerName, 20);

	char content[100]; //TODO: aux function - readFeedback ?
	cout << "Please enter your feedback: " << endl;
	cin.getline(content, 100);

	Feedback feedback(userName, content);
	//go to sellerArr[seller].addfeedback;
}

void Menu::addProductToSeller()
{
	//ask which seller do you want to add product to?
	//run on system's sellers' arr and check if it exists bool(Seller *s); 

	cin.ignore();
	char productName[20]; //TODO: aux function - readProductName
	cout << "Please enter the product's name: ";
	cin.getline(productName, 20);

	double price; //TODO: aux function - readPrice
	cout << "/nPlease Enter the product's price: ";
	cin >> price;

	int categoryChoice; //TODO: aux function - readCategory
	cout << "\nPlease select the product's catergory:" << endl;
	for (int i = 1; i <= 4; i++) {
		cout << "(" << i << ") " << Product::categories[i - 1] << endl;
	}
	cin >> categoryChoice;

	Product newProduct(productName, price, Product::eCategory(categoryChoice));//add the res from bool

}

void Menu::showSellers() const
{
	
}

void Menu::showBuyers() const
{

}









