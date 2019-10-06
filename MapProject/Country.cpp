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

// GETTER FOR TEST MEMBER VARIABLES
int * Country::getSomePointerVal() const
{
	return somePointer;
}

void Country::setPointerVal(int * newPointerVal)
{
	somePointer = newPointerVal;
}
// **********************************************

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
	countryName = "Name_not_initialized";
}

Country::Country(int countryNumber, int continentNumber, int positionedArmies)
	: countryNumber(countryNumber), continentNumber(continentNumber), numberOfArmies(positionedArmies) {}

// TEST CONSTRUCTOR FOR POINTER MEMBER
Country::Country(int * anotherPointer)
	: somePointer(anotherPointer)
{
}

Country::~Country() {}

