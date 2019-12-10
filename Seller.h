#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

#include "User.h"
class Product;


class Seller
{
public:
	bool setProducts(Product *products);
	
	User getUser();
	Product *getProducts();
	int getAmount();

	void addProduct(Product **products, int count, Product product);

private:
	Product  *products;
	User      user;
	int       countProducts;
};

#endif 