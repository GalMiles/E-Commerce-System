#include "Buyer.h"

Buyer::Buyer(User *userBuyer, ShoppingCart *shoppingCart)
{
	cout << "In Buyer constructor\n";
	this->user = userBuyer;
	this->shoppingCart = *shoppingCart;
}

void Buyer::setShoppingCart(ShoppingCart shoppingCart) {
	this->shoppingCart = shoppingCart;
}

const ShoppingCart Buyer::getShoppingCart() {
	return this->shoppingCart;
}

