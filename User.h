#ifndef __USER_H
#define __USER_H

#include <iostream>
#include <string.h>
#include "Address.h"

using namespace std;

#pragma warning(disable: 4996)

class User
{
public:
	enum eUserType {SELLER, BUYER};

	bool setUserName(char *name);
	bool setPassword(char *password);
	bool setAdress(Address adress);
	bool setUserType(eUserType userType);

	char *getUserName();
	char *getPassword();
	Address getAdress();
	eUserType getUserType();

	User(char* name, char* password, Address* address, eUserType userType);
	//~User();

private:
	char*		name;
	char*		password;
	Address		*address;
	eUserType	userType;
};

#endif
