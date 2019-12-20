#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

#include "User.h"
#include "Product.h"
class Feedback;

class Seller
{
public:
	Seller(User *sellerUser);
	Seller(const Seller&) = delete;
	//~Seller // TODO: Add d'tor

	Product** getProducts();
	void addProductToSeller(Product *product);
	void addFeedbaclToSeller(Feedback *feedback);
	void productsArrRealloc();
	void feedbackArrRealloc();
	char* getName();
	void show() const;


private:
	Product	  **products;
	User	  *sellerUser;
	int		   productsPhysSize;
	int		   productsLogSize;
	Feedback   **feedbackArr;
	int        feedbackPhySize;
	int        feedbackLogSize;

};

#endif 