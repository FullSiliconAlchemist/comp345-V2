#include "pch.h"
#include "Country.h"
#include <string>

// Country Class functions

bool Country::isConquered() 
{
	return 0;
}

int Country::getNumberOfArmies() const 
{
	return numberOfArmies;
}

int Country::getContinentNumber() const 
{
	return continentNumber;
}

int Country::getCountryNumber() const
{
	return countryNumber;
}

std::string Country::getName() const
{
	return countryName;
}

void Country::setName(std::string &newName)
{
	countryName = newName;
}

Country::Country()
{
	numberOfArmies = 0;
	continentNumber = 0;
	countryNumber = 0;
	continentNumber = 0;
	countryName = "NO_NAME";
}

Country::Country(int countryNumber, int continentNumber, int positionedArmies)
	: countryNumber(countryNumber), continentNumber(continentNumber), numberOfArmies(positionedArmies) {}

Country::~Country() {}

