#include "Seller.h"
#include "User.h"
#include "Product.h"
#include "Feedback.h"


Seller::Seller(string& name, string& password, const Address& address) : User(name, password, address)
{

}

Seller::Seller(const Seller& otherSeller) : User(move(otherSeller))
{
	this->products = otherSeller.products;
	this->feedbackArr = otherSeller.feedbackArr;
}
Seller::Seller(ifstream& inFile) : User(inFile) {}


Seller::~Seller() {

}

void Seller::addProduct(Product &product) {
	this->products.push_back(&product);
}

void Seller::addFeedback(Feedback &feedback)
{
	this->feedbackArr.push_back(&feedback);
}

list<Product*>& Seller::getProducts() {
	return products;
}


const string Seller::getName()
{
	return(this->getUserName());
}

void Seller::toOs(ostream& os) const
{
	if (products.empty()) {
		cout << "The seller has no products" << endl;
	}
	else {
		list<Product*>::const_iterator itr = (products.begin());
		list<Product*>::const_iterator itrEnd = (products.end());
		os << "The Seller's products are:" << endl;
		for ( ; itr != itrEnd; ++itr)
		{
			os << **itr << endl;
		}
	}
}

