#include "Player.h"
#include <string>
#include <iostream>
//#include "Map.h"

using std::cin;
using std::cout;
using std::string;

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
void Player::bid(int age, int bid) {
	bidding.placeBidAndAge(age, bid);
}
bool Player::PlaceNewArmies(int numOfArmies, Country *countryToPlace) {
	if (numOfArmies > * armyCubes) {
		return false;
	}
	/*int* ptToNewNumOfArmies = new int(numOfArmies + *countryToPlace->getNumberOfArmies());*/
	int* _ptToNewNumOfArmies = new int(numOfArmies + *countryToPlace->getRefactoredArmies()[this->GetId()]); // New version
	/*countryToPlace->setArmies(ptToNewNumOfArmies);*/
	countryToPlace->setRefactoredArmies(this->GetId(), _ptToNewNumOfArmies); // New version
	return true;
}

int Player::MoveArmies(int numOfMovements, int numToMove, Country *countryToTake, Country *countryToPlace) { // returns movements left 
	if (numToMove > *countryToTake->getRefactoredArmies()[this->GetId()]) { 
		return numOfMovements; 
	}
	if (*countryToTake->getContinentNumber() == *countryToPlace->getContinentNumber()) {
	
		MoveOverLand(numToMove, countryToTake, countryToPlace);
		return numOfMovements-1;
	}

	int* ptToNewNumOfArmies = new int(*countryToTake->getRefactoredArmies()[this->GetId()] - numToMove);
	countryToTake->setRefactoredArmies(this->GetId(), ptToNewNumOfArmies);

	ptToNewNumOfArmies = new int(numToMove + *countryToPlace->getRefactoredArmies()[this->GetId()]);
	countryToPlace->setRefactoredArmies(this->GetId(), ptToNewNumOfArmies);

	return numOfMovements - 3; //assumed they lost 3 movements for moving over water
}
/**/
void Player::MoveOverLand(int numToMove, Country *countryToTake, Country *countryToPlace) {
	int *ptToNewNumOfArmies = new int(*countryToTake->getRefactoredArmies()[this->GetId()] - numToMove);
	countryToTake->setRefactoredArmies(this->GetId(), ptToNewNumOfArmies);

	ptToNewNumOfArmies = new int(numToMove + *countryToPlace->getRefactoredArmies()[this->GetId()]);
	countryToPlace->setRefactoredArmies(this->GetId(), ptToNewNumOfArmies);
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
	numOfCards++;
	notify(c);
	playerHand.push_back(c);
}
int Player::getIdxOfCardToPickup(Hand choiceCards) {
	std::cout << "player " << *id << " Which card would you like to pick up? (0-5)" << std::endl;
	return this->playerType->idxOfCardToPickup(choiceCards, *goldenCoins);
}

