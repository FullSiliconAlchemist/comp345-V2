#pragma once
#include "Cards.h"
#include "BiddingFacility.h"
#include "Country.h"
#include "vector"
class Player
{
public:

	bool payCoin(int amountToPay);
	bool PlaceNewArmies(int numOfArmies, Country *countryToPlace); // Must accept a region on a map as a passed parameter to place armies (Map object)
	int MoveArmies(int numOfMovements,int numToMove, Country *countryToTake, Country *countryToPlace); // Must accept a region on a map as a passed parameter to move armies
	void MoveOverLand(int numToMove, Country *countryToTake, Country *countryToPlace); // Will probably be implemented within MoveArmies function
	void BuildCity(Country *c);
	bool DestroyArmy(int numOfArmies, Country *c);
	void destroyArmymoveArmy(int numOfArmies, Country* c, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToPlace);
	void newArmymoveArmy(int numOfArmies, Country* countryToPlace, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToMoveTo);
	void citymoveArmy(Country* c, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToPlace);
	void ignore();

	void bid();
	void receiveGoldenCoins(int numOfCoins);

	inline int GetArmyCubes() const { return *armyCubes; }	// Inline functions are defined in the header files
	inline int GetCityDiscs() const { return *cityDiscs; }
	inline int GetGoldenCoins() const { return *goldenCoins; }
	inline void setGoldenCoins(int numOfCoins) { goldenCoins = new int(numOfCoins);}
	inline int GetId() const { return *id; }
	int nextPlayerTurn(int currentTurn, int maxNumOfPlayers);
	void pickUpCard(Card c);
	Player(); // For now default constructor is fine
	~Player(); // I think this be a destroyer method
private:

	int *armyCubes;
	int *cityDiscs;
	static int currentId;
	int* id;
	// 8 Coins if playing with 5 players, 9 if 4 players, 11 with 3 players and 14 with 2
	int *goldenCoins;

	// Missing a set of 42 Cards Objects 
	//Card playerHand[20];
	std::vector<Card> playerHand;
	BiddingFacility bidding;
	// Missing a biding Object
	
};