#include "Country.h"
#include <string>

// Country Class functions

int* Country::getNumberOfArmies() const
{
	return numberOfArmies;
}
int* Country::getCity() const
{
	return city;
}

int* Country::getContinentNumber() const
{
	return continentNumber;
}

int* Country::getCountryNumber() const
{
	return countryNumber;
}

void Country::setCountry(int* newCountry)
{
	countryNumber = newCountry;
}

void Country::setContinent(int* newContinent)
{
	continentNumber = newContinent;
}

void Country::setArmies(int* armySet)
{
	numberOfArmies = armySet;
}

void Country::setCity(int* playerId) {
	city = playerId;
}

Country::Country()
{
	numberOfArmies = new int(0);
	countryNumber = new int(0);
	continentNumber = new int(0);
	city = new int(-1);
}

Country::Country(int* countryNumber, int* continentNumber)
	: countryNumber(countryNumber), continentNumber(continentNumber)
{
	numberOfArmies = new int(0);
	city = new int(0);
}

Country::~Country()
{
	//delete numberOfArmies; // Only member variable which should point to an object in the heap besides city
}


