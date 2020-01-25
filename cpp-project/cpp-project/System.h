/*
This class is in charge of managing the system. 
It contains arrays of all of the users in the system
*/

#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <iostream>
#include "SellerBuyer.h"
#include "Seller.h"
#include "Buyer.h"
#include "Menu.h"
#include "Order.h"
<<<<<<< HEAD
#include <fstream>
=======
using namespace std;
>>>>>>> 9f7c672e8626c78eb148a4027e173ea8d1bce517

class System
{
public:
	System(); //c'tor
	System(System& other) = delete; //disabling the copy c'tor
	~System(); //d'tor
	enum eUserType { SELLER, BUYER, SELLER_BUYER };
	const string storeName = "AlmoGal";
	void initSystem(); //initialize the system
	bool isEmpty(int size); //determintes if an array is empty
	void addUser(eUserType userType); //creates a new user - buyer or seller

	/*
	const System& operator+=(const Seller seller);//instead of the two functions in comment
	const System& operator+=(const Buyer buyer);
	const System& operator+=(const SellerBuyer sellerbuyer);
	*/

	void performChoice(int choice); //gets a choice and performs the desired action
	void addProductToSeller(); //add product to seller's stock
	void addFeedbackToSeller(); //add feedback to seller
	void addProductToShoppingCart(); //add product to shopping cart
	void placeOrder(); //place an order (no payment)
	void payForAnOrder(); //pay for an existing order
	void findUserByName(User*& user, list<User*>& userList);
	void findProductByName(Product*& user, list<Product*>& productList);
<<<<<<< HEAD
	list<User*> loadAllUsers(string fileName);
	User* loadUser(ifstream& inFile);

=======
	bool isStrValid(string& str);
>>>>>>> 9f7c672e8626c78eb148a4027e173ea8d1bce517

private:
	Menu theMenu;
	list<User*> userArr;
	int sellerCount;
	int buyerCount;
	int sellerBuyerCount;
};

class isUserFound //object function
{
public:
	isUserFound(string& name) { m_name = name; }
	bool operator()(User* val)
	{
		if (val->getUserName() == m_name)
			return true;

		return false;
	}

private:
	string m_name;
};

class isProductFound //object function
{
public:
	isProductFound(string& name) { m_name = name; }
	bool operator()(Product* val)
	{
		if (val->getName() == m_name)
			return true;

		return false;
	}

private:
	string m_name;
};

#endif