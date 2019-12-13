#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() //constructor
{ 
	this->shoppingCartLogSize = 0;
	this->shoppingCartPhysSize = 1;
	this->shoppingCart = new Product*[1];
}

ShoppingCart::~ShoppingCart() //d'tor
{
	for (int i = 0; i < this->shoppingCartLogSize; i++)
	{
		this->shoppingCart[i] = nullptr;
	}
	delete[] this->shoppingCart;
}

Product** ShoppingCart::getShoppingCart()
{
	return shoppingCart;
}

void ShoppingCart::shoppingCartRealloc()
{
	Product **new_arr;
	this->shoppingCartPhysSize *= 2;
	new_arr = new Product*[this->shoppingCartPhysSize];

	for (int i = 0; i < this->shoppingCartLogSize; i++)
	{
		new_arr[i] = (this->shoppingCart[i]);
		this->shoppingCart[i] = nullptr;
	}
	delete[] this->shoppingCart;

	this->shoppingCart = new_arr;
}

void ShoppingCart::addProductToShoppingCart(Product* productToAdd)
{
	if (this->shoppingCartLogSize == this->shoppingCartPhysSize) //realloc shopping cart
		shoppingCartRealloc();

	this->shoppingCart[this->shoppingCartLogSize] = productToAdd; // add product
	(this->shoppingCartLogSize)++;
}