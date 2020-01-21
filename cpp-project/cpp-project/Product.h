/*
This class holds info about products
*/

#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class Seller;

const int NUM_OF_CATEGORIES = 4; //num of categories present in the system

class Product
{
public:
	enum eCategory { CHILDREN, CLOTHES, HOME, SPORT };
	static constexpr char* categories[] = { "Children", "Clothes", "Home", "Sport" }; //strings for the enum

	Product(string& productName, double price, eCategory category, Seller* productSeller); //c'tor
	//Product(const Product& otherProduct);//copy c'tor
	void setProductName(string& productName);
	void setPrice(double price);
	void setCategory(eCategory category);
	void setProductSeller(Seller* productSeller);
	const string getName();
	const double getPrice();
	const int getProductId();
	Seller* getSeller();
	void show(); //prints the product's info

	friend ostream& operator<<(ostream& os, const Product& product);

private:
	static int productCounter; //productId counter
	string name;
	double price;
	eCategory category;
	int productId;
	Seller* productSeller;
};


#endif
