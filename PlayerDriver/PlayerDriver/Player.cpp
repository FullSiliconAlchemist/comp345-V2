#include "Player.h"

void Player::payCoin(int amountToPay) {
	*goldenCoins -= amountToPay;
}
void Player::receiveGoldenCoins(int numOfCoins) {
	*goldenCoins += numOfCoins;
}
void Player::bid() {
	bidding.placeBidAndAge();
}
bool Player::PlaceNewArmies(int numOfArmies, Country *countryToPlace) {
	if (numOfArmies > * armyCubes) {
		return false;
	}
	int* ptToNewNumOfArmies = new int(numOfArmies + *countryToPlace->getNumberOfArmies());
	countryToPlace->setArmies(ptToNewNumOfArmies);
	return true;
}

int Player::MoveArmies(int numOfMovements, int numToMove, Country *countryToTake, Country *countryToPlace) { // returns movements left 
	if (numToMove > *countryToTake->getNumberOfArmies()) { 
		return numOfMovements; 
	}
	if (*countryToTake->getContinentNumber() == *countryToPlace->getContinentNumber()) {
	
		MoveOverLand(numToMove, countryToTake, countryToPlace); 
		return numOfMovements-1;
	}

	int* ptToNewNumOfArmies = new int(*countryToTake->getNumberOfArmies() - numToMove);
	countryToTake->setArmies(ptToNewNumOfArmies);

	ptToNewNumOfArmies = new int(numToMove + *countryToPlace->getNumberOfArmies());
	countryToPlace->setArmies(ptToNewNumOfArmies);

	return numOfMovements - 3; //assumed they lost 3 movements for moving over water
}
/**/
void Player::MoveOverLand(int numToMove, Country *countryToTake, Country *countryToPlace) {
	int *ptToNewNumOfArmies = new int(*countryToTake->getNumberOfArmies() - numToMove);
	countryToTake->setArmies(ptToNewNumOfArmies);

	ptToNewNumOfArmies = new int(numToMove + *countryToPlace->getNumberOfArmies());
	countryToPlace->setArmies(ptToNewNumOfArmies);
	return;
}

void Player::BuildCity(Country *c) {
	c->setCity(id);
	return;
}

bool Player::DestroyArmy(int numOfArmies, Country *c) {
	if (numOfArmies > numOfArmies) {
		return false;
	}
	int* ptToNewNumOfArmies = new int(*c->getNumberOfArmies() - numOfArmies);
	c->setArmies(ptToNewNumOfArmies);
	return true;
}
int Player::currentId = 0;
Player::Player()
{
	armyCubes = new int(14);
	cityDiscs = new int(3);
	goldenCoins = new int(20);
	id = new int(currentId);
	currentId++;
}
Player::~Player()
{
}

//inline int Player::GetGoldenCoins() const {
//}
//
//inline int Player::GetArmyCubes() const {
//	
//}
//
//inline int Player::GetCityDiscs() const {
//	
//}