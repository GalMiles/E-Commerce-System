/*
This class is in charge of getting input from the user
*/

#ifndef __MENU_H
#define __MENU_H

#include <iostream>
#include <string>
#include "Buyer.h"
#include "Feedback.h"
#include "Seller.h"
#include "Product.h"
#include "SellerBuyer.h"
using namespace std;

const int OPTIONS_LENGTH = 14; //number of options in the menu
const int SEPERATOR_BLOCK_LENGTH = 52; // Amount of chars to print per seperator block

class Menu
{
public:
	void printMenu();
	int getUserChoice(int optionsLength); //gets a choice from the user and validates it is within the options range
	void getUserInfoFromUser(string& userName, string& password, string& country, string& city, string& street, int& homeNumber, int maxLength); //get info required to create a User object
	bool validateDate(char* date); //validate date
	void getFeedbackFromUser(string& feedBack, string& date); //get info required to create a Feedback object
	void addProductToSeller(string& productName, double& price, Product::eCategory& categoryChoice); //get info required in order to add a product to a seller's stock
	void printSellers(const list<User*>& userArr, int numOfKind); //print info about all of the sellers in the system
	void printSellerBuyers(const list<User*>& userArr, int numOfKind); //print info about all of the seller/buyers in the system
	void printBuyers(const list<User*>& userArr, int numOfKind); //print info about all of the buyers in the system
	bool printProducts(list<User*>& userArr, int size); //print all of the seller's products
	void printProductsWithName(list<User*>& userArr, int sellerCount); //search for a product and print all of the matching ones
	void printSeperatorBlock(char sep); //print separators (to make the UI look nicer)
	void printSellersNames(const list<User*>& userArr, int numOfKind);
	void printBuyersNames(const list<User*>& userArr, int numOfKind);
	friend bool isSeller(User& user);
	friend bool isBuyer(User& user);
	friend bool isSellerBuyer(User& user);

	int testOperatorsOptions();

	void getStrFromUser(string& input);


	
private:
	const char *options[OPTIONS_LENGTH] = { "Add a buyer", "Add a seller", "Add a Seller who is also a Buyer", "Add a product to seller's stock", "Add seller feedback", "Add a product to your shopping cart",
		"Place an order", "Pay for an order", "Show all buyers", "Show all sellers", "Show all Sellers who are also Buyers", "Search for a product", "Test operators", "Exit" };
};

bool isSeller(User& user) {
	return (typeid(user) == typeid(Seller)) || (typeid(user) == typeid(SellerBuyer));
}

bool isBuyer(User& user) {
	return (typeid(user) == typeid(Buyer)) || (typeid(user) == typeid(SellerBuyer));
}

bool isSellerBuyer(User& user) {
	return ((typeid(user) == typeid(SellerBuyer)));
}


#endif