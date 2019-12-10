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

	char *getUserName();
	Address getAddress();
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
