#include "Product.h"
#include "Seller.h"

int Product::productCounter = 0;

Product::Product(char *productName, double price, eCategory category, Seller* productSeller) //c'tor
{
	cout << "in Product c'tor" << endl; //TODO: delete this
	productId = ++productCounter;

	name = new char[strlen(productName) + 1];
	setProductName(productName);
	setPrice(price);
	setCategory(category);
	setProductSeller(productSeller);
}

Product::Product(const Product& otherProduct) {
	name = *(new char*(otherProduct.name));
	price = *(new double(otherProduct.price));
	category = *(new eCategory(otherProduct.category));
	productId = *(new int(otherProduct.productId));
	productSeller = new Seller(*otherProduct.productSeller);
}

void Product::setProductName(char* productName) {
	strcpy(this->name, productName);
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