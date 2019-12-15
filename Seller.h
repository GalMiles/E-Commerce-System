#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

#include "User.h"
#include "Product.h"


class Seller
{
public:
	Seller(User *sellerUser);
	Product** getProducts();
	void addProductToSeller(Product *product);
	void productsArrRealloc();
	void show() const;
	//addfeedbacktoarray

private:
	Product	**products;
	User	*sellerUser;
	int		productsPhysSize;
	int		productsLogSize;
	//add feedback array+logsize+physize;
};

#endif 