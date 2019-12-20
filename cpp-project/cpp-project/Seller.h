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
	void productsArrRealloc();
	void feedbackArrRealloc();
	char* getName();
	void addProduct(Product *product);
	void addFeedback(Feedback *feedback);
	void show() const;


private:
	Product	  **products;
	User	  *sellerUser;
	int		   productsPhySize;
	int		   productsLogSize;
	Feedback   **feedbackArr;
	int        feedbackPhySize;
	int        feedbackLogSize;

};

#endif 