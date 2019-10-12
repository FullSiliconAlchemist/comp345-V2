#pragma once
#include <string>

class Country {
	// note: defaulted to private
	int * continentNumber;
	int * countryNumber;

	// Non pointer member variable cause f**k the police
	std::string countryName;

public:
	bool isConquered(); // checks to see country object has been conquered and should say which player
	int * getContinentNumber() const;
	int * getCountryNumber() const;
	std::string getName() const;

	void setName(std::string newName);
	void setCountry(int * newCountry);
	void setContinent(int * newContinent);

	Country();
	Country(int * countryNumber, int * continentNumber);
	~Country();
};
