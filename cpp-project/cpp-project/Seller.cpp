#include "Seller.h"
#include "User.h"
#include "Product.h"
#include "Feedback.h"


Seller::Seller(User *sellerUser)//c'tor
{
	cout << "In seller constructor" << endl; //TODO: delete this
	this->sellerUser = sellerUser;
	this->productsLogSize = 0;
	this->productsPhySize = 1;
	this->products = new Product*[1];
}

Seller::Seller(const Seller& otherSeller) {
	for (int i = 0; i < otherSeller.productsLogSize; i++) {
		addProduct(new Product(*otherSeller.products[i]));
	}
	for (int i = 0; i < otherSeller.feedbackLogSize; i++) {
		addFeedback(new Feedback(*otherSeller.feedbackArr[i]));
	}
	sellerUser = new User(*otherSeller.sellerUser);
}

void Seller::productsArrRealloc()
{
	Product **new_arr;
	this->productsPhySize *= 2;
	new_arr = new Product*[this->productsPhySize];

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

void Seller::show() const
{
	sellerUser->show(); //using User's method

	cout << "The Seller's products are:" << endl;
	for (int i = 0; i < productsLogSize; i++)
	{
		cout << (products[i])->getName();
	}

}

void Seller::addProduct(Product *product) {
	if (this->productsLogSize == this->productsPhySize) //realloc arr
		this->productsArrRealloc();

	this->products[this->productsLogSize] = product; // add product
	(this->productsLogSize)++;
}

void Seller::addFeedback(Feedback *feedback)
{
	if (this->feedbackLogSize == this->feedbackPhySize)
		feedbackArrRealloc();

	feedbackArr[this->feedbackLogSize] = feedback;
	(this->feedbackLogSize)++;
}

Product** Seller::getProducts() {
	return this->products;
}

char* Seller::getName()
{
	return(this->sellerUser->getUserName());
}