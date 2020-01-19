/*
This class holds info about the shopping cart
*/

#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H


#include <iostream>
#include <list>
#include <iterator>
#include <string.h>
using namespace std;

#include "Product.h"

#pragma warning(disable: 4996)

class ShoppingCart
{
public:
	ShoppingCart(); //c'tor
	ShoppingCart(const ShoppingCart& otherShoppingCart); //copy c'tor
	//Product** getProducts();
	void addProductToShoppingCart(Product& productToAdd);
	void removeProductFromShoppingCart(int productID);
	void show(); //print shopping cart
	double getTotalPrice();
	void setTotalPrice(double price);

	friend ostream& operator<<(ostream& os, const ShoppingCart& SCToPrint);


private:
	list<Product*> shoppingCart;
	double totalPrice;
};

#endif // __SHOPPINGCART_H