bool Player::DestroyArmy(int playerID, int numOfArmies, Country *c) {

	if (numOfArmies < 0) {
		return false;
	}
	int* ptToNewNumOfArmies = new int(*c->getRefactoredArmies()[playerID] - numOfArmies);
	c->setRefactoredArmies(playerID, ptToNewNumOfArmies);
	return true;
}
void Player::destroyArmymoveArmy(int playerIDToDestroy, int numOfArmies, Country* c, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToPlace) {
	DestroyArmy(playerIDToDestroy, numOfArmies, c);
	MoveArmies(numOfMovements, numToMove, countryToTake, countryToPlace);
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

void Player::playCard(Card c, Map* gameMap, GameEngine engine, int numPlayers) {
	string action = c.getAction();

	int countryToStart = rand() % *gameMap->getTotalCountries();
	int countryToEnd = rand() % *gameMap->getTotalCountries();
	int totalCountries = *gameMap->getTotalCountries();

	bool legality;
	int x, y, z;
	//{ "newArmy", "moveArmy", "moveOverLandOrWater", "city", "destroyArmy"};
	if (action == "newArmy") {
		cout << "enter id of country you'd like to place" << endl;
		if (engine.isUser(*this))
		{
			cin >> x;
			PlaceNewArmies(3, gameMap->getCountryArray()[x]);
			gameMap->displayPlayerStats();
		}
		else
		{
			PlaceNewArmies(3, gameMap->getCountryArray()[countryToStart]);
			gameMap->displayPlayerStats();
		}
		return;
	}
	else if (action == "moveArmy" || action == "moveOverLandOrWater") {
		if (engine.isUser(*this))
		{
			cout << "enter num of armies to move" << endl;
			cin >> x;
			cout << "enter id of country you'd like to take from" << endl;
			cin >> y;
			cout << "enter id of country you'd like to move to" << endl;
			cin >> z;
			MoveArmies(3, x, gameMap->getCountryArray()[y], gameMap->getCountryArray()[z]);
			gameMap->displayPlayerStats();
		}
		else
		{
			do
			{
				countryToStart = rand() % *gameMap->getTotalCountries();
				countryToEnd = rand() % *gameMap->getTotalCountries();
				legality = gameMap->moveIsLegal(gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd], 3);
				countryToStart = 0;
				countryToEnd = 0;
			} while (legality);
			int armiesToMove = *gameMap->getCountryArray()[countryToStart]->getRefactoredArmies()[this->GetId()];
			MoveArmies(3, armiesToMove, gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd]);
			gameMap->displayPlayerStats();
		}
		return;
	}
	else if (action == "city") {
		if (engine.isUser(*this))
		{
			cout << "enter id of country to put a city" << endl;
			cin >> x;
			BuildCity(gameMap->getCountryArray()[x]);
			gameMap->displayPlayerStats();
		}
		else
		{
			BuildCity(gameMap->getCountryArray()[rand() % totalCountries]);
			gameMap->displayPlayerStats();
		}
		return;
	}
	else if (action == "destroyArmy") {
		if (engine.isUser(*this))
		{
			cout << "Which country?" << endl;
			cin >> y;
			cout << "Which player to destroy?" << endl;
			cin >> x;
			DestroyArmy(x, 3, gameMap->getCountryArray()[y]);
			gameMap->displayPlayerStats();
		}
		else
		{
			int attackPlayer = rand() % numPlayers;
			int opponentCountry = gameMap->findOpponentArmy(attackPlayer);
			DestroyArmy(attackPlayer, 3, gameMap->getCountryArray()[opponentCountry]);
			gameMap->displayPlayerStats();
		}
		return;
	}
	//std::string listOfDoubleActions[3] = { "destroyArmymoveArmy","newArmymoveArmy","citymoveArmy" };
	else if (action == "destroyArmymoveArmy") {
		if (engine.isUser(*this))
		{
			cout << "Which player to destroy?" << endl;
			cin >> x;
			cout << "enter id of country you'd like to take from" << endl;
			cin >> y;
			DestroyArmy(x, 3, gameMap->getCountryArray()[y]);

			cout << "enter num of armies to move" << endl;
			cin >> x;
			cout << "enter id of country you'd like to take from" << endl;
			cin >> y;
			cout << "enter id of country you'd like to move to" << endl;
			cin >> z;
			MoveArmies(3, x, gameMap->getCountryArray()[y], gameMap->getCountryArray()[z]);
			
			gameMap->displayPlayerStats();
		}
		else
		{
			int attackPlayer = rand() % numPlayers;
			int opponentCountry = gameMap->findOpponentArmy(attackPlayer);
			DestroyArmy(attackPlayer, 3, gameMap->getCountryArray()[opponentCountry]);
			do
			{
				countryToStart = rand() % *gameMap->getTotalCountries();
				countryToEnd = rand() % *gameMap->getTotalCountries();
				legality = gameMap->moveIsLegal(gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd], 3);
				countryToStart = 0;
				countryToEnd = 0;
			} while (legality);
			int armiesToMove = *gameMap->getCountryArray()[countryToStart]->getRefactoredArmies()[this->GetId()];
			MoveArmies(3, armiesToMove, gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd]);
		
			gameMap->displayPlayerStats();
		}
		return;
	}
	else if (action == "newArmymoveArmy") {
		if (engine.isUser(*this))
		{
			cout << "enter id of country you'd like to place" << endl;
			cin >> x;
			PlaceNewArmies(3, gameMap->getCountryArray()[x]);
			cout << "enter num of armies to move" << endl;
			cin >> x;
			cout << "enter id of country you'd like to take from" << endl;
			cin >> y;
			cout << "enter id of country you'd like to move to" << endl;
			cin >> z;
			MoveArmies(3, x, gameMap->getCountryArray()[y], gameMap->getCountryArray()[z]);

			gameMap->displayPlayerStats();
		}
		else
		{
			PlaceNewArmies(3, gameMap->getCountryArray()[countryToStart]);
			do
			{
				countryToStart = rand() % *gameMap->getTotalCountries();
				countryToEnd = rand() % *gameMap->getTotalCountries();
				legality = gameMap->moveIsLegal(gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd], 3);
				countryToStart = 0;
				countryToEnd = 0;
			} while (legality);
			int armiesToMove = *gameMap->getCountryArray()[countryToStart]->getRefactoredArmies()[this->GetId()];
			MoveArmies(3, armiesToMove, gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd]);
		
			gameMap->displayPlayerStats();
		}
		return;
	}
	else if (action == "citymoveArmy") {
		if (engine.isUser(*this))
		{
			cout << "enter id of country to put a city" << endl;
			cin >> x;
			BuildCity(gameMap->getCountryArray()[x]);
			cout << "enter num of armies to move" << endl;
			cin >> x;
			cout << "enter id of country you'd like to take from" << endl;
			cin >> y;
			cout << "enter id of country you'd like to move to" << endl;
			cin >> z;
			MoveArmies(3, x, gameMap->getCountryArray()[y], gameMap->getCountryArray()[z]);

			gameMap->displayPlayerStats();
		}
		else
		{
			BuildCity(gameMap->getCountryArray()[rand() % totalCountries]);
			do
			{
				countryToStart = rand() % *gameMap->getTotalCountries();
				countryToEnd = rand() % *gameMap->getTotalCountries();
				legality = gameMap->moveIsLegal(gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd], 3);
				countryToStart = 0;
				countryToEnd = 0;
			} while (legality);
			int armiesToMove = *gameMap->getCountryArray()[countryToStart]->getRefactoredArmies()[this->GetId()];
			MoveArmies(3, armiesToMove, gameMap->getCountryArray()[countryToStart], gameMap->getCountryArray()[countryToEnd]);
		
			gameMap->displayPlayerStats();
		}
		return;
	}
}

