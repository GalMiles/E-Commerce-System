#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
#include "User.h"
using namespace std;

#pragma warning(disable: 4996)

class Product;

class Seller
{
public:
	Seller(User *sellerUser);
	bool setProducts(Product *products);
	Product *getProducts();
	int getAmount();

	void addProduct(Product **products, int count, Product product);

private:
	Product  *products;
	User     *sellerUser;
	int      countProducts;
};

#endif 