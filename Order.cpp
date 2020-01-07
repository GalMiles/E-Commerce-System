#include "Order.h"

Order::Order(ShoppingCart* shoppingCart, Buyer* buyer)
{
	this->shoppingCart = shoppingCart;
	this->numOfProducts = shoppingCart->getSoppingCartPhySize();
	this->buyer = buyer;
	calculateTotalPrice();
	this->sellers = new Seller*[numOfProducts];
}

Order::~Order() {
	cout << "order d'tor" << endl;
	for (int i = 0; i < this->numOfProducts; i++)
	{
		this->sellers[i] = nullptr;
	}
	delete[]sellers;
}

void Order::setOrderSellers() {
	Product* p;
	for (int i = 0; i < numOfProducts; i++) {
		p = shoppingCart->getShoppingCart()[i];
		sellers[i] = p->getSeller();
	}
}

void Order::calculateTotalPrice()
{
	Product* p;
	this->totalPrice = 0;
	for (int i = 0; i < numOfProducts; i++) {
		p = shoppingCart->getShoppingCart()[i];
		this->totalPrice += p->getPrice();
	}
}

double Order::getTotalPrice() {
	return this->totalPrice;
}

Buyer* Order::getBuyer()
{
	return this->buyer;
}
