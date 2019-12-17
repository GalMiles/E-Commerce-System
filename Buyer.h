#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
#include "User.h"
using namespace std;

#include "ShoppingCart.h"
#include "Seller.h"

#pragma warning(disable: 4996)

class Product;

class Buyer
{
public:
	Buyer(User *buyerUser, ShoppingCart *shoppingCart);
	Buyer(const Buyer&) = delete;
	~Buyer();

	void setShoppingCart(ShoppingCart shoppingCart); //NOTE: should this be bool?
	const ShoppingCart getShoppingCart();
	void sellerArrRealloc();
	void addSellerToBuyerArr(Seller *seller);
	User *getUser();
	char *getName();
	int getSellerArrLogSize();
	Seller **getSellerArr();

	void show();

private:
	ShoppingCart	shoppingCart;
	User			*buyerUser;
	Seller			**sellerArr;
	int             sellerArrLogSize;
	int             sellerArrPhySize;

};

#endif