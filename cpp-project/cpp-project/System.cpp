#include "System.h"


System::System() : theMenu()
{
	this->sellerArrLogSize = 0;
	this->sellerArrPhySize = 1;
	this->sellerArr = new Seller*[1];
	this->buyerArrLogSize = 0;
	this->buyerArrPhySize = 1;
	this->buyerArr = new Buyer*[1];
}

void System::initSystem()
{
	cout << "Welcome to " << STORE_NAME << endl;
	int choice;
	do {
		cout << endl;
		theMenu.printMenu();
		choice = theMenu.getUserChoice(OPTIONS_LENGTH);
		performChoice(choice);
	} while (choice != 11);
}

bool isEmpty(int size) {
	return (size <= 0);
}

void System::sellerArrRealloc()
{
	Seller **new_arr;
	this->sellerArrPhySize *= 2;
	new_arr = new Seller *[this->sellerArrPhySize];

	for (int i = 0; i < this->sellerArrLogSize; i++)
	{
		new_arr[i] = (this->sellerArr[i]);
		this->sellerArr[i] = nullptr;
	}
	delete[] this->sellerArr;

	this->sellerArr = new_arr;
}

void System::buyerArrRealloc()
{
	Buyer **new_arr;
	this->buyerArrPhySize *= 2;
	new_arr = new Buyer *[this->buyerArrPhySize];

	for (int i = 0; i < this->buyerArrLogSize; i++)
	{
		new_arr[i] = (this->buyerArr[i]);
		this->buyerArr[i] = nullptr;
	}
	delete[] this->buyerArr;

	this->buyerArr = new_arr;
}

void System::addSellerToSellerArr(Seller &seller)
{
	if (this->sellerArrLogSize == this->sellerArrPhySize)
		sellerArrRealloc();

	sellerArr[this->sellerArrLogSize] = new Seller(seller);
	(this->sellerArrLogSize)++;
}

void System::addBuyerToBuyerArr(Buyer &buyer)
{
	if (this->buyerArrLogSize == this->buyerArrPhySize)
		buyerArrRealloc();

	buyerArr[this->buyerArrLogSize] = new Buyer(buyer);
	(this->buyerArrLogSize)++;
}

void System::performChoice(int choice)
{
	switch (choice) {
	case 1:
		addUser(BUYER);
		break;
	case 2:
		addUser(SELLER);
		break;
	case 3:
		addProductToSeller();
		break;
	case 4:
		addFeedbackToSeller();
		break;
	case 5:
		addProductToShoppingCart();
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		theMenu.printBuyers(buyerArr, buyerArrLogSize);
		break;
	case 9:
		theMenu.printSellers(sellerArr, sellerArrLogSize);
		break;
	case 10:
		theMenu.printProductsWithName(sellerArr, sellerArrLogSize);
		break;
	}
}

void System::addUser(eUserType userType) {
	char userName[MAX_LENGTH];
	char password[MAX_LENGTH];
	char country[MAX_LENGTH];
	char city[MAX_LENGTH];
	char street[MAX_LENGTH];
	int homeNumber;
	
	theMenu.getUserInfoFromUser(userName, password, country, city, street, homeNumber, MAX_LENGTH);

	Address newAddress(country, city, street, homeNumber);
	User newUser(userName, password, &newAddress);

	if (userType == BUYER) {
		ShoppingCart newShoppingCart;
		Buyer newBuyer(&newUser, &newShoppingCart);
		addBuyerToBuyerArr(newBuyer); // TODO: Test if a copy c'tor is needed
	}

	else if (userType == SELLER) {
		Seller newSeller(&newUser);
		addSellerToSellerArr(newSeller); // TODO: Test if a copy c'tor is needed
	}
}

void System::addProductToSeller()
{
	if (isEmpty(this->sellerArrLogSize)) {
		cout << "No sellers present in system." << endl;
	}
	else {
		cout << "\nPlease choose the seller to whom you'd like the add a product: " << endl;
		theMenu.printSellers(sellerArr, sellerArrLogSize);
		int chosenSellerIndex = theMenu.getUserChoice(sellerArrLogSize) - 1;
		Seller *chosenSeller = sellerArr[chosenSellerIndex];
		char productName[MAX_LENGTH];
		double price;
		Product::eCategory categoryChoice;
		theMenu.addProductToSeller(productName, price, categoryChoice);
		Product newProduct(productName, price, categoryChoice, chosenSeller);
		chosenSeller->addProduct(newProduct);
	}
}

