/*
This class holds info about the shopping cart
*/

#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H


#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

#include "Product.h"

#pragma warning(disable: 4996)

class ShoppingCart
{
public:
	ShoppingCart(); //c'tor
	//ShoppingCart(const ShoppingCart& otherShoppingCart); //copy c'tor
	list<Product*>& getProducts();
	void addProductToShoppingCart(Product& productToAdd);
	void removeProductFromShoppingCart(int productID);
	void show() const; //print shopping cart
	const double getTotalPrice();
	void setTotalPrice(double price);

	friend ostream& operator<<(ostream& os, const ShoppingCart& SCToPrint);

private:
	list<Product*> shoppingCart;
	double totalPrice;
};

class isIdFound //object function
{
public:
	isIdFound(int id) { m_productId = id; }
	bool operator()(Product* val)
	{
		if (val->getProductId() == m_productId)
			return true;

		return false;
	}

private:
	int m_productId;
};

#endif // __SHOPPINGCART_H