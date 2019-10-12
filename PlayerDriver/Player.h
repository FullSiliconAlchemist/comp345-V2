#pragma once
class Player
{
public:

	void PayCoin();
	void PlaceNewArmies(); // Must accept a region on a map as a passed parameter to place armies (Map object)
	void MoveArmies(); // Must accept a region on a map as a passed parameter to move armies
	void MoveOverLand(); // Will probably be implemented within MoveArmies function
	void BuildCity();
	void DestroyArmy();

	inline int GetArmyCubes() const { return armyCubes; }	// Inline functions are defined in the header files
	inline int GetCityDiscs() const { return cityDiscs; }
	inline int GetGoldenCoins() const { return goldenCoins; }

	Player(); // For now default constructor is fine
	~Player(); // I think this be a destroyer method
private:

	int armyCubes;
	int cityDiscs;

	// 8 Coins if playing with 5 players, 9 if 4 players, 11 with 3 players and 14 with 2
	int goldenCoins;

	// Missing a set of 42 Cards Objects 
	int cards;
	
	// Missing a biding Object
	int bidingObject;

};


