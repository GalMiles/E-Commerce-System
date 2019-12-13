#include "Seller.h"
#include "User.h"


Seller::Seller(User *sellerUser)//c'tor
{
	cout << "In seller constructor" << endl; //TODO: delete this
	this->sellerUser = sellerUser;
	this->productsLogSize = 0;
	this->productsPhysSize = 1;
	this->products = new Product*[1];
}

void Seller::productsArrRealloc()
{
	Product **new_arr;
	this->productsPhysSize *= 2;
	new_arr = new Product*[this->productsPhysSize];

	for (int i = 0; i < this->productsLogSize; i++)
	{
		new_arr[i] = (this->products[i]);
		this->products[i] = nullptr;
	}
	delete[] this->products;

	this->products = new_arr;
}

void Seller::addProductToSeller(Product *product)
{
	if (this->productsLogSize == this->productsPhysSize) //realloc arr
		productsArrRealloc();

	products[this->productsLogSize] = product; // add product
	(this->productsLogSize)++;
}