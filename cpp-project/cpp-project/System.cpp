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
		choice = theMenu.getUserChoice();
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
	}

	else if (userType == SELLER) {
		Seller newSeller(&newUser);
	}
}

void System::addProductToSeller(Product *product)
{
	if (this->productsLogSize == this->productsPhysSize) //realloc arr
		productsArrRealloc();

	products[this->productsLogSize] = product; // add product
	(this->productsLogSize)++;
}

void System::addFeedbackToSeller(Feedback *feedback)
{
	if (this->feedbackLogSize == this->feedbackPhySize)
		feedbackArrRealloc();

	feedbackArr[this->feedbackLogSize] = feedback;
	(this->feedbackLogSize)++;

}