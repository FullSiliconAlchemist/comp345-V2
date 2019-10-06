#pragma once
#include <string>

class Country {
	// note: defaulted to private
	int numberOfArmies;
	int arrOfPlayers[5];
	int continentNumber;
	int countryNumber;
	std::string countryName;

	// TEST VALUE
	int * somePointer;

public:
	bool isConquered(); // checks to see country object has been conquered and should say which player
	int getNumberOfArmies() const;
	int getContinentNumber() const;
	int getCountryNumber() const;
	std::string getName() const;

	// TEST FUNCTION
	int * getSomePointerVal() const;
	void setPointerVal(int * newPointerVal);

	void setName(std::string &newName);

	Country();
	Country(int countryNumber, int continentNumber, int positionedArmies);
	Country(int * anotherPointer);
	~Country();
};
