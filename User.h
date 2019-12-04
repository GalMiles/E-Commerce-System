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

public:
	bool setUserName(char *name);
	bool setPassword(char *password);
	bool setAdress(Address adress);
	bool setUserType(eUserType userType);

	char *getUserName();
	char *getPassword();
	Address getAdress();
	eUserType getUserType();


private:
	char *     m_name;
	char *     m_password;
	Address    m_address;
	eUserType  m_userType;
};

#endif
