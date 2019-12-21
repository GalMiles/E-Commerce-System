#include "Order.h"

Order::Order(ShoppingCart*& shoppingCart, Buyer*& buyer)
{
	setShoppingCart(shoppingCart);
	setNumOfProducts(shoppingCart);
	setBuyer(buyer);
	calculateTotalPrice();
	this->sellers = new Seller*[numOfProducts];
	setOrderSellers();
}

Order::Order(const Order& otherOrder) {
	shoppingCart = new ShoppingCart(*otherOrder.shoppingCart);
	numOfProducts = *(new int(shoppingCart->getShoppingCartLogSize()));
	buyer = new Buyer(*otherOrder.buyer);
	calculateTotalPrice();
	sellers = new Seller*[numOfProducts];
	for (int i = 0; i < numOfProducts; i++) {
		sellers[i] = otherOrder.sellers[i];
	}
}
Order::~Order() {
	for (int i = 0; i < this->numOfProducts; i++)
	{
		this->sellers[i] = nullptr;
	}
}

void Order::setBuyer(Buyer*& buyer) {
	this->buyer = buyer;
}

void Order::setNumOfProducts(ShoppingCart*& shoppingCart) {
	this->numOfProducts = shoppingCart->getShoppingCartLogSize();
}

void Order::setShoppingCart(ShoppingCart*& shoppingCart) {
	this->shoppingCart = shoppingCart;
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