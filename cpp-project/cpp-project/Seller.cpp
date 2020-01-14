#include "Seller.h"
#include "User.h"
#include "Product.h"
#include "Feedback.h"


Seller::Seller(char* name, char* password, Address* address) : User(name, password, address)
{
	this->productsLogSize = 0;
	this->productsPhySize = 1;
	this->products = new Product*[1];
	this->products[0] = nullptr;
	this->feedbackLogSize = 0;
	this->feedbackPhySize = 1;
	this->feedbackArr = new Feedback*[1];
	this->feedbackArr[0] = nullptr;
}

Seller::Seller(const Seller& otherSeller) : User(move(otherSeller))
{
	this->productsLogSize = 0;
	this->productsPhySize = 1;
	this->products = new Product*[1];
	this->products[0] = nullptr;
	for (int i = 0; i < otherSeller.productsLogSize; i++) {
		addProduct(*(new Product(*otherSeller.products[i])));
	}

	this->feedbackLogSize = 0;
	this->feedbackPhySize = 1;
	this->feedbackArr = new Feedback*[1];
	this->feedbackArr[0] = nullptr;
	for (int i = 0; i < otherSeller.feedbackLogSize; i++) {
		addFeedback(*(new Feedback(*otherSeller.feedbackArr[i])));
	}
}

Seller::~Seller() {
	for (int i = 0; i < productsPhySize; i++)
	{
		this->products[i] = nullptr;
	}
	delete[]products;

	for (int i = 0; i < feedbackPhySize; i++)
	{
		this->feedbackArr[i] = nullptr;
	}
	delete[]feedbackArr;
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
	this->show(); //using User's method

	cout << "The Seller's products are:" << endl;
	for (int i = 0; i < productsLogSize; i++)
	{
		cout << (products[i])->getName();
	}

}

void Seller::addProduct(Product &product) {
	if (this->productsLogSize == this->productsPhySize) //realloc arr
		this->productsArrRealloc();

	this->products[this->productsLogSize] = new Product(product); // add product
	(this->productsLogSize)++;
}

void Seller::addFeedback(Feedback &feedback)
{
	if (this->feedbackLogSize == this->feedbackPhySize)
		feedbackArrRealloc();

	feedbackArr[this->feedbackLogSize] = new Feedback(feedback);
	(this->feedbackLogSize)++;
}

Product** Seller::getProducts() {
	return this->products;
}

char* Seller::getName()
{
	return(this->getUserName());
}

int Seller::getProductsLogSize() {
	return (this->productsLogSize);
}

void Seller::toOs(ostream& os) const
{
	if (this->productsLogSize == 0) {
		cout << "The seller has no products" << endl;
	}
	else {
		os << "The Seller's products are:" << endl;
		for (int i = 0; i < productsLogSize; i++)
		{
			os << (products[i])->getName();
		}
	}
}
