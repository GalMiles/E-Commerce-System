#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
#include "Product.h"
#include "User.h"
using namespace std;

#pragma warning(disable: 4996)

class Buyer
{
public:
	bool setUser(User user);
	bool setShoppingCart(Product *shoppingCart);

public:
	
	const Product **getShoppingCart();
	void addProductToCart(Product **shoppingCart);////

private:
	Product  **m_shoppingCart;
	User       m_user;
};

#endif