#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class Address
{
public:
	const int MAX_COUNTRY_LENGHT = 57;
	bool setCountry(char *country);
	bool setCity(char *city);
	bool setStreet(char *street);
	void setHomeNumber(int homeNumber);
	void setZipCode(int zipCode);

	char *getCountry();
	char *getCity();
	char *getStreet();
	int getHomeNumber();
	int getZipCode();

private:
	char*     m_country;
	char*     m_city;
	char*     m_street;
	int       m_homeNumber;
	int       m_zipCode;

};
#endif