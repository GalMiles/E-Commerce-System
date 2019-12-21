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
	ShoppingCart(const ShoppingCart& otherShoppingCart);
	~ShoppingCart();
	Product** getProducts();
	void addProductToShoppingCart(Product& productToAdd);
	void shoppingCartRealloc(); //NOTE: we should probably use the function implemented in Seller
	void show();

	int getShoppingCartLogSize();
	int getShoppingCartPhySize();

private:
	Product** shoppingCart;
	int shoppingCartPhysSize;
	int shoppingCartLogSize;
};

#endif // __SHOPPINGCART_H