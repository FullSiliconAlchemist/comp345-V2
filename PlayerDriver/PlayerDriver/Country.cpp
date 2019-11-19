#include "Country.h"
#include <string>
#include <iostream>

// Country Class functions

int* Country::getCity() const
{
	return city;
}

int** Country::getRefactoredArmies() const
{
	return refactoredArmies;
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

void Country::setCity(int* playerId) {
	city = playerId;
}

void Country::setRefactoredArmies(int playerID, int* armiesToSet)
{
	refactoredArmies[playerID] = armiesToSet;
}

Country::Country()
{
	countryNumber = new int(0);
	continentNumber = new int(0);
	city = new int(0);

	// Setting all armies in all countries to 0
	refactoredArmies = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		refactoredArmies[i] = new int(0);
	}
}

Country::Country(int* countryNumber, int* continentNumber)
	: countryNumber(countryNumber), continentNumber(continentNumber)
{
	city = new int(0);

	// Setting all armies in all countries to 0
	refactoredArmies = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		refactoredArmies[i] = new int(0);
	}
}

Country::~Country()
{
}


