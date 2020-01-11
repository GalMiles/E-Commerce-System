/*
This class is in charge of managing the system. 
It contains arrays of all of the users in the system
*/

#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "Seller.h"
#include "Buyer.h"
#include "Menu.h"
#include "Order.h"

const int MAX_FEEDBACK_SIZE = 100; //limit the feedback's length

class System
{
public:
	System(); //c'tor
	System(System& other) = delete; //disabling the copy c'tor
	~System(); //d'tor
	enum eUserType { SELLER, BUYER };
	const char STORE_NAME[8] = "AlmoGal";
	void initSystem(); //initialize the system
	bool isEmpty(int size); //determintes if an array is empty
	void userArrRealloc();
	void addUserToArr(User &user);
	void performChoice(int choice); //gets a choice and performs the desired action
	void addUser(eUserType userType); //creates a new user - buyer or seller
	void addProductToSeller(); //add product to seller's stock
	void addFeedbackToSeller(); //add feedback to seller
	void addProductToShoppingCart(); //add product to shopping cart
	void placeOrder(); //place an order (no payment)
	void payForAnOrder(); //pay for an existing order


private:
	Menu theMenu;
	Seller **sellerArr;
	Buyer **buyerArr;
	User** userArr;
	int userArrLogSize;
	int userArrPhySize;
	int sellerCount;
	int buyerCount;
};

#endif