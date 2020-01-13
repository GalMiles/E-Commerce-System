#include "System.h"


System::System() : theMenu()
{
	this->userArrLogSize = 0;
	this->userArrPhySize = 1;
	this->userArr = new User*[1];
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

/*
void System::addUserToArr(User &user)
{
	if (this->userArrLogSize == this->userArrPhySize)
		userArrRealloc();

	userArr[userArrLogSize] = new User(user);
	(this->userArrLogSize)++;
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
addUserToArr(newBuyer);
this->buyerCount++;
}

else if (userType == SELLER) {
Seller newSeller(userName, password, &newAddress);
addUserToArr(newSeller);
this->sellerCount++;
}
}
*/

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
		addProductToSeller();
		break;
	case 4:
		addFeedbackToSeller();
		break;
	case 5:
		addProductToShoppingCart();
		break;
	case 6:
		placeOrder();
		break;
	case 7:
		payForAnOrder();
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


void System::addProductToSeller()
{
	if (isEmpty(this->sellerArrLogSize)) {
		cout << "No sellers present in system." << endl;
	}
	else {
		cout << "\nPlease choose the seller to whom you'd like the add a product: " << endl;
		theMenu.printSellers(sellerArr, sellerArrLogSize); //print all of the sellers
		int chosenSellerIndex = theMenu.getUserChoice(sellerArrLogSize) - 1;
		Seller *chosenSeller = sellerArr[chosenSellerIndex];
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
			char feedBackDate[DATE_LENGTH];
			theMenu.getFeedbackFromUser(feedBackContent, MAX_FEEDBACK_SIZE, feedBackDate);
			Feedback newFeedback(chosenBuyer->getName(), feedBackContent, feedBackDate);
			chosenSeller->addFeedback(newFeedback);
		}
	}
}

void System::addProductToShoppingCart() {
	if (isEmpty(this->buyerArrLogSize)) {
		cout << "No buyers present in system." << endl;
	}
	else {
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
}

void System::placeOrder() {
	if (isEmpty(this->buyerArrLogSize)) {
		cout << "No buyers present in system." << endl;
	}
	else {
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
			cout << "The following products are in your shopping cart: " << endl << endl;
			theMenu.printSeperatorBlock('-');
			chosenBuyer->getShoppingCart()->show();
			theMenu.printSeperatorBlock('-');
			cout << endl << "Please choose product/s to order, separated by commas with no whitespace (e.g. 1,2,4,6): ";
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
			chosenBuyer->addOrderToOrderArr(newOrder);
			delete[] productsString;
		}
	}
}

void System::payForAnOrder() {
	if (isEmpty(this->buyerArrLogSize)) {
		cout << "No buyers present in system." << endl;
	}
	else {
		cout << "Please choose a buyer to pay for an order: " << endl;
		theMenu.printBuyers(buyerArr, buyerArrLogSize);
		int chosenBuyerIndex = theMenu.getUserChoice(buyerArrLogSize) - 1;
		Buyer *chosenBuyer = buyerArr[chosenBuyerIndex];
		if (isEmpty(chosenBuyer->getOrderArrLogSize())) {
			cout << "This buyer does not have any orders to pay for." << endl;
		}
		else {
			bool unpaidOrders = false; // Unless there are unpaid orders, the buyer can't pay
			cout << "This buyer has placed the following orders: " << endl << endl;
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
					chosenBuyer->addSellerToBuyerArr(*chosenOrderShoppingCart->getProducts()[i]->getSeller());
				}
			}
			else {
				cout << "All orders are already paid for." << endl;
			}
		}
	}
}