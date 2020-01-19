#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() //constructor
{
	this->totalPrice = 0;
}

ShoppingCart::ShoppingCart(const ShoppingCart& otherShoppingCart) {
	this->shoppingCart = otherShoppingCart.shoppingCart;
	this->totalPrice = otherShoppingCart.totalPrice;
}

/*
Product** ShoppingCart::getProducts()
{
	return shoppingCart;
}
*/


void ShoppingCart::addProductToShoppingCart(Product& productToAdd)
{
	this->shoppingCart.push_back(&productToAdd);
}

void ShoppingCart::show() {
	list<Product*>::iterator itr = shoppingCart.begin();
	list<Product*>::iterator itrEnd = shoppingCart.end();
	int i = 0;
	for ( ; itr != itrEnd; ++itr) {
		cout << "[" << i + 1 << "]" << endl;
		i++;
		(*itr)->show();
	}
}
/*
void ShoppingCart::removeProductFromShoppingCart(int productID) {
	if (shoppingCart.empty()) { //if there are no products in the shopping cart
		return;
	}
	else {
		int productIndex; //index of the product we want to delete
		for (int i = 0; i < this->shoppingCartLogSize; i++) {
			if (shoppingCart[i]->getProductId() == productID) { //if this is the product we want to delete
				productIndex = i;
				break; //break the loop
			}
		}
		for (int i = productIndex; i < this->shoppingCartLogSize - 1; i++) { //deleting the product
			this->shoppingCart[i] = this->shoppingCart[i + 1];
		}
		this->shoppingCart[shoppingCartLogSize] = nullptr;
		shoppingCartLogSize--;
	}
}
*/

double ShoppingCart::getTotalPrice() { return this->totalPrice; }

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
