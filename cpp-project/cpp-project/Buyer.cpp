#include "Buyer.h"

Buyer::Buyer(string& name, string& password, Address* address, ShoppingCart *shoppingCart) : User(name, password, address)
{
	setShoppingCart(shoppingCart);
	this->unpaidOrder = NULL;
	this->orderStatus = false;
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
	this->orderHistory.push_back(&order);
}

const string Buyer::getName()
{
	return(this->getUserName());
}

list<User*>& Buyer::getSellerArr() { return sellerArr; }

list<Order*>& Buyer::getOrderArr() { return orderHistory; }

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

bool Buyer::getOrderStatus() { return this->orderStatus; }

Order* Buyer::getUnpaidOrder() { return this->unpaidOrder; }

<<<<<<< HEAD
Buyer::Buyer(ifstream& inFile) :User(inFile)
{
}
=======
void Buyer::closeOrder() {
	this->addOrderToOrderArr(* (new Order(*unpaidOrder)));
	this->unpaidOrder = NULL;
	this->orderStatus = false;
}

void Buyer::setUnpaidOrder(Order& order) {
	this->unpaidOrder = &order;
}
>>>>>>> 9f7c672e8626c78eb148a4027e173ea8d1bce517
