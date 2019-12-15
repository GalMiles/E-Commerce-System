#include "Buyer.h"

Buyer::Buyer(User *userBuyer, ShoppingCart *shoppingCart)
{
	cout << "In Buyer constructor\n";
	this->buyerUser = userBuyer;
	this->shoppingCart = *shoppingCart;
	this->sellerArr = new Seller*[1];
	this->sellerArrLogSize = 0;
	this->sellerArrPhySize = 0;

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

void Buyer::addSellerToBuyerArr(Seller *seller)
{
	if (this->sellerArrLogSize == this->sellerArrPhySize) //realloc arr
		sellerArrRealloc();

	sellerArr[this->sellerArrLogSize] = seller; // add product
	(this->sellerArrLogSize)++;
}



