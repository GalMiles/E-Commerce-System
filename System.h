#ifndef _SYSTEM_H
#define __SYSTEM_H

#include "Seller.h"
#include "Buyer.h"
class System
{
public:
	System(char *name);//c'tor
	System(System& other) = delete;
	~System();//d'tor

	void sellerArrRealloc();
	void buyerArrRealloc();
	void addSellerToArr(Seller* s);
	void addBuyerToArr(Buyer* buyer);

	void showSellerArr();
	void showBuyerArr();

private:
	char *storeName;
	Seller **sellerArr;
	int sellerArrLogSize;
	int sellerArrPhySize;
	Buyer **buyerArr;
	int buyerArrLogSize;
	int buyerArrPhySize;

};

#endif
