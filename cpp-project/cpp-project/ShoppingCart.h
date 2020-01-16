/*
This class holds info about the shopping cart
*/

#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H


#include <iostream>
#include <string.h>
using namespace std;

#include "Product.h"

#pragma warning(disable: 4996)

class ShoppingCart
{
public:
	ShoppingCart(); //c'tor
	ShoppingCart(const ShoppingCart& otherShoppingCart); //copy c'tor
	~ShoppingCart(); //d'tor
	Product** getProducts();
	void addProductToShoppingCart(Product& productToAdd);
	void removeProductFromShoppingCart(int productID);
	void shoppingCartRealloc();
	void show(); //print shopping cart

	int getShoppingCartLogSize();
	int getShoppingCartPhySize();

	double getTotalPrice();
	void setTotalPrice(double price);

	friend ostream& operator<<(ostream& os, const ShoppingCart& shoppingCart);


private:
	Product** shoppingCart;
	int shoppingCartPhysSize;
	int shoppingCartLogSize;
	double totalPrice;
};

#endif // __SHOPPINGCART_H