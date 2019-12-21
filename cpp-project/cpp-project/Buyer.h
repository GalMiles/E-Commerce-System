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
	Buyer::Buyer(User *userBuyer, ShoppingCart *shoppingCart);
	Buyer(const Buyer& otherBuyer);
	~Buyer();

	void sellerArrRealloc();
	void addSellerToBuyerArr(Seller &seller);
	void setUser(User* user);
	void setShoppingCart(ShoppingCart* shoppingCart);
	User *getUser();
	char *getName();
	int getSellerArrLogSize();
	Seller **getSellerArr();
	ShoppingCart* getShoppingCart();

	void show();

private:
	User			*buyerUser;
	Seller			**sellerArr;
	ShoppingCart	*shoppingCart;
	int             sellerArrLogSize;
	int             sellerArrPhySize;

};

#endif