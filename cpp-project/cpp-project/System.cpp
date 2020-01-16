#include "System.h"


System::System() : theMenu()
{
	this->userArrLogSize = 0;
	this->userArrPhySize = 1;
	this->userArr = new User*[1];
	this->sellerCount = 0;
	this->buyerCount = 0;
	this->sellerBuyerCount = 0;
}

System::~System() {
	for (int i = 0; i < userArrPhySize; i++) {
		this->userArr[i] = nullptr;
	}
	delete[]userArr;
}

void System::initSystem() //initialize the system
{
	cout << "Welcome to " << STORE_NAME << endl;
	int choice;
	do {
		cout << endl;
		theMenu.printMenu();
		choice = theMenu.getUserChoice(OPTIONS_LENGTH);
		performChoice(choice);
	} while (choice != OPTIONS_LENGTH); //while the user didn't ask to exit the program
}

bool System::isEmpty(int size) {
	return (size <= 0);
}

void System::userArrRealloc()
{
	User **new_arr;
	this->userArrPhySize *= 2;
	new_arr = new User *[this->userArrPhySize];

	for (int i = 0; i < this->userArrLogSize; i++)
	{
		new_arr[i] = (this->userArr[i]);
		this->userArr[i] = nullptr;
	}
	delete[] this->userArr;

	this->userArr = new_arr;
}

void System::addUser(eUserType userType)
{
	char userName[MAX_LENGTH];
	char password[MAX_LENGTH];
	char country[MAX_LENGTH];
	char city[MAX_LENGTH];
	char street[MAX_LENGTH];
	int homeNumber;

	theMenu.getUserInfoFromUser(userName, password, country, city, street, homeNumber, MAX_LENGTH);

	Address newAddress(country, city, street, homeNumber);

	if (userType == BUYER)
	{
		ShoppingCart newShoppingCart;
		Buyer newBuyer(userName, password, &newAddress, &newShoppingCart);
		(*this) += newBuyer;
		this->buyerCount++;
	}

	else if (userType == SELLER) {
		Seller newSeller(userName, password, &newAddress);
		(*this) += newSeller;
		this->sellerCount++;
	}

	else if (userType == SELLER_BUYER) {
		ShoppingCart newShoppingCart;
		SellerBuyer newSellerBuyer(Seller(userName, password, &newAddress), Buyer(userName, password, &newAddress, &newShoppingCart));
		(*this) += newSellerBuyer;
		sellerCount++;
		buyerCount++;
		sellerBuyerCount++;
	}
}


const System& System::operator+=(const Seller seller)
{
	if (this->userArrLogSize == this->userArrPhySize)
		userArrRealloc();

	userArr[userArrLogSize] = new Seller(seller);
	(this->userArrLogSize)++;

	return *this;

}

const System& System::operator+=(const Buyer buyer)
{
	if (this->userArrLogSize == this->userArrPhySize)
		userArrRealloc();

	userArr[userArrLogSize] = new Buyer(buyer);
	(this->userArrLogSize)++;

	return *this;

}

const System& System::operator+=(const SellerBuyer sellerbuyer)
{
	if (this->userArrLogSize == this->userArrPhySize)
		userArrRealloc();

	userArr[userArrLogSize] = new SellerBuyer(sellerbuyer);
	(this->userArrLogSize)++;

	return *this;

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
		theMenu.printBuyers(userArr, userArrLogSize, buyerCount);
		break;
	case 10:
		theMenu.printSellers(userArr, userArrLogSize, sellerCount);
		break;
	case 11:
		theMenu.printSellerBuyers(userArr, userArrLogSize, sellerBuyerCount);
		break;
	case 12:
		theMenu.printProductsWithName(userArr, userArrLogSize, sellerCount);
		break;
	case 13:
		testOperators(theMenu.testOperatorsOptions());
		break;
	}
}

