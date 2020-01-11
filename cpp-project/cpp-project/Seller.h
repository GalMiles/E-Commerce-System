/*
This class holds info about sellers
*/

#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

#include "User.h"
#include "Product.h"

//forward declaration
class Feedback;

class Seller : public User
{
public:
	Seller(char* name, char* password, Address* address); //c'tor
	Seller(const Seller& otherSeller); //copy c'tor
	~Seller(); //d'tor

	Product** getProducts();
	void productsArrRealloc(); //reallocate memory for productsArr
	void feedbackArrRealloc();//reallocate memory for feedbackArr
	char* getName();
	int getProductsLogSize();
	void addProduct(Product &product); //add product to productArr
	void addFeedback(Feedback &feedback); //add feedback to feedbackArr
	void show() const; //print info about this seller


private:
	Product	  **products;
	int		   productsPhySize;
	int		   productsLogSize;
	Feedback   **feedbackArr;
	int        feedbackPhySize;
	int        feedbackLogSize;

};

#endif 