void System::addFeedbackToSeller()
{
	if (isEmpty(this->buyerArrLogSize)) {
		cout << "No buyers present in system." << endl;
	}
	else if (isEmpty(this->sellerArrLogSize)) {
		cout << "No sellers present in system." << endl;
	}
	else {
		cout << "\nPlease choose a buyer to submit feedback: " << endl;
		theMenu.printBuyers(buyerArr, buyerArrLogSize);
		int chosenBuyerIndex = theMenu.getUserChoice(buyerArrLogSize) - 1;
		Buyer *chosenBuyer = buyerArr[chosenBuyerIndex];
		// Show only sellers from whom the respective buyer had bought
		if (isEmpty(chosenBuyer->getSellerArrLogSize())) {
			cout << chosenBuyer->getName() << " hasn't bought from any sellers yet." << endl;
		}
		else {
			cout << "\nPlease choose the seller to whom you'd like the add a feedback: " << endl;
			theMenu.printSellers(chosenBuyer->getSellerArr(), chosenBuyer->getSellerArrLogSize());
			int chosenSellerIndex = theMenu.getUserChoice(chosenBuyer->getSellerArrLogSize()) - 1;
			Seller *chosenSeller = chosenBuyer->getSellerArr()[chosenSellerIndex];
			char feedBackContent[MAX_FEEDBACK_SIZE];
			theMenu.getFeedbackFromUser(feedBackContent, MAX_FEEDBACK_SIZE);
			Feedback newFeedback(chosenBuyer->getName(), feedBackContent);
			chosenSeller->addFeedback(newFeedback);
		}
	}
}

void System::addProductToShoppingCart() {
	if (isEmpty(this->buyerArrLogSize)) {
		cout << "No buyers present in system." << endl;
	}
	cout << "\nPlease choose a buyer to add a product to his/her shopping cart: " << endl;
	theMenu.printBuyers(buyerArr, buyerArrLogSize);
	int chosenBuyerIndex = theMenu.getUserChoice(buyerArrLogSize) - 1;
	Buyer *chosenBuyer = buyerArr[chosenBuyerIndex];
	if (theMenu.printProducts(sellerArr, sellerArrLogSize)) {
		cout << "Please choose a seller to buy from " << "[1 ~ " << sellerArrLogSize << "]: " << endl;
		int chosenSellerIndex = theMenu.getUserChoice(sellerArrLogSize) - 1;
		Seller *chosenSeller = sellerArr[chosenSellerIndex];
		cout << "Please choose the desired product number from this seller " << "[1 ~ " << chosenSeller->getProductsLogSize() << "]: " << endl;
		int chosenProductIndex = theMenu.getUserChoice(chosenSeller->getProductsLogSize()) - 1;
		Product *chosenProduct = chosenSeller->getProducts()[chosenProductIndex];
		chosenBuyer->getShoppingCart()->addProductToShoppingCart(*chosenProduct);
	}
	else {
		cout << "No products present in the system." << endl;
	}
}

void System::makeOrder() {
	if (isEmpty(this->buyerArrLogSize)) {
		cout << "No buyers present in system." << endl;
	}
	cout << "\nPlease choose a buyer to make an order for: " << endl;
	theMenu.printBuyers(buyerArr, buyerArrLogSize);
	int chosenBuyerIndex = theMenu.getUserChoice(buyerArrLogSize) - 1;
	Buyer *chosenBuyer = buyerArr[chosenBuyerIndex];
	if (isEmpty(chosenBuyer->getShoppingCart()->getShoppingCartLogSize())) {
		cout << "This buyer doesn't have any products in his/her shopping cart." << endl;
	}
	else {
		int stringSize = (chosenBuyer->getShoppingCart()->getShoppingCartLogSize() * 2) + 1; // (Integer + comma) per product in Shopping Cart + '\0'
		char* productsString = new char[stringSize];
		const char s[2] = ","; // Each product in user input is supposed to be separated by commas
		char *token;
		int productIndex;
		cout << "The following products are in your shopping cart: " << endl;
		chosenBuyer->getShoppingCart()->show();
		cout << "Please choose product/s to order, separated by commas with no whitespace (e.g. 1,2,4,6): ";
		cin.ignore();
		cin.getline(productsString, stringSize); // TODO: VALIDATE USER INPUT (SOME PRODUCTS ENTERED ETC.)
		ShoppingCart orderShoppingCart;
		token = strtok(productsString, s); // Get first product that user wanted to order
		while (token != NULL) {
			productIndex = atoi(token) - 1;
			orderShoppingCart.addProductToShoppingCart(*chosenBuyer->getShoppingCart()->getProducts()[productIndex]);
			token = strtok(NULL, s);
		}
		Order newOrder(&orderShoppingCart, chosenBuyer);
		delete[] productsString;
	}
}