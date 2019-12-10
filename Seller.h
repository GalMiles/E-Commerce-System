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
	
	Product *getProducts();
	void addProduct(Product **products, int *logSize, int *phySize, Product *product);

	Product *productRealloc(Product **products, int logSize, int *phySize);


private:
	Product  **products;
	User      *sellerUser;
	int       countProducts;
};

#endif 