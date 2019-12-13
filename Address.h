#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class Address
{
public:
	Address(char* country, char* city, char* street, int homeNumber);
	const int MAX_COUNTRY_LENGTH = 57;
	bool setCountry(char *country);
	bool setCity(char *city);
	bool setStreet(char *street);
	void setHomeNumber(int homeNumber);

	char *getCountry();
	char *getCity();
	char *getStreet();
	int getHomeNumber();

	bool isAddressValid(char* address);

private:
	//TODO: add length constraint as const
	char	country[50];
	char	city[50];
	char	street[50];
	int		homeNumber;
};
#endif