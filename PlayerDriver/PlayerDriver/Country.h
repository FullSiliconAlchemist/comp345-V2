#pragma once
#include <string>

class Country {
	// note: defaulted to private
	int* numberOfArmies;
	int* arrOfPlayers[5];
	int* continentNumber;
	int* countryNumber;
	int* city;
	// Non pointer member variable cause f**k the police
	std::string countryName;

	// TEST VALUE
	int* somePointer;

public:
	bool isConquered(); // checks to see country object has been conquered and should say which player
	int* getNumberOfArmies() const;
	int* getContinentNumber() const;
	int* getCountryNumber() const;
	int* getCity() const;
	std::string getName() const;

	// TEST FUNCTION
	//int* getSomePointerVal() const;
	//void setPointerVal(int* newPointerVal);

	void setName(std::string newName);
	void setCountry(int* newCountry);
	void setContinent(int* newContinent);
	void setArmies(int* armySet);
	void setCity(int* playerId);

	Country();
	Country(int* countryNumber, int* continentNumber, int* positionedArmies);
	Country(int* countryNumber, int* continentNumber);
	~Country();
};