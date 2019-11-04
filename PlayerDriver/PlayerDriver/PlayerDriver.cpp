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

	string fullPath;
	vector<vector<int>> mapDataPntr;

	cout << "How many players (2-5)" << endl;
	cin >> numOfPlayers;
	players = new Player[numOfPlayers];

	// used map loader to load nameOfMapFile ******************************* and create a map

	// Browse possible maps
	cout << "Map files are loaded from C:\\tmp\\\n" << endl;
	string path = "C:\\tmp\\";

	// C++:V17 only, checks all files in a directory
	for (const auto& entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;

	// Loop for when the player wants to load a file
	// Should probs be a method in class such as mapLoader
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

	//cout << "Country from country vector object initialized in constructor, country number: " << *gameMap->getCountryVector()->at(5)->getCountryNumber() << endl;
	cout << "Country from country vector object initialized in constructor, country number: " << *gameMap->getCountryArray()[5]->getCountryNumber() << endl;

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

	// Players choose where they set their armies if there are only two players playing.
	// Otherwise they're set in the starting country.
	int countryToSetArmyP1, countryToSetArmyP2;

	if (numOfPlayers > 2)
	{
		std::cout << "\nPlayers, 3 of your armies will be placed on a random country in the \"starter region\"."  << std::endl;
		std::cout << "The programmer making this game has decided it will be the country 4."					<< std::endl;
		std::cout << "Countries are defined by numbers, starting at 0 to the total number of countries - 1\n"   << std::endl;

		for (int i = 0; i < numOfPlayers; i++)
		{
			players[i].PlaceNewArmies(3, gameMap->getCountryArray()[4]);
		}

		std::cout << "3 armies per player have been set on country 4.\n" << std::endl;
	}
	else
	{
		std::cout << "Players take turns placing 1 army at a time on any country, until 10 armies per player has been placed." << std::endl;
		std::cout << "Countries are defined by numbers, starting at 0 to the total number of countries - 1\n"				   << std::endl;
		
		for (int i = 0; i < 10; i++)
		{
			std::cout << "Round " << (i + 1) << " of setting armies..." << std::endl;
			std::cout << "Player 1 pick a Country number from 0 to " << (*gameMap->getTotalCountries() - 1) << " to place your army: ";
			cin >> countryToSetArmyP1;
			std::cout << "Player 2 pick a Country number from 0 to " << (*gameMap->getTotalCountries() - 1) << " to place your army: ";
			cin >> countryToSetArmyP2;

			players[0].PlaceNewArmies(1, gameMap->getCountryArray()[countryToSetArmyP1]); // Should check to see if it is valid to put two armies of different players in the same country to start
			players[1].PlaceNewArmies(1, gameMap->getCountryArray()[countryToSetArmyP2]);

			std::cout << std::endl;
		}

		std::cout << "Armies have been set on desired countries. Too bad there's no GUI to see them." << std::endl;
	}

	//Need to place players starting armies on the map ******************

// ---------------------- START PART 3 -------------------------

	// According to the rules, the game is over once all players have gotten a certain number 
	// of cards. Thus, after each player has gone their turn, the game will check for to see if all players
	// have acquired their maximum number of cards. Once the game loop is done, there will be a tally of the points
	// to determine the winner.

	bool gameRunning = true;

	while (gameRunning)
	{

	}

// ---------------------- START PART 4 -------------------------
	Player p;

	Country * c1 = new Country();
	Country * c2 = new Country();

	//test pay coin
	cout << "Coins before pay: " << p.GetGoldenCoins();
	p.payCoin(5);
	cout << "\nCoins after pay: " << p.GetGoldenCoins();

	//test placeNewArmy
	cout << "\nArmies before placement: " << *gameMap->getCountryArray()[4]->getNumberOfArmies(); // Example of starter armies when players are more than 3
	p.PlaceNewArmies(3, gameMap->getCountryArray()[5]);
	cout << "\nArmies after placement: " << *gameMap->getCountryArray()[5]->getNumberOfArmies();

	//test move armies(Implements moveOverLand within move armies method)
	cout << "\nArmies before move c1: " << *c1->getNumberOfArmies() <<" c2: "<< *c2->getNumberOfArmies();
	p.MoveArmies(3, 1, c1, c2);
	cout << "\nArmies before move c1: " << *c1->getNumberOfArmies() << " c2: " << *c2->getNumberOfArmies();

	//test destroy army
	cout << "\nArmies before delete c1: " << *c1->getNumberOfArmies();
	p.DestroyArmy(1, c1);
	cout << "\nArmies after delete c1: " << *c1->getNumberOfArmies();

	//test place city (Shows id# for player that owns the city)
	cout << "\ncity status before placement: " << *c1->getCity();
	p.BuildCity(c1);
	cout << "\ncity status before placement: " << *c1->getCity();
// ---------------------- END PART 4 -------------------------

// ---------------------- START PART 5 -------------------------
	cout << "\n\n";
	faceUp.showHand();
	Card nextCard = gameDeck.draw();
	Card toPickup = faceUp.exchange(0, nextCard);
	cout << "\n\n";
	faceUp.showHand();
	// ********** Next players turn **********************

	delete c1, c2;

//---------------------- END PART 5 -------------------------
}