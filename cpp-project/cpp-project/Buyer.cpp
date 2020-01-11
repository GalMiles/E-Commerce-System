#include "Buyer.h"

Buyer::Buyer(char* name, char* password, Address* address, ShoppingCart *shoppingCart) : User(name, password, address)
{
	setShoppingCart(shoppingCart);
	this->sellerArr = new Seller*[1];
	this->sellerArr[0] = nullptr;
	this->sellerArrLogSize = 0;
	this->sellerArrPhySize = 1;
	this->orderArr = new Order*[1];
	this->orderArr[0] = nullptr;
	this->orderArrLogSize = 0;
	this->orderArrPhySize = 1;
}


Buyer::Buyer(const Buyer& otherBuyer) : User(move(otherBuyer))
{
	this->sellerArr = new Seller*[1];
	this->sellerArr[0] = nullptr;
	this->sellerArrLogSize = 0;
	this->sellerArrPhySize = 1;
	this->orderArr = new Order*[1];
	this->orderArr[0] = nullptr;
	this->orderArrLogSize = 0;
	this->orderArrPhySize = 1;
	for (int i = 0; i < otherBuyer.sellerArrLogSize; i++) {
		addSellerToBuyerArr(*(new Seller(*otherBuyer.sellerArr[i])));
	}
	shoppingCart = new ShoppingCart(*otherBuyer.shoppingCart);
}

Buyer::~Buyer()
{
	for (int i = 0; i < this->sellerArrPhySize; i++)
	{
		this->sellerArr[i] = nullptr;
	}
	delete[]sellerArr; 

	for (int i = 0; i < this->orderArrPhySize; i++)
	{
		this->orderArr[i] = nullptr;
	}
	delete[]orderArr;
}

void Buyer::setShoppingCart(ShoppingCart* shoppingCart) {
	this->shoppingCart = shoppingCart;
}

ShoppingCart* Buyer::getShoppingCart() {
	return this->shoppingCart;
}

void Buyer::show()
{
	//buyerUser->show();
}

void Buyer::sellerArrRealloc()
{
	Seller **new_arr;
	this->sellerArrPhySize *= 2;
	new_arr = new Seller*[this->sellerArrPhySize];

	for (int i = 0; i < this->sellerArrLogSize; i++)
	{
		new_arr[i] = (this->sellerArr[i]);
		this->sellerArr[i] = nullptr;
	}
	delete[] this->sellerArr;

	this->sellerArr = new_arr;
}

void Buyer::orderArrRealloc() {
	Order **new_arr;
	this->orderArrPhySize *= 2;
	new_arr = new Order*[this->orderArrPhySize];

	for (int i = 0; i < this->orderArrLogSize; i++)
	{
		new_arr[i] = (this->orderArr[i]);
		this->orderArr[i] = nullptr;
	}
	delete[] this->orderArr;

	this->orderArr = new_arr;
}

void Buyer::addSellerToBuyerArr(Seller &seller)
{
	if (this->sellerArrLogSize == this->sellerArrPhySize) //realloc arr
		sellerArrRealloc();

	sellerArr[this->sellerArrLogSize] = new Seller(seller);
	(this->sellerArrLogSize)++;
}

void Buyer::addOrderToOrderArr(Order &order)
{
	if (this->orderArrLogSize == this->orderArrPhySize) //realloc arr
		orderArrRealloc();

	orderArr[this->orderArrLogSize] = new Order(order);
	(this->orderArrLogSize)++;
}

//User *Buyer::getUser() { return this->buyerUser; }


char* Buyer::getName()
{
	return(this->getUserName());
}

int Buyer::getSellerArrLogSize() { return sellerArrLogSize; }

int Buyer::getOrderArrLogSize() { return orderArrLogSize; }

Seller** Buyer::getSellerArr() { return sellerArr; }

Order** Buyer::getOrderArr() { return orderArr; }

bool Buyer::operator>(const Buyer& other) const {
	return ((this->shoppingCart->getTotalPrice()) > (other.shoppingCart->getTotalPrice()));
}