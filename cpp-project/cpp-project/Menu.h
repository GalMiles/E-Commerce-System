#ifndef __MENU_H
#define __MENU_H

#include <iostream>
#include <string.h>
#include "Buyer.h"
#include "Feedback.h"
#include "Seller.h"
#include "Product.h"
using namespace std;

const int OPTIONS_LENGTH = 11;
const int SEPERATOR_BLOCK_LENGTH = 25; // Amount of hyphens/dashes to print per seperator block

class Menu
{
public:
	void printMenu();
	int getUserChoice(int optionsLength);
	void getUserInfoFromUser(char* userName, char* password, char* country, char* city, char* street, int& homeNumber, int maxLength);
	void getFeedbackFromUser(char* feedBack, int feedBackSize);
	void addProductToSeller(char* productName, double& price, Product::eCategory& categoryChoice);
	void printSellers(Seller **sellerArr, int size);
	void printBuyers(Buyer **buyerArr, int size);
	void printProducts(Seller** sellerArr, int size);
	void printProductsWithName(Seller **sellerArr, int size);
	void printSeperatorBlock();

	


private:
	
	const char *options[OPTIONS_LENGTH] = { "Add a buyer", "Add a seller", "Add a product to seller's stock", "Add seller feedback", "Add a product to your shopping cart",
		"Place an order", "Pay for an order", "Show all buyers", "Show all sellers", "Search for a product", "Exit" };
};

#endif