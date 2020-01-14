/*
This class holds general user info (address, password, user name - info which is required for any user - buyer or seller)
*/

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

	User(char* name, char* password, Address* address); //c'tor
	User(const User& otherUser); //copy c'tor
	virtual ~User();

	void show() const; //print user's info

	friend ostream& operator<<(ostream& os, const User& user);
	virtual void toOs(ostream& os) const = 0;


private:
	char*		name;
	char*		password;
	Address		*address;
};

#endif