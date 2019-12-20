#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "Menu.h"
#include "Address.h"
#include "Buyer.h"
#include "Seller.h"

const int MAX_LENGTH = 20;

class System
{
public:
	System();
	enum eUserType { SELLER, BUYER };
	const char STORE_NAME[8] = "AlmoGal";
	void initSystem();
	void sellerArrRealloc();
	void buyerArrRealloc();
	void addSellerToSellerArr(Seller *seller);
	void addBuyerToBuyerArr(Buyer *buyer);
	void performChoice(int choice);
	void addUser(eUserType userType);
	void addProductToSeller(Product *product);
	void addFeedbackToSeller(Feedback *feedback);

private:
	Menu theMenu;
	Seller **sellerArr;
	Buyer **buyerArr;
	int sellerArrLogSize;
	int sellerArrPhySize;
	int buyerArrLogSize;
	int buyerArrPhySize;
};

#endif