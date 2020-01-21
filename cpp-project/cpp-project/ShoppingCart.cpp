#include "ShoppingCart.h"


ShoppingCart::ShoppingCart() //constructor
{
	this->totalPrice = 0;
}

/*
ShoppingCart::ShoppingCart(const ShoppingCart& otherShoppingCart) {
	this->shoppingCart = otherShoppingCart.shoppingCart;
	this->totalPrice = otherShoppingCart.totalPrice;
}*/


list<Product*>& ShoppingCart::getProducts()
{
	return shoppingCart;
}



void ShoppingCart::addProductToShoppingCart(Product& productToAdd)
{
	this->shoppingCart.push_back(&productToAdd);
}

void ShoppingCart::show() const {
	list<Product*>::const_iterator itr = shoppingCart.begin();
	list<Product*>::const_iterator itrEnd = shoppingCart.end();
	int i = 0;
	for ( ; itr != itrEnd; ++itr) {
		cout << "[" << i + 1 << "]" << endl;
		i++;
		(*itr)->show();
	}
}

void ShoppingCart::removeProductFromShoppingCart(int productID) 
{
	if (shoppingCart.empty()) { return; }//if there are no products in the shopping cart
	
	else
	{
		list<Product*>::iterator found = find_if(shoppingCart.begin(), shoppingCart.end(), isIdFound(productID));
	}
		
}


const double ShoppingCart::getTotalPrice() { return this->totalPrice; }

void ShoppingCart::setTotalPrice(double price) {
	this->totalPrice = price;
}

ostream& operator<<(ostream& os, const ShoppingCart& SCToPrint)
{
	list<Product*>::const_iterator itr = SCToPrint.shoppingCart.begin();
	list<Product*>::const_iterator itrEnd = SCToPrint.shoppingCart.end();
	int i = 0;
	for (; itr != itrEnd; ++itr) {
		cout << "[" << i + 1 << "]" << endl;
		i++;
		(*itr)->show();
	}
	return os;
}
