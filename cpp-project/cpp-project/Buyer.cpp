#include "Buyer.h"

Buyer::Buyer(User *userBuyer) : shoppingCart()
{
	setUser(userBuyer);
	this->sellerArr = new Seller*[1];
	this->sellerArr[0] = nullptr;
	this->sellerArrLogSize = 0;
	this->sellerArrPhySize = 1;
}


Buyer::Buyer(const Buyer& otherBuyer) {
	buyerUser = new User(*otherBuyer.buyerUser);
	for (int i = 0; i < otherBuyer.sellerArrLogSize; i++) {
		addSellerToBuyerArr(*(new Seller(*otherBuyer.sellerArr[i])));
	}
	shoppingCart = *(new ShoppingCart(otherBuyer.shoppingCart));
}

Buyer::~Buyer()
{
	for (int i = 0; i < this->sellerArrPhySize; i++)
	{
		this->sellerArr[i] = nullptr;
	}
	//delete[]sellerArr;
}

void Buyer::setUser(User* user) {
	this->buyerUser = user;
}

ShoppingCart Buyer::getShoppingCart() {
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

void Buyer::addSellerToBuyerArr(Seller &seller)
{
	if (this->sellerArrLogSize == this->sellerArrPhySize) //realloc arr
		sellerArrRealloc();

	sellerArr[this->sellerArrLogSize] = new Seller(seller);
	(this->sellerArrLogSize)++;
}

User *Buyer::getUser() { return this->buyerUser; }

char* Buyer::getName()
{
	return(this->buyerUser->getUserName());
}

int Buyer::getSellerArrLogSize() { return sellerArrLogSize; }

Seller** Buyer::getSellerArr() { return sellerArr; }