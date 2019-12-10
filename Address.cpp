#include "Address.h"

Address::Address(char* country, char* city, char* street, int homeNumber) {
	cout << "In Address constructor\n";
	strcpy(this->country, country);
	strcpy(this->city, city);
	strcpy(this->street, street);
	this->homeNumber = homeNumber;
}

char* Address::getCountry()
{
	return country;
}

char* Address::getCity()
{
	return city;
}

char* Address::getStreet()
{
	return street;
}

int Address::getHomeNumber()
{
	return homeNumber;
}

bool Address::setCountry(char *country)
{
	bool res;
	res = isAddressValid(country);

	if (res)
	{
		strcpy(country, country);
		return true;
	}
	else
		return false;
}

bool Address::setCity(char *city)
{
	bool res;
	res = isAddressValid(city);

	if (res)
	{
		strcpy(city, city);
		return true;
	}
	else
		return false;
}

bool Address::setStreet(char *street)
{
	bool res;
	res = isAddressValid(street);

	if (res)
	{
		strcpy(street, street);
		return true;
	}
	else
		return false;
}

void Address::setHomeNumber(int homeNumber)
{
	homeNumber = homeNumber;
}

bool Address::isAddressValid(char* address) {
	int length = strlen(address);
	for (int i = 0; i < length; i++) {
		if ((address[i] < 'A' || (address[i] > 'Z' && address[i] < 'a') || address[i] > 'z'))
			return false;
		else
			return true;
	}
}