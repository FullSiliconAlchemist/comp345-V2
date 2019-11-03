#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include "Map.h"
#include "MapLoader.h"
#include "Country.h"
#include "Player.h"
#include "Cards.h"
#include "BiddingFacility.h"

using namespace std;
namespace fs = std::filesystem; // *** Filesystem library is part of C++ V17 ***

int main()
{
// ---------------------- START PART 1 -------------------------
	Deck gameDeck;
	Map *gameMap;
	MapLoader* loader = new MapLoader();

	 // create and show deck / face up cards
	int numOfPlayers;
	Player* players;
	string nameOfMapFile;

	vector<vector<int>>* loadedData;

	cout << "How many players (2-5)" << endl;
	cin >> numOfPlayers;
	players = new Player[numOfPlayers];

	// used map loader to load nameOfMapFile ******************************* and create a map

	// Browse possible maps
	cout << "Map files are loaded from C:\\tmp\\\n" << endl;
	string path = "C:\\tmp\\";

	for (const auto& entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;

	string fullPath;
	vector<vector<int>> mapDataPntr;

	do {
		fullPath = path;
		cout << "Which map do you want to load?" << endl;
		cin >> nameOfMapFile;

		fullPath.append(nameOfMapFile);
		string* strptr = &fullPath;

		mapDataPntr = loader->openFileAndStore(strptr);
	
	} while (!loader->getIsLoaded());
	
	// Initialize map object from map data
	gameMap = new Map(&mapDataPntr);

	if (gameMap->checkGraphConnectivity())
	{
		cout << "This map is valid. Play on!" << endl;
	}
	else {
		cout << "This map is not a connected graph... Players will not be able to traverse it." << endl;
	}
	cout << endl;

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