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
	Buyer::Buyer(User *userBuyer);
	Buyer(const Buyer& otherBuyer);
	~Buyer();

	ShoppingCart getShoppingCart();
	void sellerArrRealloc();
	void addSellerToBuyerArr(Seller &seller);
	void setUser(User* user);
	User *getUser();
	char *getName();
	int getSellerArrLogSize();
	Seller **getSellerArr();

	void show();

private:
	User			*buyerUser;
	Seller			**sellerArr;
	ShoppingCart	shoppingCart;
	int             sellerArrLogSize;
	int             sellerArrPhySize;

};

#endif