void System::testOperators(int choice) {
	switch (choice) {
	case 1:
		if ((this->buyerCount) < 2)
			cout << "Not enough buyers present in system." << endl;
		else {
			cout << "\nPlease select two buyers to compare: " << endl;
			theMenu.printBuyersNames(userArr, userArrLogSize);
			cout << "Buyer 1:" << endl;
			int chosenBuyer1Index = theMenu.getUserChoice(buyerCount) - 1;
			int correctBuyer1Index = getCorrectIndex(BUYER, chosenBuyer1Index, this->userArr, this->userArrLogSize);
			Buyer *chosenBuyer1 = dynamic_cast<Buyer*>(userArr[correctBuyer1Index]);

			cout << "Buyer 2:" << endl;
			int chosenBuyer2Index = theMenu.getUserChoice(buyerCount) - 1;
			int correctBuyer2Index = getCorrectIndex(BUYER, chosenBuyer2Index, this->userArr, this->userArrLogSize);
			Buyer *chosenBuyer2 = dynamic_cast<Buyer*>(userArr[correctBuyer2Index]);

			if (chosenBuyer1 > chosenBuyer2)
				cout << "Buyer 1 > Buyer 2" << endl;
			else
				cout << "Buyer 1 < Buyer 2" << endl;
		}

	case 2:
		cout << "Adding a new Buyer to the System's users array" << endl;
		addUser(BUYER);
		cout << "The new user was added" << endl;

	case 3:
		bool foundProducts = false; // If there are sellers but no products whatsoever, should stay false
		if (sellerCount <= 0) {
			cout << "There are no sellers present in the system." << endl;
		}
		else {
			for (int i = 0; i < userArrLogSize && !foundProducts; i++)
			{
				if ((typeid(*(userArr[i])) == typeid(Seller)) || (typeid(*(userArr[i])) == typeid(SellerBuyer)))
				{
					int productsNum = dynamic_cast<Seller*>(userArr[i])->getProductsLogSize();
					if (productsNum <= 0) { // Seller has no product
						continue;
					}
					foundProducts = true;
					cout << dynamic_cast<Seller*>(userArr[i])->getProducts()[0] << endl;
					cout << endl;
				}
			}
		}
	case 4:
		if (userArrLogSize <= 0)
			cout << "No users are present in the system. Please add a user and try again." << endl;
		else
			cout << userArr[0] << endl;
	case 5:

	}
}


void System::addProductToSeller()
{
	if (isEmpty(this->sellerCount)) {
		cout << "No sellers present in system." << endl;
	}
	else 
	{
		cout << "\nPlease choose the seller to whom you'd like the add a product: " << endl;

		theMenu.printSellersNames(userArr, userArrLogSize);
	//print all of the sellers

		theMenu.printSellers(userArr, userArrLogSize, sellerCount); //print all of the sellers
		int chosenSellerIndex = theMenu.getUserChoice(sellerCount) - 1;
		int correctIndex = getCorrectIndex(SELLER, chosenSellerIndex, this->userArr, this->userArrLogSize);
		Seller *chosenSeller = dynamic_cast<Seller*>(userArr[correctIndex]);
		char productName[MAX_LENGTH];
		double price;
		Product::eCategory categoryChoice;
		theMenu.addProductToSeller(productName, price, categoryChoice);
		Product newProduct(productName, price, categoryChoice, chosenSeller); //createa new product
		chosenSeller->addProduct(newProduct);
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
		theMenu.printBuyersNames(userArr, userArrLogSize);
		theMenu.printBuyers(userArr, userArrLogSize, buyerCount);
		int chosenBuyerIndex = theMenu.getUserChoice(buyerCount) - 1;
		int correctBuyerIndex = getCorrectIndex(BUYER, chosenBuyerIndex,this->userArr, this->userArrLogSize);
		Buyer *chosenBuyer = dynamic_cast<Buyer*>(userArr[correctBuyerIndex]);
		// Show only sellers from whom the respective buyer had bought
		if (isEmpty(chosenBuyer->getSellerArrLogSize())) {
			cout << chosenBuyer->getName() << " hasn't bought from any sellers yet." << endl;
		}
		else {
			cout << "\nPlease choose the seller to whom you'd like the add a feedback: " << endl;
			theMenu.printSellersNames(chosenBuyer->getSellerArr(), chosenBuyer->getSellerArrLogSize());
			theMenu.printSellers(chosenBuyer->getSellerArr(), chosenBuyer->getSellerArrLogSize(), chosenBuyer->getSellerArrLogSize());
			int chosenSellerIndex = theMenu.getUserChoice(chosenBuyer->getSellerArrLogSize()) - 1;
			int correctSellerIndex = getCorrectIndex(SELLER, chosenSellerIndex, chosenBuyer->getSellerArr(), chosenBuyer->getSellerArrLogSize());
			Seller *chosenSeller = dynamic_cast<Seller*>(chosenBuyer->getSellerArr()[correctSellerIndex]);
			char feedBackContent[MAX_FEEDBACK_SIZE];
			char feedBackDate[DATE_LENGTH];
			theMenu.getFeedbackFromUser(feedBackContent, MAX_FEEDBACK_SIZE, feedBackDate);
			Feedback newFeedback(chosenBuyer->getName(), feedBackContent, feedBackDate);
			chosenSeller->addFeedback(newFeedback);
		}
	}
}

