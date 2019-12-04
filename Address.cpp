#include "Address.h"

char* Address::getCountry()
{
	return m_country;
}

char* Address::getCity()
{
	return m_city;
}

char* Address::getStreet()
{
	return m_street;
}

int Address::getHomeNumber()
{
	return m_homeNumber;
}

/////////////////////////////////////////////////////////////
bool Address::setCountry(char *country)
{
	bool res;
	res = isAddressValid(country);

	if (res)
	{
		strcpy(m_country, country);
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
		strcpy(m_city, city);
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
		strcpy(m_street, street);
		return true;
	}
	else
		return false;
}

void Address::setHomeNumber(int homeNumber)
{
	m_homeNumber = homeNumber;
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