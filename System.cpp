#include "System.h"
#include <iostream>
#include <string.h>
using namespace std;

System::System(char *name)//c'tor
{
	int strLength = strlen(name);
	cout << "In System constructor\n";
	this->storeName = new char[strLength + 1];
	strcpy(this->storeName, name);

	this->buyerArr = new Buyer*[1];
	this->buyerArr[0] = nullptr;
	buyerArrPhySize = 1;
	buyerArrLogSize = 0;

	this->sellerArr = new Seller*[1];
	this->sellerArr[0] = nullptr;
	sellerArrPhySize = 1;
	sellerArrLogSize = 0;

}

System::~System() // d'tor
{
	cout << "In System d'tor\n";

	delete[] storeName;
	for (int i = 0; i < this->sellerArrPhySize; i++)
	{
		delete this->sellerArr[i];
	}

	for (int i = 0; i < this->buyerArrPhySize; i++)
	{
		delete this->buyerArr[i];
	}

}

void System::sellerArrRealloc()

{
	Seller **new_arr;
	this->sellerArrPhySize *= 2;
	new_arr = new Seller*[this->sellerArrPhySize];

	for (int i = 0; i < this->sellerArrLogSize; i++)
	{
		new_arr[i] = (this->sellerArr[i]);
		this->sellerArr[i] = nullptr;
	}
	delete[] this->sellerArr;

	this->sellerArr = new_arr;
}

void System::buyerArrRealloc()

{
	Buyer **new_arr;
	this->buyerArrPhySize *= 2;
	new_arr = new Buyer*[this->buyerArrPhySize];

	for (int i = 0; i < this->buyerArrLogSize; i++)
	{
		new_arr[i] = (this->buyerArr[i]);
		this->buyerArr[i] = nullptr;
	}
	delete[] this->buyerArr;

	this->buyerArr = new_arr;
}

void System::addSellerToArr(Seller* seller)
{
	if (this->sellerArrLogSize == this->sellerArrPhySize)
		sellerArrRealloc();

	sellerArr[this->sellerArrLogSize] = seller;
	(this->sellerArrLogSize)++;
}

void System::addBuyerToArr(Buyer* buyer)
{
	if (this->buyerArrLogSize == this->buyerArrPhySize)
		buyerArrRealloc();

	buyerArr[this->buyerArrLogSize] = buyer;
	(this->buyerArrLogSize)++;
}

void System::showSellerArr()
{
	for (int i = 0; i < sellerArrLogSize; i++)
	{
		sellerArr[i]->show();//using Seller's show method
	}
}

void System::showBuyerArr()
{
	for (int i = 0; i < buyerArrLogSize; i++)
	{
		buyerArr[i]->show();//using Seller's show method
	}
}

int System::getSellerArrLogSize() { return this->sellerArrLogSize; }

int System::getSellerArrPhySize() { return this->sellerArrPhySize; }

int System::getBuyerArrLogSize() { return this->buyerArrLogSize; }

int System::getBuyerArrPhySize() { return this->buyerArrPhySize; }

Seller** System::getSellerArr() { return this->sellerArr; }

Buyer** System::getBuyerArr() { return this->buyerArr; }















