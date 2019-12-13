#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
#include "User.h"
using namespace std;

#include "ShoppingCart.h"

#pragma warning(disable: 4996)

class Product;

class Buyer
{
public:
	Buyer(User *buyerUser, ShoppingCart *shoppingCart);
	//~Buyer();
	void setShoppingCart(ShoppingCart shoppingCart); //NOTE: should this be bool?
	const ShoppingCart getShoppingCart();

private:
	ShoppingCart	shoppingCart;
	User			*user;
};

#endif