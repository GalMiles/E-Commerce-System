#include "Buyer.h"

Buyer::Buyer(string name, string password, Address* address, ShoppingCart *shoppingCart) : User(name, password, address)
{
	setShoppingCart(shoppingCart);
}


Buyer::Buyer(const Buyer& otherBuyer) : User(move(otherBuyer))
{
	this->sellerArr = otherBuyer.sellerArr;
	shoppingCart = new ShoppingCart(*otherBuyer.shoppingCart);
}

Buyer::~Buyer()
{

}

void Buyer::setShoppingCart(ShoppingCart* shoppingCart) {
	this->shoppingCart = shoppingCart;
}

ShoppingCart* Buyer::getShoppingCart() {
	return this->shoppingCart;
}

void Buyer::show() const
{
	//buyerUser->show();
}

void Buyer::addSellerToBuyerArr(User *seller)
{
	this->sellerArr.push_back(seller);
}

void Buyer::addOrderToOrderArr(Order &order)
{
	this->orderArr.push_back(&order);
}

string Buyer::getName()
{
	return(this->getUserName());
}

/*
User** Buyer::getSellerArr() { return sellerArr; }

Order** Buyer::getOrderArr() { return orderArr; }
*/

const Buyer& Buyer::operator>(const Buyer& other) const
{
	if (this->shoppingCart->getTotalPrice() > other.shoppingCart->getTotalPrice())
		return *this;

	else
		return other;
}

void Buyer::toOs(ostream& os) const
{
	os << "and his/her shopping cart's total price is: " <<this->shoppingCart->getTotalPrice() << endl;
}

