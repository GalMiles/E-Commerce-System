#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
#include "User.h"
using namespace std;

#pragma warning(disable: 4996)

class Product;

class Buyer
{
public:
	Buyer(User *buyerUser);
	//~Buyer();
	bool setShoppingCart(Product *shoppingCart);
	const Product **getShoppingCart();
	//void addProductToCart(Product **shoppingCart);

private:
	Product		**m_shoppingCart;
	User		*user;
};

#endif