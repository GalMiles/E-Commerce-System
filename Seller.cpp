#include "Seller.h"
#include "User.h"
#include "Product.h"


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

void Seller::feedbackArrRealloc()
{
	Feedback **new_arr;
	this->feedbackPhySize *= 2;
	new_arr = new Feedback*[this->feedbackPhySize];

	for (int i = 0; this->feedbackLogSize; i++)
	{
		new_arr[i] = (this->feedbackArr[i]);
		this->feedbackArr[i] = nullptr;
	}
	delete[] this->feedbackArr;

	this->feedbackArr = new_arr;
}

void Seller::addProductToSeller(Product *product)
{
	if (this->productsLogSize == this->productsPhysSize) //realloc arr
		productsArrRealloc();

	products[this->productsLogSize] = product; // add product
	(this->productsLogSize)++;
}

void Seller::show() const
{
	sellerUser->show(); //using User's method

	cout << "The Seller's products are:" << endl;
	for (int i = 0; i < productsLogSize; i++)
	{
		cout << (products[i])->getName();
	}

}

Product** Seller::getProducts() {
	return this->products;
}

void Seller::addFeedbaclToSeller(Feedback *feedback)
{
	if (this->feedbackLogSize == this->feedbackPhySize)
		feedbackArrRealloc();

	feedbackArr[this->feedbackLogSize] = feedback;
	(this->feedbackLogSize)++;

}

char* Seller::getName()
{
	return(this->sellerUser->getUserName());
}
