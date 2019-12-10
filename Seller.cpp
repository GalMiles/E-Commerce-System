#include "Seller.h"
#include "User.h"


Seller::Seller(User *sellerUser)//c'tor
{
	cout << "In seller constructor" << endl;
	this->sellerUser = sellerUser;
}


Product* Seller::productRealloc(Product **products, int logSize, int *phySize)
{
	Product **new_arr;
	*phySize = (*phySize) * 2;
	new_arr = new Product *[*phySize];

	for (int i = 0; i < logSize; i++)
	{
		new_arr[i] = (products[i]);
		products[i] = nullptr;
	}
	delete[] products;

	return *(new_arr);
}

void Seller::addProduct(Product **products, int *logSize, int *phySize, Product *product)
{
	if (*logSize == *phySize) //realloc arr
	{
		*products = productRealloc(products, *logSize, phySize);
	}

	products[*logSize] = product; // add product
	(*logSize)++;

}