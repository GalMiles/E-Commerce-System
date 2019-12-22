#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "Seller.h"
#include "ShoppingCart.h"
#include "Buyer.h"

class Buyer;

class Order
{
private:
	ShoppingCart* shoppingCart;
	Buyer* buyer;
	Seller** sellers;
	double totalPrice;
	int numOfProducts;
	bool paid;


public:
	Order(ShoppingCart* shoppingCart, Buyer* buyer);
	Order(const Order& otherOrder);
	~Order();
	//Seller** getOrderSellers();
	Buyer* getBuyer();
	void calculateTotalPrice();
	double getTotalPrice();
	bool isPaid();
	void setPaymentStatus(bool paymentStatus);
	void setBuyer(Buyer* buyer);
	void setNumOfProducts(ShoppingCart* shoppingCart);
	void setShoppingCart(ShoppingCart* shoppingCart);
	ShoppingCart* getOrderShoppingCart();
	void setOrderSellers();
	enum ePaymentStatus { UNPAID, PAID };
	static constexpr char* paymentStatuses[] = { "UNPAID", "PAID" };


};

#endif