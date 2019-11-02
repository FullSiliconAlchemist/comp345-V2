#include <string>
#include <iostream>
#include <vector>
#include "Map.h"
#include "MapLoader.h"
#include "Country.h"
#include "Player.h"
#include "Cards.h"
#include "BiddingFacility.h"
using namespace std;

int main()
{
// ---------------------- START PART 1 -------------------------
	Deck gameDeck;
	Map *gameMap;
	
	MapLoader* loader = new MapLoader();

	// Current file name
	string fileName = "C:\\tmp\\datafile.txt";

	string* strptr = &fileName;

	vector<vector<int>> mapData = loader->openFileAndStore(strptr);

	vector<vector<int>> * mapDataPntr = &mapData;

	gameMap = new Map(mapDataPntr);

	 // create and show deck / face up cards
	int numOfPlayers;
	Player* players;
	string nameOfMapFile;

	cout << "How many players (2-5)" << endl;
	cin >> numOfPlayers;
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
	std::cout << "player" << idxOfPlayerTurn << " won the bid\n";

	//Need to place players starting armies on the map ******************

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
	cout << "\ncity status before placement: " << *c1.getCity();
// ---------------------- END PART 4 -------------------------

// ---------------------- START PART 5 -------------------------
	cout << "\n\n";
	faceUp.showHand();
	Card nextCard = gameDeck.draw();
	Card toPickup = faceUp.exchange(0, nextCard);
	cout << "\n\n";
	faceUp.showHand();
	// ********** Next players turn **********************


//---------------------- END PART 5 -------------------------
}