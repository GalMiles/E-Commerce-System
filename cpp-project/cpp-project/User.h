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
	enum eUserType { SELLER, BUYER };

	char *getUserName();
	void setUserName(char* name);
	void setPassword(char* password);
	void setAddress(Address* address);
	void setUserType(eUserType userType);
	Address* getAddress();
	eUserType getUserType();

	User(char* name, char* password, Address* address, eUserType userType);
	User(const User&) = delete;
	~User();

	void show() const;

private:
	char*		name;
	char*		password;
	Address		*address;
	eUserType	userType;
};

#endif