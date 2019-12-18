#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "ShoppingCart.h"
#include "Buyer.h"


class Order
{
private:
	ShoppingCart* shoppingCart;
	Buyer* buyer;
	Seller** sellers;
	double totalPrice;
	int numOfProducts;


public:
	Order(ShoppingCart* shoppingCart, Buyer* buyer);
	~Order();
	Seller** getOrderSellers();
	Buyer* getBuyer();
	void calculateTotalPrice();
	double getTotalPrice();
	void setOrderSellers();

};

#endif