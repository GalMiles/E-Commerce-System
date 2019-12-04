#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class User;
class Product;


class Seller
{
public:
	bool setUser(User user);
	bool setProducts(Product *products);
	
	User getUser();
	Product *getProducts();
	int getAmount();

	void addProduct(Product **products, int count, Product product);

private:
	Product  *m_products;
	User     m_user;
	int      m_countProducts;
};

#endif 