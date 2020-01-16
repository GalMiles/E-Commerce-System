/*
This class is in charge of getting input from the user
*/

#ifndef __MENU_H
#define __MENU_H

#include <iostream>
#include <string.h>
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
	void getUserInfoFromUser(char* userName, char* password, char* country, char* city, char* street, int& homeNumber, int maxLength); //get info required to create a User object
	bool validateDate(char* date); //validate date
	void getFeedbackFromUser(char* feedBack, int feedBackSize, char* date); //get info required to create a Feedback object
	void addProductToSeller(char* productName, double& price, Product::eCategory& categoryChoice); //get info required in order to add a product to a seller's stock
	void printSellers(User **userArr, int arrSize, int numOfKind); //print info about all of the sellers in the system
	void printSellerBuyers(User **userArr, int arrSize, int numOfKind); //print info about all of the seller/buyers in the system
	void printBuyers(User **userArr, int arrSize, int numOfKind); //print info about all of the buyers in the system
	bool printProducts(User **userArr, int size); //print all of the seller's products
	void printProductsWithName(User **userArr, int size, int sellerCount); //search for a product and print all of the matching ones
	void printSeperatorBlock(char sep); //print separators (to make the UI look nicer)
	void printSellersNames(User **userArr, int size, int numOfKind);
	void printBuyersNames(User **userArr, int size, int numOfKind);

	int testOperatorsOptions();


	
private:
	const char *options[OPTIONS_LENGTH] = { "Add a buyer", "Add a seller", "Add a Seller who is also a Buyer", "Add a product to seller's stock", "Add seller feedback", "Add a product to your shopping cart",
		"Place an order", "Pay for an order", "Show all buyers", "Show all sellers", "Show all Sellers who are also Buyers", "Search for a product", "Test operators", "Exit" };
};

#endif