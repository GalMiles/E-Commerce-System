/*
This class holds info about buyers.
It contains their user's info, their shopping cart, an array of the sellers they have purchased from and their order history
*/

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


//forward declarations:
class Product;

class Order;

class Buyer : public User
{
public:
	Buyer::Buyer(char* name, char* password, Address* address, ShoppingCart *shoppingCart); //c'tor
	Buyer(const Buyer& otherBuyer); //copy c'tor
	~Buyer(); //d'tor

	void sellerArrRealloc(); //reallocate memory for sellerArr
	void orderArrRealloc(); //reallocate memory for orderArr
	void addSellerToBuyerArr(Seller &seller); //add seller to the buyer's sellers array
	void addOrderToOrderArr(Order &order); //add order to they buyer's order history
	void setShoppingCart(ShoppingCart* shoppingCart);
	char *getName();
	int getSellerArrLogSize();
	int getOrderArrLogSize();
	Seller **getSellerArr();
	Order **getOrderArr();
	ShoppingCart* getShoppingCart();
	bool operator>(const Buyer& other) const;

	void show(); //print buyer's info

private:
	Seller			**sellerArr;
	Order			**orderArr;
	ShoppingCart	*shoppingCart;
	int             sellerArrLogSize;
	int             sellerArrPhySize;
	int             orderArrLogSize;
	int             orderArrPhySize;

};

#endif