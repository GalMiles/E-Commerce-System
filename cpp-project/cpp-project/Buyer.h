#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "User.h"
#include "ShoppingCart.h"
#include "Seller.h"
#include"Order.h"

#pragma warning(disable: 4996)

class Product;

//class Order;

class Buyer
{
public:
	Buyer::Buyer(User *userBuyer, ShoppingCart *shoppingCart);
	Buyer(const Buyer& otherBuyer);
	~Buyer();

	void sellerArrRealloc();
	void orderArrRealloc();
	void addSellerToBuyerArr(Seller &seller);
	void addOrderToOrderArr(Order &order);
	void setUser(User* user);
	void setShoppingCart(ShoppingCart* shoppingCart);
	User *getUser();
	char *getName();
	int getSellerArrLogSize();
	Seller **getSellerArr();
	Order **getOrderArr();
	ShoppingCart* getShoppingCart();

	void show();

private:
	User			*buyerUser;
	Seller			**sellerArr;
	Order			**orderArr;
	ShoppingCart	*shoppingCart;
	int             sellerArrLogSize;
	int             sellerArrPhySize;
	int             orderArrLogSize;
	int             orderArrPhySize;

};

#endif