int Player::computeScore() {
	//for card in hand, save number of each resource
	//for num of resource adds score 
	int score = 0;
	std::string listOfGoods[6] = { "crystal", "stone", "iron", "wood", "veggies", "wild" };
	int const MAX_NUM_GOOD = 8;
	int const crystalValue[] = {0, 1,2,3,5,5,5,5,5};
	int const stoneValue[] = { 0,0,1,2,3,5,5,5,5};
	int const ironValue[] = { 0,0,1,1,2,2,3,5,5 };
	int const woodValue[] = { 0,0,1,1,2,3,5,5,5};
	int const veggiesValue[] = { 0,0,0,1,1,2,2,3,5 };
	int numOfResource[6] = {0,0,0,0,0,0};
	for (int i = 0; i < playerHand.size(); i++) {
		if (playerHand[i].getGood().compare(listOfGoods[0]) == 0) {
			if (numOfResource[0] < MAX_NUM_GOOD) {
				numOfResource[0]++;
			}
		}
		else if (playerHand[i].getGood().compare(listOfGoods[1]) == 0) {
			if (numOfResource[0] < MAX_NUM_GOOD) {
				numOfResource[0]++;
			}
		}
		else if (playerHand[i].getGood().compare(listOfGoods[2]) == 0) {
			if (numOfResource[0] < MAX_NUM_GOOD) {
				numOfResource[0]++;
			}
		}
		else if (playerHand[i].getGood().compare(listOfGoods[3]) == 0) {
			if (numOfResource[0] < MAX_NUM_GOOD) {
				numOfResource[0]++;
			}
		}
		else if (playerHand[i].getGood().compare(listOfGoods[4]) == 0) {
			if (numOfResource[0] < MAX_NUM_GOOD) {
				numOfResource[0]++;
			}
		}
		else if (playerHand[i].getGood().compare(listOfGoods[5]) == 0) {
			if (numOfResource[0] < MAX_NUM_GOOD) {
				numOfResource[0]++;
			}
		}
	}
	score += crystalValue[numOfResource[0]];
	score += stoneValue[numOfResource[1]];
	score += ironValue[numOfResource[2]];
	score += woodValue[numOfResource[3]];
	score += veggiesValue[numOfResource[4]];

	//score += m->computeScore(id);
	return score;
}
void Player::showHand() {
	for (int i = 0; i < playerHand.size(); i++) {
		std::cout << "Card" << i << ": action: " << playerHand[i].getAction() << " good: " << playerHand[i].getGood() << " cost:" << playerHand[i].getCost() << "\n";
	}

}
void Player::setPlayerType(PlayerStrategies* newPlayerType) {
	this->playerType = newPlayerType;
}
PlayerStrategies* Player::getPlayerType() const
{
	return this->playerType;
}
int Player::currentId = 0;
Player::Player()
{
	numOfCards = 0;
	armyCubes = new int(14);
	cityDiscs = new int(3);
	goldenCoins = new int(20);
	id = new int(currentId);
	currentId++;
	std::vector<Card> playerHand;
	playerType = new PlayerUser();
}
Player::~Player()
{
}