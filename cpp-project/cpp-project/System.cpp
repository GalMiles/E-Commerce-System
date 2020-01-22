#include "System.h"


System::System() : theMenu()
{
	sellerCount = 0;
	buyerCount = 0;
	sellerBuyerCount = 0;
}

/*
System::~System() {
	for (int i = 0; i < userArrPhySize; i++) {
		this->userArr[i] = nullptr;
	}
	delete[]userArr;
}*/

void System::initSystem() //initialize the system
{
	cout << "Welcome to " << storeName << endl;
	int choice;
	do {
		cout << endl;
		theMenu.printMenu();
		choice = theMenu.getUserChoice(OPTIONS_LENGTH);
		performChoice(choice);
	} while (choice != OPTIONS_LENGTH); //while the user didn't ask to exit the program
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
		//placeOrder();
		break;
	case 8:
		//payForAnOrder();
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

	theMenu.getUserInfoFromUser(userName, password, country, city, street, homeNumber, MAX_LENGTH);

	Address newAddress(country, city, street, homeNumber);

	if (userType == BUYER)
	{
		ShoppingCart newShoppingCart;
		Buyer newBuyer(userName, password, &newAddress, &newShoppingCart);
		userArr.push_back(new Buyer(newBuyer));
		this->buyerCount++;
	}

	else if (userType == SELLER) {
		Seller newSeller(userName, password, &newAddress);
		userArr.push_back(new Seller(newSeller));
		this->sellerCount++;
	}

	else if (userType == SELLER_BUYER) {
		ShoppingCart newShoppingCart;
		SellerBuyer newSellerBuyer(Seller(userName, password, &newAddress), Buyer(userName, password, &newAddress, &newShoppingCart));
		userArr.push_back(new SellerBuyer(newSellerBuyer));
		sellerCount++;
		buyerCount++;
		sellerBuyerCount++;
	}
}

/*
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
*/


void System::addProductToSeller()
{
	if (isEmpty(this->sellerCount)) {
		cout << "No sellers present in system." << endl;
	}
	else //if there is at least one seller in the system
	{
		cout << "\nPlease choose the name of the seller to whom you'd like the add a product: " << endl;

		theMenu.printSellersNames(userArr, sellerCount); //print all of the sellers

		User* chosenSeller;
		findUserByName(chosenSeller, this->userArr);
		string productName;
		double price;
		Product::eCategory categoryChoice;
		theMenu.addProductToSeller(productName, price, categoryChoice);
		Product newProduct(productName, price, categoryChoice, dynamic_cast<Seller*>(chosenSeller)); //createa new product
		dynamic_cast<Seller*>(chosenSeller)->addProduct(newProduct);
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
			string feedBackDate;
			theMenu.getFeedbackFromUser(feedBackContent, feedBackDate);
			Feedback newFeedback((chosenBuyer)->getUserName(), feedBackContent, feedBackDate);
			dynamic_cast<Seller*>(chosenSeller)->addFeedback(newFeedback);
		}
	}
}

void System::addProductToShoppingCart() {
	if (isEmpty(this->buyerCount)) {
		cout << "No buyers present in system." << endl;
	}
	else {
		cout << "\nPlease choose a buyer to add a product to his/her shopping cart: " << endl;
		theMenu.printBuyersNames(userArr,buyerCount );
		
		User* chosenBuyer;
		findUserByName(chosenBuyer, this->userArr);

		if (theMenu.printProducts(userArr, userArr.size())) {
			cout << "Please choose a seller to buy from: " << endl;

			User* chosenSeller;
			findUserByName(chosenSeller, this->userArr);

			cout << "Please choose the desired product number from this seller: " << endl;
			Product *chosenProduct;
			findProductByName(chosenProduct, dynamic_cast<Seller*>(chosenSeller)->getProducts());

			dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart()->addProductToShoppingCart(*chosenProduct);
		}
		else {
			cout << "No products present in the system." << endl;
		}
	}
}

/*
void System::placeOrder() {
	if (isEmpty(this->buyerCount)) {
		cout << "No buyers present in system." << endl;
	}
	else {
		cout << "\nPlease choose a buyer to make an order for: " << endl;
		theMenu.printBuyers(userArr, buyerCount);

		User* chosenBuyer;
		findUserByName(chosenBuyer, this->userArr);
		
		if (isEmpty(dynamic_cast<Buyer*>(chosenBuyer)->getShoppingCart()->getProducts().size())) {
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
			Order newOrder(&orderShoppingCart, dynamic_cast<Buyer*>(chosenBuyer));
			dynamic_cast<Buyer*>(chosenBuyer)->addOrderToOrderArr(newOrder);
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
		findUserByName(chosenBuyer, this->userArr);

		if (isEmpty(dynamic_cast<Buyer*>(chosenBuyer)->getOrderArr().size())) {
			cout << "This buyer does not have any orders to pay for." << endl;
		}
		else {
			bool unpaidOrders = false; // Unless there are unpaid orders, the buyer can't pay
			cout << "This buyer has placed the following orders: " << endl;
			list<Order*>::iterator itr = dynamic_cast<Buyer*>(chosenBuyer)->getOrderArr().begin();
			list<Order*>::iterator itrEnd = dynamic_cast<Buyer*>(chosenBuyer)->getOrderArr().end();
			int i = 0;
			for ( ; itr!= itrEnd; ++itr, i++) {
				bool isThisOrderPaid = (*itr)->isPaid();
				if (!isThisOrderPaid && !unpaidOrders) { // There is at least one unpaid order
					unpaidOrders = true;
				}
				cout << "[ Order Number " << i + 1 << " ]\t(Status: " << Order::paymentStatuses[isThisOrderPaid] << ')' << endl;
				theMenu.printSeperatorBlock('+');
				(*itr)->getOrderShoppingCart()->show();
				cout << "\n$ Total Price: " << (*itr)->getTotalPrice() << endl;
				theMenu.printSeperatorBlock('+');
				cout << endl;
			}
			int orderChoiceIndex;
			Order* chosenOrder;
			if (unpaidOrders) {
				cout << "Please choose an unpaid order to pay for: " << "[1 ~ " << dynamic_cast<Buyer*>(chosenBuyer)->getOrderArr().size() << ']';
				do {
					cin.ignore();
					orderChoiceIndex = theMenu.getUserChoice(dynamic_cast<Buyer*>(chosenBuyer)->>getOrderArr().size()) - 1;
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
*/

void System::findUserByName(User*& user, list<User*>& userList) {
	
	list<User*>::iterator itr = userList.begin();
	list<User*>::iterator itrEnd = userList.end();
	list<User*>::iterator chosenUser = userList.end();
	string toFind;

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

