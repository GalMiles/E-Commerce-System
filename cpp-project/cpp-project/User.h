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

	char *getUserName();
	void setUserName(char* name);
	void setPassword(char* password);
	void setAddress(Address* address);
	Address* getAddress();

	User(char* name, char* password, Address* address);
	User(const User& otherUser);
	~User();

	void show() const;

private:
	char*		name;
	char*		password;
	Address		*address;
};

#endif