void System::addProductToShoppingCart() {
	if (isEmpty(this->buyerCount)) {
		cout << "No buyers present in system." << endl;
	}
	else {
		cout << "\nPlease choose a buyer to add a product to his/her shopping cart: " << endl;
		theMenu.printBuyersNames(userArr, userArrLogSize);
		theMenu.printBuyers(userArr, userArrLogSize, buyerCount);
		int chosenBuyerIndex = theMenu.getUserChoice(buyerCount) - 1;
		int correctBuyerIndex = getCorrectIndex(BUYER, chosenBuyerIndex, this->userArr,this->userArrLogSize);
		Buyer *chosenBuyer = dynamic_cast<Buyer*>(userArr[correctBuyerIndex]);
		if (theMenu.printProducts(userArr, userArrLogSize)) {
			cout << "Please choose a seller to buy from " << "[1 ~ " << sellerCount << "]: " << endl;
			int chosenSellerIndex = theMenu.getUserChoice(sellerCount) - 1;
			int correctSellerIndex = getCorrectIndex(SELLER, chosenSellerIndex, this->userArr, this->userArrLogSize);
			Seller *chosenSeller = dynamic_cast<Seller*>(userArr[correctSellerIndex]);
			cout << "Please choose the desired product number from this seller " << "[1 ~ " << chosenSeller->getProductsLogSize() << "]: " << endl;
			int chosenProductIndex = theMenu.getUserChoice(chosenSeller->getProductsLogSize()) - 1;
			Product *chosenProduct = chosenSeller->getProducts()[chosenProductIndex];
			chosenBuyer->getShoppingCart()->addProductToShoppingCart(*chosenProduct);
		}
		else {
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
		theMenu.printBuyersNames(userArr, userArrLogSize);
		theMenu.printBuyers(userArr, userArrLogSize, buyerCount);
		int chosenBuyerIndex = theMenu.getUserChoice(buyerCount) - 1;
		int correctBuyerIndex = getCorrectIndex(BUYER, chosenBuyerIndex, this->userArr, this->userArrLogSize);
		Buyer *chosenBuyer = dynamic_cast<Buyer*>(userArr[correctBuyerIndex]);
		if (isEmpty(chosenBuyer->getShoppingCart()->getShoppingCartLogSize())) {
			cout << "This buyer doesn't have any products in his/her shopping cart." << endl;
		}
		else {
			int stringSize = (chosenBuyer->getShoppingCart()->getShoppingCartLogSize() * 2) + 1; // (Integer + comma) per product in Shopping Cart + '\0'
			char* productsString = new char[stringSize];
			const char s[2] = ","; // Each product in user input is supposed to be separated by commas
			char *token;
			int productIndex;
			cout << "The following products are in your shopping cart: " << endl << endl;
			theMenu.printSeperatorBlock('-');
			chosenBuyer->getShoppingCart()->show();
			theMenu.printSeperatorBlock('-');
			cout << endl << "Please choose product/s to order, separated by commas with no whitespace (e.g. 1,2,4,6): ";
			cin.ignore();
			cin.getline(productsString, stringSize);
			ShoppingCart orderShoppingCart;
			token = strtok(productsString, s); // Get first product that user wanted to order
			while (token != NULL) {
				productIndex = atoi(token) - 1;
				orderShoppingCart.addProductToShoppingCart(*chosenBuyer->getShoppingCart()->getProducts()[productIndex]);
				token = strtok(NULL, s);
			}
			Order newOrder(&orderShoppingCart, chosenBuyer);
			chosenBuyer->addOrderToOrderArr(newOrder);
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
		theMenu.printBuyersNames(userArr, userArrLogSize);
		theMenu.printBuyers(userArr, userArrLogSize, buyerCount);
		int chosenBuyerIndex = theMenu.getUserChoice(buyerCount) - 1;
		int correctBuyerIndex = getCorrectIndex(BUYER, chosenBuyerIndex, this->userArr, this->userArrLogSize);
		Buyer *chosenBuyer = dynamic_cast<Buyer*>(userArr[correctBuyerIndex]);
		if (isEmpty(chosenBuyer->getOrderArrLogSize())) {
			cout << "This buyer does not have any orders to pay for." << endl;
		}
		else {
			bool unpaidOrders = false; // Unless there are unpaid orders, the buyer can't pay
			cout << "This buyer has placed the following orders: " << endl;
			for (int i = 0; i < chosenBuyer->getOrderArrLogSize(); i++) {
				Order* tempOrder = chosenBuyer->getOrderArr()[i];
				bool isThisOrderPaid = tempOrder->isPaid();
				if (!isThisOrderPaid && !unpaidOrders) { // There is at least one unpaid order
					unpaidOrders = true;
				}
				cout << "[ Order Number " << i + 1 << " ]\t(Status: " << Order::paymentStatuses[isThisOrderPaid] << ')' << endl;
				theMenu.printSeperatorBlock('+');
				tempOrder->getOrderShoppingCart()->show();
				cout << "\n$ Total Price: " << tempOrder->getTotalPrice() << endl;
				theMenu.printSeperatorBlock('+');
				cout << endl;
			}
			int orderChoiceIndex;
			Order* chosenOrder;
			if (unpaidOrders) {
				cout << "Please choose an unpaid order to pay for: " << "[1 ~ " << chosenBuyer->getOrderArrLogSize() << ']';
				do {
					cin.ignore();
					orderChoiceIndex = theMenu.getUserChoice(chosenBuyer->getOrderArrLogSize()) - 1;
					chosenOrder = chosenBuyer->getOrderArr()[orderChoiceIndex];
					if (chosenOrder->isPaid()) {
						cout << "This order has already been paid for." << endl;
					}
				} while (chosenOrder->isPaid());
				theMenu.printSeperatorBlock('*');
				cout << "\nProcessing payment...";
				chosenOrder->setPaymentStatus(true);
				cout << "\nPayment complete." << endl;
				theMenu.printSeperatorBlock('*');
				ShoppingCart* chosenOrderShoppingCart = chosenOrder->getOrderShoppingCart();
				ShoppingCart* chosenBuyerShoppingCart = chosenBuyer->getShoppingCart();
				for (int i = 0; i < chosenOrderShoppingCart->getShoppingCartLogSize(); i++) {
					chosenBuyerShoppingCart->removeProductFromShoppingCart(chosenOrderShoppingCart->getProducts()[i]->getProductId());
				}
				for (int i = 0; i < chosenOrderShoppingCart->getShoppingCartLogSize(); i++) {
					chosenBuyer->addSellerToBuyerArr(chosenOrderShoppingCart->getProducts()[i]->getSeller());
				}
				chosenBuyer->getShoppingCart()->setTotalPrice(0);
			}
			else {
				cout << "All orders are already paid for." << endl;
			}
		}
	}
}

int System::getCorrectIndex(eUserType userType, int index, User** userArr, int arrSize) //since the array is a mix of all kinds of user, we need to rectify the index in order to access the user in our system's array
{
	int matchesTypeCount = 0;
	if (userType == SELLER) {
		for (int i = 0; i < arrSize; i++) {
			if ((typeid(*(userArr[i])) == typeid(Seller)) || (typeid(*(userArr[i])) == typeid(SellerBuyer)))
				matchesTypeCount++;
			if (matchesTypeCount == index+1)
				return i;
		}
	}

	else if (userType == BUYER) {
		for (int i = 0; i < arrSize; i++) {
			if ((typeid(*(userArr[i])) == typeid(Buyer)) || (typeid(*(userArr[i])) == typeid(SellerBuyer)))
				matchesTypeCount++;
			if (matchesTypeCount == index+1)
				return i;
		}
	}

	return -1; //in case the index wasn't found
}