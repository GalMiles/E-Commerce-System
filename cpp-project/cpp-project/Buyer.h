/*
This class holds info about buyers. It inherits from User
It contains their user's info, their shopping cart, an array of the sellers they have purchased from and their order history
*/

#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <list> 
#include <iterator>
#include <string>
using namespace std;

#include "User.h"
#include "ShoppingCart.h"
#include "Seller.h"
#include"Order.h"

#pragma warning(disable: 4996)


//forward declarations:
class Product;
class Order;

class Buyer : virtual public User
{
public:
	Buyer::Buyer(string& name, string& password, Address* address, ShoppingCart *shoppingCart); //c'tor
	Buyer(const Buyer& otherBuyer); //copy c'tor
	~Buyer(); //d'tor
	Buyer(ifstream& inFile);

	void addSellerToBuyerArr(User *seller); //add seller to the buyer's sellers array
	void addOrderToOrderArr(Order &order); //add order to they buyer's order history
	void setShoppingCart(ShoppingCart* shoppingCart); 
	void setUnpaidOrder(Order& order); //set the current unpaid order
	const string getName();
	list<User*>& getSellerArr();
	list<Order*>& getOrderArr();
	ShoppingCart* getShoppingCart();
	bool getOrderStatus();
	Order* getUnpaidOrder();
	void closeOrder();
	const Buyer& operator>(const Buyer& other) const;
	virtual void toOs(ostream& os) const override;
	void show() const; 


private:
	list<User*>		sellerArr;
	Order*			unpaidOrder;
	bool			orderStatus; //indicates whether the seller has an unpaid order or not
	list<Order*>	orderHistory;
	ShoppingCart	*shoppingCart;
};

#endif