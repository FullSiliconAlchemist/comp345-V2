#include "pch.h"
#include "Country.h"
#include <string>

// Country Class functions

bool Country::isConquered() 
{
	return 0;
}

int * Country::getContinentNumber() const
{
	return continentNumber;
}

int * Country::getCountryNumber() const
{
	return countryNumber;
}

std::string Country::getName() const
{
	return countryName;
}

void Country::setName(std::string newName)
{
	countryName = newName;
}

void Country::setCountry(int * newCountry)
{
	countryNumber = newCountry;
}

void Country::setContinent(int * newContinent)
{
	continentNumber = newContinent;
}

Country::Country()
{}

Country::Country(int * countryNumber, int * continentNumber)
	: countryNumber(countryNumber), continentNumber(continentNumber)
{}

Country::~Country() {}

