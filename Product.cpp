#include "Product.h"

int Product::productCounter = 0;

Product:: Product(char *productName,double price, eCategory category, Seller* productSeller) //c'tor
{
	cout << "in Product c'tor" << endl; //TODO: delete this
	productId = ++productCounter;

	int nameLength = strlen(productName);
	this->name = new char[nameLength + 1];
	strcpy(this->name, productName);

	this->price = price;
	this->category = category;
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

