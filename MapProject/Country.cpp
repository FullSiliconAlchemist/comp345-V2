#include "pch.h"
#include "Country.h"
#include <string>

// Country Class functions

bool Country::isConquered() {
	return 0;
}

int Country::getNumberOfArmies() const {
	return numberOfArmies;
}

int Country::getContinent() const {
	return continent;
}

Country::Country()
{
	numberOfArmies = 0;
	continent = 0;
	countryName = "NONE";
}

Country::Country(int positionedArmies, int countryContinent)
	: numberOfArmies(positionedArmies), continent(countryContinent) {}

Country::~Country() {}

