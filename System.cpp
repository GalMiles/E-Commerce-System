#include "System.h"

System::System(char *name)//c'tor
{
	int strLength = strlen(name);
	cout << "In System constructor\n";
	this->storeName = new char[strLength + 1];
	strcpy(this->storeName, name);

	this->buyerArr = new Buyer*[1];
	sellerArrPhySize = 1;
	sellerArrLogSize = 0;

	this->sellerArr = new Seller*[1];
	buyerArrPhySize = 1;
	sellerArrLogSize = 0;

}

System::~System() // d'tor
{
	cout << "In System d'tor\n";

	delete[] storeName;
	for (int i = 0; i < sellerArrLogSize; i++)
	{
		delete sellerArr[i];
	}

	for (int i = 0; i < buyerArrLogSize; i++)
	{
		delete buyerArr[i];
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





