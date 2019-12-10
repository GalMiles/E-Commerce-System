#include "Product.h"

int Product::productCounter = 0;

Product:: Product(char *productName,double price, Feedback *feedback)//c'tor
{
	cout << "in Product c'tor" << endl;

	productId = ++productCounter;

	int nameLength = strlen(productName);
	this->name = new char[nameLength + 1];
	strcpy(this->name, productName);

	this->price = price;
	
	this->feedback = feedback;

}

char* Product::getName()
{
	return m_name;
}

 double Product::getPrice()
{
	 return m_price;
}

int Product::getProductId()
{
	return m_productId;
}

/*
eCategory Product::getCategory()
{
	return m_category;
}
*/

