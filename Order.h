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
	Order(ShoppingCart* shoppingCart, Buyer* buyer);
	ShoppingCart* shoppingCart;
	Buyer* buyer;
	Seller** sellers;
	double totalPrice;
	int numOfProducts;


public:
	Seller** getOrderSellers();
	Buyer* getBuyer();
	void calculateTotalPrice();
};

#endif