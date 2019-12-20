#include "Product.h"

int Product::productCounter = 0;

Product::Product(char *productName, double price, eCategory category, Seller* productSeller) //c'tor
{
	cout << "in Product c'tor" << endl; //TODO: delete this
	productId = ++productCounter;

	this->name = new char[strlen(productName) + 1];
	setProductName(name);
	setPrice(price);
	setCategory(category);
	setProductSeller(productSeller);
}

void Product::setProductName(char* productName) {
	strcpy(this->name, productName);
}

void Product::setPrice(double price) {
	this->price = price;
}

void Product::setCategory(eCategory category) {
	this->price = price;
}

void Product::setProductSeller(Seller* productSeller) {
	this->productSeller = productSeller;
}

char* Product::getName()
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

/*
eCategory Product::getCategory()
{
return m_category;
}
*/

Seller* Product::getSeller() {
	return this->productSeller;
}