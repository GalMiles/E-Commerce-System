#include "Product.h"
#include "Seller.h"

int Product::productCounter = 0; //initialize the productId counter

Product::Product(string productName, double price, eCategory category, Seller* productSeller) //c'tor
{
	productId = ++productCounter;

	setProductName(productName);
	setPrice(price);
	setCategory(category);
	setProductSeller(productSeller);
}

Product::Product(const Product& otherProduct) {
	name = otherProduct.name;
	price = otherProduct.price;
	category = eCategory(otherProduct.category);
	productId = otherProduct.productId;
	productSeller = new Seller(*otherProduct.productSeller);
}

void Product::setProductName(string productName) {
	this->name = productName;
}

void Product::setPrice(double price) {
	this->price = price;
}

void Product::setCategory(eCategory category) {
	this->category = category;
}

void Product::setProductSeller(Seller* productSeller) {
	this->productSeller = productSeller;
}

string Product::getName()
{
	return name;
}

double Product::getPrice()
{
	return price;
}

int Product::getProductId()
{
	return productId;
}


Seller* Product::getSeller() {
	return this->productSeller;
}

void Product::show() {
	cout << "* Product ID: " << this->getProductId() << endl;
	cout << "* Product Name: " << this->getName() << endl;
	cout << "* Proudct Price: " << this->getPrice() << endl;
	cout << "* Sold By: " << this->getSeller()->getName() << endl;
}

ostream& operator<<(ostream& os, const Product& product)
{
	os << "* Product ID: " <<product.productId << endl;
	os << "* Product Name: " << product.name << endl;
	os << "* Proudct Price: " << product.price << endl;
	return os;
}
