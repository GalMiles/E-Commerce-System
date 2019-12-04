#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

#include "Feedback.h"


class Product
{

public:
	enum eCategory {CHILDREN, CLOTHES, HOME, SPORT};

	void setName(char *name);
	bool setPrice(double price);
	void setCategory(eCategory category);

	char *getName();
	double getPrice();
	//eCategory getCategory();
	int getProductId();
	
private:
	void setProductId(int ProductId);

	char     *m_name;
	double    m_price;
	eCategory m_category;
	int       m_productId;
	Feedback  *m_feedback;
};

#endif