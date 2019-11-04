#pragma once
#include <string>

class Country {
	// Unused member variables of shame
	// int* arrOfPlayers[5];
	// std::string countryName;

	// note: defaulted to private
	int* numberOfArmies;
	int* continentNumber;
	int* countryNumber;
	int* city;

public:	
	int* getNumberOfArmies() const;
	int* getContinentNumber() const;
	int* getCountryNumber() const;
	int* getCity() const;

	void setCountry(int* newCountry);
	void setContinent(int* newContinent);
	void setArmies(int* armySet); // Method accepts a heap-initialize object and stores reference
	void setCity(int* playerId);

	Country();
	Country(int* countryNumber, int* continentNumber);
	~Country();
};