/*
This class holds info about orders
*/

#ifndef __ORDER_H
#define __ORDER_H

#include <iostream>
#include <string.h>
#include "Seller.h"
#include "ShoppingCart.h"
#include "Buyer.h"
using namespace std;


class Buyer;

class Order
{
public:
	Order(ShoppingCart* shoppingCart, Buyer* buyer); //c'tor
	//Order(const Order& otherOrder); //copy c'tor
	Buyer* getBuyer();
	void calculateTotalPrice(); //calculates total price of the items
	double getTotalPrice();
	bool isPaid(); //is this order paid
	void setPaymentStatus(bool paymentStatus); //sets payment status - PAID/UNPAID
	void setBuyer(Buyer* buyer);
	void setShoppingCart(ShoppingCart* shoppingCart);
	ShoppingCart* getOrderShoppingCart();
	void setOrderSellers(); //set array of sellers whom the products of this order were purchased from
	enum ePaymentStatus { UNPAID, PAID };
	static constexpr char* paymentStatuses[] = { "UNPAID", "PAID" }; //strings for the enum

private:
	ShoppingCart* shoppingCart;
	Buyer* buyer;
	list<Seller*> sellers;
	double totalPrice;
	bool paid;
};

#endif