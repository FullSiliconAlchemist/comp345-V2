#pragma once
#include <string>

class Country {
	// Unused member variables of shame
	// std::string countryName;

	// Each army has to be identified by the player ID
	// Since player ID is just an integer from 1 to 5 depending on the amount of players

	// note: defaulted to private
	int** refactoredArmies;
	int* numberOfArmies;
	int* continentNumber;
	int* countryNumber;
	int* city;

	// int* arrOfPlayers[5];

public:	
	int* getNumberOfArmies() const;
	int* getContinentNumber() const;
	int* getCountryNumber() const;
	int* getCity() const;

	int** getRefactoredArmies() const;

	void setCountry(int* newCountry);
	void setContinent(int* newContinent);
	void setArmies(int* armySet); // Method accepts a heap-initialize object and stores reference
	void setCity(int* playerId);

	void setRefactoredArmies(int playerID, int* armiesToSet);

	Country();
	Country(int* countryNumber, int* continentNumber);
	~Country();
};