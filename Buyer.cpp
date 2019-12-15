#include "Buyer.h"

Buyer::Buyer(User *userBuyer, ShoppingCart *shoppingCart)
{
	cout << "In Buyer constructor\n";
	this->buyerUser = userBuyer;
	this->shoppingCart = *shoppingCart;
}

void Buyer::setShoppingCart(ShoppingCart shoppingCart) {
	this->shoppingCart = shoppingCart;
}

const ShoppingCart Buyer::getShoppingCart() {
	return this->shoppingCart;
}

void Buyer::show()
{
	buyerUser->show(); //using User's method

	cout << "The buyer's products are:" << endl;
	/*for (int i = 0; i < this->shoppingCart.getSoppingCartLogSize; i++)
	{
		cout << shoppingCart.shoppingCart[i].getName;
	}
	*/
}


