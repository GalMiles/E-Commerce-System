#ifndef _MENU_H
#define __MENU_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

const int OPTIONS_LENGTH = 11;

class Menu
{
public:
	int initMenu();
	void choiceCases(int choice);
	void addBuyer();
	void addSeller();
	void addFeedback();
	void addProductToSeller();

private:
	const char *options[OPTIONS_LENGTH] = { "Add a buyer", "Add a seller", "Add a product to seller's stock", "Add seller feedback", "Add a product to your shopping cart",
											"Place an order", "Pay for an order", "Show all buyers", "Show all sellers", "Search for a product", "Exit" };
};


#endif