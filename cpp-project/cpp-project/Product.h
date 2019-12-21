#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class Seller;

class Product
{
public:
	enum eCategory { CHILDREN, CLOTHES, HOME, SPORT };
	static constexpr char* categories[] = { "Children", "Clothes", "Home", "Sport" };

	Product(char *productName, double price, eCategory category, Seller* productSeller); //c'tor
	Product(const Product& otherProduct);
	void setProductName(char* productName);
	void setPrice(double price);
	void setCategory(eCategory category);
	void setProductSeller(Seller* productSeller);
	char *getName();
	double getPrice();
	//eCategory getCategory();
	int getProductId();
	Seller* getSeller();
	void show();


private:
	static int productCounter;
	char *name;
	double price;
	eCategory category;
	int productId;
	Seller* productSeller;
};


#endif
