#include "System.h"
#include <fstream>


System::System() : theMenu()
{
	sellerCount = 0;
	buyerCount = 0;
	sellerBuyerCount = 0;
}


System::~System() {
	list<User*>::iterator itr = userArr.begin();
	list<User*>::iterator itrEnd = userArr.end();

	for (; itr != itrEnd; ++itr) { //loop to free the memory allocated for this Data Structure
		delete *itr;
	}
}

void System::initSystem() //initialize the system
{
	ifstream inFile("AlmoGal.txt", ios::in);//OPEN
	if (!inFile.fail())//open succeed
	{
		loadAllUsers(inFile, this->userArr);//load data
	}
	else
	
	{
		cout << "no users to upload" << endl;
	}
	
	cout << "Welcome to " << storeName << endl;
	int choice;

	do {
		cout << endl;
		theMenu.printMenu();
		choice = theMenu.getUserChoice(OPTIONS_LENGTH);
		performChoice(choice);
	} while (choice != OPTIONS_LENGTH); //while the user didn't ask to exit the program
	this->SaveAllUsers(userArr, "AlmoGal.txt"); //saving data

}

void System::performChoice(int choice)
{
	switch (choice) {
	case 1:
		addUser(BUYER); //create a new Buyer user
		break;
	case 2:
		addUser(SELLER); //create a new Seller user
		break;
	case 3:
		addUser(SELLER_BUYER); //create a new Seller user
		break;
	case 4:
		addProductToSeller();
		break;
	case 5:
		addFeedbackToSeller();
		break;
	case 6:
		addProductToShoppingCart();
		break;
	case 7:
		placeOrder();
		break;
	case 8:
		payForAnOrder();
		break;
	case 9:
		theMenu.printBuyers(userArr, buyerCount);
		break;
	case 10:
		theMenu.printSellers(userArr, sellerCount);
		break;
	case 11:
		theMenu.printSellerBuyers(userArr, sellerBuyerCount);
		break;
	case 12:
		theMenu.printProductsWithName(userArr, sellerCount);
		break;
	}
}

bool System::isEmpty(int size) {
	return (size <= 0);
}

void System::addUser(eUserType userType)
{
	string userName;
	string password;
	string country;
	string city;
	string street;
	int homeNumber;
	bool valid;

	do {
		theMenu.getUserInfoFromUser(userName, password, country, city, street, homeNumber);
		valid = (isStrValid(country) && isStrValid(city) && isStrValid(street));
		if (!valid)
			cout << "Invalid input was submitted. Please try again." << endl;
	} while (!valid);

	Address newAddress(country, city, street, homeNumber);
	
	if (userType == BUYER)
	{
		ShoppingCart newShoppingCart;
		Buyer newBuyer(userName, password, newAddress, &newShoppingCart);
		userArr.push_back(new Buyer(newBuyer));
		this->buyerCount++;
	}

	else if (userType == SELLER) {
		Seller newSeller(userName, password, newAddress);
		userArr.push_back(new Seller(newSeller));
		this->sellerCount++;
	}

	else if (userType == SELLER_BUYER) {
		ShoppingCart newShoppingCart;
		SellerBuyer newSellerBuyer(Seller(userName, password, newAddress), Buyer(userName, password, newAddress, &newShoppingCart));
		userArr.push_back(new SellerBuyer(newSellerBuyer));
		sellerCount++;
		buyerCount++;
		sellerBuyerCount++;
	}
}


void System::addProductToSeller()
{
	if (isEmpty(this->sellerCount)) {
		cout << "No sellers present in system." << endl;
	}
	else //if there is at least one seller in the system
	{
		cout << "\nPlease choose the name of the seller to whom you'd like the add a product: " << endl;

		theMenu.printSellersNames(userArr, sellerCount); //print all of the sellers

		theMenu.cleanBuffer();
		User* chosenSeller;
		findUserByName(chosenSeller, this->userArr);
		string productName;
		double price;
		Product::eCategory categoryChoice;
		theMenu.addProductToSeller(productName, price, categoryChoice);
		Product newProduct(productName, price, categoryChoice, dynamic_cast<Seller*>(chosenSeller)); //createa new product
		dynamic_cast<Seller*>(chosenSeller)->addProduct(*(new Product(newProduct)));
	}
}

