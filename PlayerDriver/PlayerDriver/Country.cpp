#include "Country.h"
#include <string>

// Country Class functions

bool Country::isConquered()
{
	return 0;
}

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

std::string Country::getName() const
{
	return countryName;
}

void Country::setName(std::string newName)
{
	countryName = newName;
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
	*numberOfArmies = *armySet;
}
void Country::setCity(int* playerId) {
	city = playerId;
}

Country::Country()
{
	numberOfArmies = new int(0);
	continentNumber = new int(0);
	city = new int(-1);
}

Country::Country(int* countryNumber, int* continentNumber, int* positionedArmies)
	: countryNumber(countryNumber), continentNumber(continentNumber), numberOfArmies(positionedArmies)
{}

Country::~Country() {}
