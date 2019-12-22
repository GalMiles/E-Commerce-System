#include "Product.h"
#include "Seller.h"

int Product::productCounter = 0; //initialize the productId counter

Product::Product(char *productName, double price, eCategory category, Seller* productSeller) //c'tor
{
	productId = ++productCounter;

	name = new char[strlen(productName) + 1];
	setProductName(productName);
	setPrice(price);
	setCategory(category);
	setProductSeller(productSeller);
}

Product::Product(const Product& otherProduct) {
	name = new char[strlen(otherProduct.name) + 1];
	//name = *(new char*(otherProduct.name));
	strcpy(name, otherProduct.name);
	price = *(new double(otherProduct.price));
	category = *(new eCategory(otherProduct.category));
	productId = *(new int(otherProduct.productId));
	productSeller = new Seller(*otherProduct.productSeller);
}

Product::~Product() {
	delete this->name;
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


Seller* Product::getSeller() {
	return this->productSeller;
}

void Product::show() {
	cout << "* Product ID: " << this->getProductId() << endl;
	cout << "* Product Name: " << this->getName() << endl;
	cout << "* Proudct Price: " << this->getPrice() << endl;
	cout << "* Sold By: " << this->getSeller()->getName() << endl;
}