#include "Order.h"

Order::Order(ShoppingCart* shoppingCart, Buyer* buyer)
{
	setShoppingCart(shoppingCart);
	setBuyer(buyer);
	calculateTotalPrice();
	setOrderSellers();
	setPaymentStatus(false);
}

/*
Order::Order(const Order& otherOrder) {
	shoppingCart = new ShoppingCart(*otherOrder.shoppingCart);
	numOfProducts = *(new int(shoppingCart->getShoppingCartLogSize()));
	buyer = new Buyer(*otherOrder.buyer);
	calculateTotalPrice();
	this->sellers = otherOrder.sellers;
	paid = otherOrder.paid;
}*/


void Order::setBuyer(Buyer* buyer) {
	this->buyer = buyer;
}

Buyer* Order::getBuyer() {
	return this->buyer;
}

bool Order::isPaid() {
	return this->paid;
}

void Order::setPaymentStatus(bool paymentStatus) {
	this->paid = paymentStatus;
}

void Order::setShoppingCart(ShoppingCart* shoppingCart) {
	this->shoppingCart = new ShoppingCart(*shoppingCart);
}

ShoppingCart* Order::getOrderShoppingCart() {
	return this->shoppingCart;
}

void Order::setOrderSellers() {
	vector<Product*>::iterator itr = shoppingCart->getProducts().begin();
	vector<Product*>::iterator itrEnd = shoppingCart->getProducts().end();

	for ( ; itr != itrEnd; ++itr) {
		sellers.push_back((*itr)->getSeller());
	}
}

void Order::calculateTotalPrice()
{
	vector<Product*>::iterator itr = shoppingCart->getProducts().begin();
	vector<Product*>::iterator itrEnd = shoppingCart->getProducts().end();
	this->totalPrice = 0;
	for (; itr != itrEnd; ++itr) {
		this->totalPrice += (*itr)->getPrice();
	}
}

double Order::getTotalPrice() {
	return this->totalPrice;
}