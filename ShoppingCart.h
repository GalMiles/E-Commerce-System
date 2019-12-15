#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H


#include <iostream>
#include <string.h>
using namespace std;

#include "Product.h"

#pragma warning(disable: 4996)

class ShoppingCart
{
public:
	ShoppingCart();
	~ShoppingCart();
	Product** getShoppingCart();
	void addProductToShoppingCart(Product* productToAdd); //NOTE: should this be bool?
	void shoppingCartRealloc(); //NOTE: we should probably use the function implemented in Seller

	int getSoppingCartLogSize();
	int getSoppingCartPhySize();

private:
	Product** shoppingCart;
	int shoppingCartPhysSize;
	int shoppingCartLogSize;
};

#endif // __SHOPPINGCART_H
