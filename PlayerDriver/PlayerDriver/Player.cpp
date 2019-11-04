#include "Player.h"

bool Player::payCoin(int amountToPay) {
	if (*goldenCoins - amountToPay < 0) {
		return false;
	}
	*goldenCoins -= amountToPay;
	return true;
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
	int* _ptToNewNumOfArmies = new int(numOfArmies + *countryToPlace->getRefactoredArmies()[this->GetId()]); // New version
	countryToPlace->setArmies(ptToNewNumOfArmies);
	countryToPlace->setRefactoredArmies(this->GetId(), _ptToNewNumOfArmies); // New version
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
int Player::nextPlayerTurn(int currentTurn, int maxNumOfPlayers) {
	if (currentTurn + 1 == maxNumOfPlayers) {
		return 0;
	}
	return currentTurn + 1;
}
void Player::pickUpCard(Card c) {
	playerHand.push_back(c);
}

bool Player::DestroyArmy(int numOfArmies, Country *c) {
	if (numOfArmies > numOfArmies) {
		return false;
	}
	int* ptToNewNumOfArmies = new int(*c->getNumberOfArmies() - numOfArmies);
	c->setArmies(ptToNewNumOfArmies);
	return true;
}
void Player::destroyArmymoveArmy(int numOfArmies, Country* c, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToPlace) {
	DestroyArmy(numOfArmies, c);
	MoveArmies(numOfMovements,numToMove, countryToTake, countryToPlace);
}
void Player::newArmymoveArmy(int numOfArmies, Country* countryToPlace, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToMoveTo) {
	PlaceNewArmies(numOfArmies,countryToPlace);
	MoveArmies(numOfMovements, numToMove, countryToTake, countryToMoveTo);
}
void Player::citymoveArmy(Country* c, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToPlace) {
	BuildCity(c);
	MoveArmies(numOfMovements, numToMove, countryToTake, countryToPlace);
}
void Player::ignore() {
	//do nothing
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