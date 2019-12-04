#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class Product;
class User;

class Buyer
{
public:
	bool setUser(User user);
	bool setShoppingCart(Product *shoppingCart);
	const Product **getShoppingCart();
	void addProductToCart(Product **shoppingCart);

private:
	Product  **m_shoppingCart;
	User       m_user;
};

#endif