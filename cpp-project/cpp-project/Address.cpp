#include "Address.h"

Address::Address(char* country, char* city, char* street, int homeNumber) {
	cout << "In Address constructor\n";
	setCountry(country);
	setCity(city);
	setStreet(street);
	setHomeNumber(homeNumber);
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
	if (isAddressValid(country))
	{
		strcpy(country, country);
		return true;
	}
	else
		return false;
}

bool Address::setCity(char *city)
{
	if (isAddressValid(city))
	{
		strcpy(city, city);
		return true;
	}
	else
		return false;
}

bool Address::setStreet(char *street)
{
	if (isAddressValid(street))
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
	}
	return true;
}

void Address::show() const
{
	cout << "The address is:" << homeNumber << " " << street << "," << city << "," << country << endl;
}