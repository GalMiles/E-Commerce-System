#ifndef __MENU_H
#define __MENU_H

#include <iostream>
#include <string.h>
#include "Buyer.h"
#include "Feedback.h"
#include "Seller.h"
#include "Product.h"
#include "System.h"
using namespace std;

const int OPTIONS_LENGTH = 11;

class Menu
{
public:
	void printMenu();
	int getUserChoice();
	void getUserInfoFromUser(char* userName, char* password, char* country, char* city, char* street, int& homeNumber, int maxLength);
	void printSellers(Seller **sellerArr, int size);
	void printBuyers(Buyer **buyerArr, int size);


private:
	
	const char *options[OPTIONS_LENGTH] = { "Add a buyer", "Add a seller", "Add a product to seller's stock", "Add seller feedback", "Add a product to your shopping cart",
		"Place an order", "Pay for an order", "Show all buyers", "Show all sellers", "Search for a product", "Exit" };
};

#endif