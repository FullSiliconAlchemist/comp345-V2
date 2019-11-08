#include "Country.h"
#include <string>
#include <iostream>

// Country Class functions

int* Country::getNumberOfArmies() const
{
	return numberOfArmies;
}
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

void Country::setArmies(int* armySet)
{
	numberOfArmies = armySet;
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
	numberOfArmies = new int(0);
	countryNumber = new int(0);
	continentNumber = new int(0);
	city = new int(-1);

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
	numberOfArmies = new int(0);
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
	/*delete this->city;
	this->city = NULL;
	delete this->continentNumber;
	this->continentNumber = NULL;
	delete this->countryNumber;
	this->countryNumber = NULL;
	delete this->numberOfArmies;
	this->numberOfArmies = NULL;
	delete this->refactoredArmies;
	this->refactoredArmies = NULL;*/
}


