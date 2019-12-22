#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() //constructor
{
	this->shoppingCartLogSize = 0;
	this->shoppingCartPhysSize = 1;
	this->shoppingCart = new Product*[1];
}

ShoppingCart::ShoppingCart(const ShoppingCart& otherShoppingCart) {
	this->shoppingCartLogSize = 0;
	this->shoppingCartPhysSize = 1;
	this->shoppingCart = new Product*[1];
	for (int i = 0; i < otherShoppingCart.shoppingCartLogSize; i++) {
		addProductToShoppingCart(*(new Product(*otherShoppingCart.shoppingCart[i])));
	}
}

ShoppingCart::~ShoppingCart() //d'tor
{
	for (int i = 0; i < this->shoppingCartPhysSize; i++)
	{
		this->shoppingCart[i] = nullptr;
	}
}

Product** ShoppingCart::getProducts()
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

void ShoppingCart::addProductToShoppingCart(Product& productToAdd)
{
	if (this->shoppingCartLogSize == this->shoppingCartPhysSize) //realloc shopping cart
		shoppingCartRealloc();

	this->shoppingCart[this->shoppingCartLogSize] = new Product(productToAdd); // add product
	(this->shoppingCartLogSize)++;
}

int ShoppingCart::getShoppingCartLogSize()
{
	return (this->shoppingCartLogSize);
}

int ShoppingCart::getShoppingCartPhySize()
{
	return (this->shoppingCartPhysSize);
}

void ShoppingCart::show() {
	for (int i = 0; i < shoppingCartLogSize; i++) {
		cout << "[" << i + 1 << "]" << endl;
		shoppingCart[i]->show();
	}
}

void ShoppingCart::removeProductFromShoppingCart(int productID) {
	if (this->shoppingCartLogSize <= 0) {
		return;
	}
	else {
		int productIndex;
		for (int i = 0; i < this->shoppingCartLogSize; i++) {
			if (shoppingCart[i]->getProductId() == productID) {
				productIndex = i;
				break;
			}
		}
		for (int i = productIndex; i < this->shoppingCartLogSize - 1; i++) {
			this->shoppingCart[i] = this->shoppingCart[i + 1];
		}
		this->shoppingCart[shoppingCartLogSize] = nullptr;
		shoppingCartLogSize--;
	}
}
