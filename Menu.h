#ifndef _MENU_H
#define __MENU_H

#include <iostream>
#include <string.h>
using namespace std;

class Menu
{
public:
	const int OPTIONS_LENGTH = 11;
	int initMenu();

private:
	const char *options[OPTIONS_LENGTH] = { "Add a buyer", "Add a seller", "Add a product to seller's stock", "Add seller feedback", "Add a product to your shopping cart",
											"Place an order", "Pay for an order", "Show all buyers", "Show all sellers", "Search for a product", "Exit" };
};


#endif