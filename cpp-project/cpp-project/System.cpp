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
	theMenu.printMenu();
	int choice;
	do {
		choice = theMenu.getUserChoice(OPTIONS_LENGTH);
		performChoice(choice);
	} while (choice != 11);
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

void System::addSellerToSellerArr(Seller *seller)
{
	if (this->sellerArrLogSize == this->sellerArrPhySize)
		sellerArrRealloc();

	sellerArr[this->sellerArrLogSize] = seller;
	(this->sellerArrLogSize)++;
}

void System::addBuyerToBuyerArr(Buyer *buyer)
{
	if (this->buyerArrLogSize == this->buyerArrPhySize)
		buyerArrRealloc();

	buyerArr[this->buyerArrLogSize] = buyer; 
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
	case 8:
		theMenu.printBuyers(buyerArr, buyerArrLogSize);
		break;
	case 9:
		theMenu.printSellers(sellerArr, sellerArrLogSize);
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
		Buyer newBuyer(&newUser);
		addBuyerToBuyerArr(&newBuyer); // TODO: Test if a copy c'tor is needed
	}

	else if (userType == SELLER) {
		Seller newSeller(&newUser);
		addSellerToSellerArr(&newSeller); // TODO: Test if a copy c'tor is needed
	}
}

void System::addProductToSeller(Product *product)
{
	cout << "\nPlease choose the seller to whom you'd like the add a product: " << endl;
	theMenu.printSellers(sellerArr, sellerArrLogSize);
	int chosenSellerIndex = theMenu.getUserChoice(sellerArrLogSize) - 1;
	Seller *chosenSeller = sellerArr[chosenSellerIndex];
	chosenSeller->addProduct(product);
}

void System::addFeedbackToSeller()
{
	cout << "\nPlease choose a buyer to submit feedback: " << endl;
	theMenu.printBuyers(buyerArr, buyerArrLogSize);
	int chosenBuyerIndex = theMenu.getUserChoice(buyerArrLogSize) - 1;
	Buyer *chosenBuyer = buyerArr[chosenBuyerIndex];
	cout << "\nPlease choose the seller to whom you'd like the add a feedback: " << endl;
	theMenu.printSellers(chosenBuyer->getSellerArr(), chosenBuyer->getSellerArrLogSize());
	int chosenSellerIndex = theMenu.getUserChoice(chosenBuyer->getSellerArrLogSize()) - 1;
	Seller *chosenSeller = chosenBuyer->getSellerArr()[chosenSellerIndex];
	char feedBackContent[MAX_FEEDBACK_SIZE];
	theMenu.getFeedbackFromUser(feedBackContent, MAX_FEEDBACK_SIZE);
	Feedback newFeedback(chosenBuyer->getName(), feedBackContent);
	chosenSeller->addFeedback(&newFeedback);
}