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
	Order(ShoppingCart*& shoppingCart, Buyer*& buyer);
	Order(const Order& otherOrder);
	~Order();
	Seller** getOrderSellers();
	Buyer* getBuyer();
	void calculateTotalPrice();
	double getTotalPrice();
	void setBuyer(Buyer*& buyer);
	void setNumOfProducts(ShoppingCart*& shoppingCart);
	void setShoppingCart(ShoppingCart*& shoppingCart);
	void setOrderSellers();

};

#endif