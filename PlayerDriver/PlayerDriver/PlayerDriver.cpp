#include <string>
#include <iostream>
#include <vector>
#include "Map.h"
#include "Country.h"
#include "Player.h"
#include "Cards.h"
#include "BiddingFacility.h"
using namespace std;

int main()
{
// ---------------------- START PART 1 -------------------------
	Deck gameDeck;
	 // create and show deck / face up cards
	int numOfPlayers = 0;
	Player* players;
	string nameOfMapFile;
	while (numOfPlayers < 2 || numOfPlayers > 5) {
		cout << "How many players (2-5)" << endl;
		cin >> numOfPlayers;
	}

	players = new Player[numOfPlayers];

	cout << "What is the name of the map file?" << endl;
	cin >> nameOfMapFile;
	// used map loader to load nameOfMapFile ******************************* and create a map
// ---------------------- END PART 1 -------------------------
// ---------------------- START PART 2 -------------------------
	Hand faceUp(gameDeck); //DECK is shuffled on creation
	faceUp.showHand();
	int idxOfPlayerTurn;
	for (int i = 0; i < numOfPlayers; i++) {
		players[i].bid();
		switch (numOfPlayers) {
		case 2: players[i].setGoldenCoins(14);
		case 3: players[i].setGoldenCoins(11);
		case 4: players[i].setGoldenCoins(9);
		case 5: players[i].setGoldenCoins(8);
		}
	}
	BiddingFacility::printBidStatus();
	idxOfPlayerTurn = BiddingFacility::biddingComplete();
	cout << "player" << idxOfPlayerTurn << " won the bid\n";

	//Need to place players starting armies on the map ******************
// ---------------------- START PART 3 -------------------------
	int idxOfCardToTake = 0;
	while (idxOfCardToTake != -1) {
		
		Card replacement;
		Card toPickUp;
		faceUp.showHand();
		cout << "player" << idxOfPlayerTurn << " Which card would you like to pick up? (0-5)";
		cin >> idxOfCardToTake;

		if (players[idxOfPlayerTurn].payCoin(faceUp.cost[idxOfCardToTake])) {
			replacement = gameDeck.draw();
			toPickUp = faceUp.exchange(idxOfCardToTake,replacement);
			cout << "Card picked up has action:" << toPickUp.getAction() <<" and cost "<<toPickUp.getCost()<< endl;
			players[idxOfPlayerTurn].pickUpCard(toPickUp);
		}
		idxOfPlayerTurn = players[idxOfPlayerTurn].nextPlayerTurn(idxOfPlayerTurn, numOfPlayers);
	}
// ---------------------- END PART 3 -------------------------
// ---------------------- START PART 4 -------------------------
	Player p;
	Country c1,c2;
	Country *ptrC1 = &c1;
	Country *ptrC2 = &c2;

	//test pay coin
	cout << "Coins before pay: " << p.GetGoldenCoins();
	p.payCoin(5);
	cout << "\nCoins after pay: " << p.GetGoldenCoins();

	//test placeNewArmy
	cout << "\nArmies before placement: " << *c1.getNumberOfArmies();
	p.PlaceNewArmies(3, ptrC1);
	cout << "\nArmies after placement: " << *c1.getNumberOfArmies();

	//test move armies(Implements moveOverLand within move armies method)
	cout << "\nArmies before move c1: " << *c1.getNumberOfArmies() <<" c2: "<< *c2.getNumberOfArmies();
	p.MoveArmies(3, 1, ptrC1, ptrC2);
	cout << "\nArmies before move c1: " << *c1.getNumberOfArmies() << " c2: " << *c2.getNumberOfArmies();

	//test destroy army
	cout << "\nArmies before delete c1: " << *c1.getNumberOfArmies();
	p.DestroyArmy(1, ptrC1);
	cout << "\nArmies after delete c1: " << *c1.getNumberOfArmies();

	//test place city (Shows id# for player that owns the city)
	cout << "\ncity status before placement: " << *c1.getCity();
	p.BuildCity(ptrC1);
	cout << "\ncity status after placement: " << *c1.getCity();
	//void destroyArmymoveArmy(int numOfArmies, Country* c, int numOfMovements, int numToMove, Country* countryToTake, Country* countryToPlace);
	//void newArmymoveArmy(int numOfArmies, Country * countryToPlace, int numOfMovements, int numToMove, Country * countryToTake, Country * countryToMoveTo);
	//void citymoveArmy(Country * c, int numOfMovements, int numToMove, Country * countryToTake, Country * countryToPlace);
	//void ignore
// ---------------------- END PART 4 -------------------------

// ---------------------- START PART 5 -------------------------
	cout << "\n\n";
	faceUp.showHand();
	Card nextCard = gameDeck.draw();
	Card toPickup = faceUp.exchange(0, nextCard);
	cout << "\n\n";
	faceUp.showHand();
	// ********** Next players turn ********************** not impletement as part of 1 whole loop(idxOfPlayerTurn = players[idxOfPlayerTurn].nextPlayerTurn(idxOfPlayerTurn, numOfPlayers);)
//---------------------- END PART 5 -------------------------
}