void System::addFeedbackToSeller()
{
	if (isEmpty(this->buyerCount)) {
		cout << "No buyers present in system." << endl;
	}
	else if (isEmpty(this->sellerCount)) {
		cout << "No sellers present in system." << endl;
	}
	else {
		cout << "\nPlease choose a buyer to submit feedback: " << endl;
		theMenu.printBuyersNames(userArr, buyerCount);
		
		theMenu.cleanBuffer();
		User* chosenBuyer;
		findUserByName(chosenBuyer, this->userArr);

		// Show only sellers from whom the respective buyer had bought
		if (isEmpty(dynamic_cast<Buyer*>(chosenBuyer)->getSellerArr().size()))
			cout << (chosenBuyer)->getUserName() << " hasn't bought from any sellers yet." << endl;

		else {
			cout << "\nPlease choose the seller to whom you'd like the add a feedback: " << endl;
			theMenu.printSellersNames(dynamic_cast<Buyer*>(chosenBuyer)->getSellerArr(), dynamic_cast<Buyer*>(chosenBuyer)->getSellerArr().size());

			User* chosenSeller;
			findUserByName(chosenSeller, dynamic_cast<Buyer*>(chosenBuyer)->getSellerArr());

			string feedBackContent;
			char feedBackDate[11];
			theMenu.getFeedbackFromUser(feedBackContent, feedBackDate);
			Feedback newFeedback((chosenBuyer)->getUserName(), feedBackContent, feedBackDate);
			dynamic_cast<Seller*>(chosenSeller)->addFeedback(*new Feedback(newFeedback));
		}
	}
}

void System::addProductToShoppingCart() {
	if (isEmpty(this->buyerCount)) { //check if there are buyers
		cout << "No buyers present in system." << endl;
	}
	else { //there are buyers
		cout << "\nPlease choose a buyer to add a product to his/her shopping cart: " << endl;
		theMenu.printBuyersNames(userArr,buyerCount );
		
		theMenu.cleanBuffer();
		User* chosenBuyer;
		findUserByName(chosenBuyer, this->userArr);

		if (theMenu.printProducts(userArr, userArr.size())) {
			cout << "Please choose a seller to buy from: " << endl;

			User* chosenSeller;
			findUserByName(chosenSeller, this->userArr);

			cout << "Please choose the desired product from this seller: " << endl;
			Product *chosenProduct;
			findProductByName(chosenProduct, dynamic_cast<Seller*>(chosenSeller)->getProducts());

			dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart()->addProductToShoppingCart(*chosenProduct);
		}
		else { //if no products were found
			cout << "No products present in the system." << endl;
		}
	}
}

void System::placeOrder() {
	if (isEmpty(this->buyerCount)) {
		cout << "No buyers present in system." << endl;
	}
	else {
		cout << "\nPlease choose a buyer to make an order for: " << endl;
		theMenu.printBuyers(userArr, buyerCount);

		theMenu.cleanBuffer();

		User* chosenBuyer;
		findUserByName(chosenBuyer, this->userArr);
		
		if (isEmpty(dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart()->getProducts().size())) {
			cout << "This buyer doesn't have any products in his/her shopping cart." << endl;
		}
		else {
			int stringSize = (dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart()->getProducts().size() * 2) + 1; // (Integer + comma) per product in Shopping Cart + '\0'
			char* productsString = new char[stringSize];
			const char s[2] = ","; // Each product in user input is supposed to be separated by commas
			char *token;
			int productIndex;
			cout << "The following products are in your shopping cart: " << endl << endl;
			theMenu.printSeperatorBlock('-');
			dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart()->show();
			theMenu.printSeperatorBlock('-');
			cout << endl << "Please choose product/s to order, separated by commas with no whitespace (e.g. 1,2,4,6): ";
			//theMenu.cleanBuffer();
			cin.getline(productsString, stringSize); // TODO: VALIDATE USER INPUT (SOME PRODUCTS ENTERED ETC.)
			ShoppingCart orderShoppingCart;
			token = strtok(productsString, s); // Get first product that user wanted to order
			while (token != NULL) {
				productIndex = atoi(token) - 1;
				orderShoppingCart.addProductToShoppingCart(*(dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart()->getProducts()[productIndex]));
				token = strtok(NULL, s);
			}
			Order newOrder(&orderShoppingCart, dynamic_cast<Buyer*>(chosenBuyer));
			dynamic_cast<Buyer*>(chosenBuyer)->setUnpaidOrder(*(new Order(newOrder)));

			delete[] productsString;
		}
	}
}

