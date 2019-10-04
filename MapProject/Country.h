#pragma once
#include <string>

class Country {
	int numberOfArmies;
	int arrOfPlayers[5];
	int continent;
	std::string countryName;

public:
	bool isConquered(); // checks to see country object has been conquered and should say which player
	int getNumberOfArmies() const;
	int getContinent() const;

	Country();
	Country(int positionedArmies, int countryContinent);
	~Country();
};
