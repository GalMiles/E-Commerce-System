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

int Address::getZipCode()
{
	return m_zipCode;
}

/////////////////////////////////////////////////////////////
bool Address::setCountry(char *country)
{
	bool res;
	res = isValid(country);

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
	res = isValid(city);

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
	res = isValid(street);

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

void Address::setZipCode(int zipCode)
{
	m_zipCode = zipCode;
}