void System::payForAnOrder() {
	if (isEmpty(this->buyerCount)) {
		cout << "No buyers present in system." << endl;
	}
	else {
		cout << "Please choose a buyer to pay for an order: " << endl;
		theMenu.printBuyersNames(userArr, buyerCount);
		User* chosenBuyer;

		theMenu.cleanBuffer();
		findUserByName(chosenBuyer, this->userArr);

		if (dynamic_cast<Buyer*>(chosenBuyer)->getOrderStatus())
		{
			cout << "The following order is pending payment: " << endl;
			theMenu.printSeperatorBlock('+');
			dynamic_cast<Buyer*>(chosenBuyer)->getUnpaidOrder()->getOrderShoppingCart()->show();
			cout << "\nTotal Price: " << dynamic_cast<Buyer*>(chosenBuyer)->getUnpaidOrder()->getTotalPrice() << endl;
			theMenu.printSeperatorBlock('+');
			cout << "\nProccessing payment..." << endl;
			dynamic_cast<Buyer*>(chosenBuyer)->getUnpaidOrder()->setPaymentStatus(true);
			cout << "\nPayment complete." << endl;
			theMenu.printSeperatorBlock('*');

			ShoppingCart* chosenOrderShoppingCart = dynamic_cast<Buyer*>(chosenBuyer)->getUnpaidOrder()->getOrderShoppingCart();
			ShoppingCart* chosenBuyerShoppingCart = dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart();

			vector<Product*>::iterator itr = chosenOrderShoppingCart->getProducts().begin();
			vector<Product*>::iterator itrEnd = chosenOrderShoppingCart->getProducts().end();

			for (; itr != itrEnd; ++itr) { //remove the items from the buyer's shopping cart
				chosenBuyerShoppingCart->removeProductFromShoppingCart((*itr)->getProductId());
				dynamic_cast<Buyer*>(chosenBuyer)->addSellerToBuyerArr((*itr)->getSeller());
			}
			dynamic_cast<Buyer*>(chosenBuyer)->closeOrder();
		}
		else
			cout << "This buyer does not have any orders to pay for." << endl;
	}
}

void System::findUserByName(User*& user, list<User*>& userList) {
	
	list<User*>::iterator itr = userList.begin();
	list<User*>::iterator itrEnd = userList.end();
	list<User*>::iterator chosenUser = userList.end();
	string toFind;

	//theMenu.cleanBuffer();
	//cin.ignore();
	do {
		cout << "Choice(username): ";
		theMenu.getStrFromUser(toFind);
		cout << endl;
		chosenUser = find_if(itr, itrEnd, isUserFound(toFind));
		if (chosenUser == itrEnd)
			cout << "Invalid choice! Please try again." << endl;
	} while (chosenUser == itrEnd);

	user = *chosenUser;
}

void System::findProductByName(Product*& user, list<Product*>& productList) {

	list<Product*>::iterator itr = productList.begin();
	list<Product*>::iterator itrEnd = productList.end();
	list<Product*>::iterator chosenProduct = productList.end();
	string toFind;

	//cin.ignore();
	do {
		cout << "Choice(proudct name): ";
		theMenu.getStrFromUser(toFind);
		cout << endl;
		chosenProduct = find_if(itr, itrEnd, isProductFound(toFind));
		if (chosenProduct == itrEnd)
			cout << "Invalid choice! Please try again." << endl;
	} while (chosenProduct == itrEnd);

	user = *chosenProduct;
}

void System::loadAllUsers(ifstream& inFile, list<User*>& userArr)
{
	User *user;
	
	int size;
	inFile >> size;

	for (int i = 0; i < size; i++)
	{
		user = loadUser(inFile);
		userArr.push_back(user);
	}
	inFile.close();

}
User*::System::loadUser(ifstream& inFile)
{
	char type[4];
	inFile >> type;
	if (strcmp(type, "Buy")==0)
	{
		return new Buyer(inFile);
	}
	else if (strcmp(type, "Sel") == 0)
	{
		return new Seller(inFile);
	}
	
	else if (strcmp(type, "SeB") == 0)//type=SELLERBUYER
	{
		return new SellerBuyer(inFile);
	}
}


void System::SaveAllUsers(list<User*> allUsers, const string fileName)
{
	ofstream outFile(fileName, ios::trunc);//open new file or distroy the exists one
	int size = allUsers.size();
	outFile << size <<endl;

	list<User*>::iterator itr = userArr.begin();
	list<User*>::iterator itrEnd = userArr.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->saveType(outFile);
		(*itr)->saveUser(outFile);
		outFile << endl;

	}
	outFile.close();

}

bool System::isStrValid(string& str) {
	int length = str.length();
	for (int i = 0; i < length; i++) {
		if ((str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'))
			return false;
	}
	return true;
}
