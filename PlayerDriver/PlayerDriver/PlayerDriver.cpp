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
	int numOfPlayers = 0;
	Player* players;
	string nameOfMapFile;
	string fullPath;
	vector<vector<int>> mapDataPntr;

	while (numOfPlayers < 2 || numOfPlayers > 5) {
		cout << "How many players (2-5)" << endl;
		cin >> numOfPlayers;
	}

	players = new Player[numOfPlayers];

	// Browse possible maps
	cout << "Map files are loaded from C:\\tmp\\\n" << endl;
	string path = "C:\\tmp\\";

	// C++:V17 only, checks all files in a directory
	for (const auto& entry : fs::directory_iterator(path))
	{
		std::cout << entry.path() << std::endl;
	}
	cout << endl;

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

	if (gameMap->getIsValidMap())
	{
		cout << "This map is valid. Play on!" << endl;
	}
	else {
		cout << "This map is not a connected graph... Players will not be able to traverse it." << endl;
	}
	cout << endl;

	delete loader;

// ---------------------- END PART 1 -------------------------

// ---------------------- START PART 2 -------------------------

	bool moveLegal = gameMap->moveIsLegal(gameMap->getCountryArray()[4], gameMap->getCountryArray()[0], 3);
	
	/*gameMap->~Map();

	cout << gameMap->getAdjacencyList() << endl;
	cout << gameMap->getCountryArray()[0] << endl;
	cout << gameMap->getMapGraph() << endl;
	cout << gameMap->getTotalCountries() << endl;*/


	if (moveLegal)
		cout << "***************** Map checking works ******************" << endl;
	else
		cout << "GET BACK AT IT SON" << endl;

	//exit(0);

	cout << endl;

	Hand faceUp(gameDeck); //DECK is shuffled on creation
	faceUp.showHand();
	int idxOfPlayerTurn;
	for (int i = 0; i < numOfPlayers; i++) {
		players[i].bid();
		switch (numOfPlayers) {
		case 2: players[i].setGoldenCoins(14);
			break;
		case 3: players[i].setGoldenCoins(11);
			break;
		case 4: players[i].setGoldenCoins(9);
			break;
		case 5: players[i].setGoldenCoins(8);
			break;
		}
	}
	for (int i = 0; i < numOfPlayers; i++)
	{
		cout << players[i].GetGoldenCoins() << " " << endl;
	}

	BiddingFacility::printBidStatus();
	idxOfPlayerTurn = BiddingFacility::biddingComplete();
	cout << "player" << idxOfPlayerTurn << " won the bid\n";

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

		std::cout << "Armies have been set on desired countries. Too bad there's no GUI to see them. \nMaybe some day." << std::endl;
	}

// ---------------------- START PART 3 -------------------------

	// GAME LOOP DEMO

	int idxOfCardToTake = 0;
	/**/
	int count = 0;
	while (idxOfCardToTake != -1 && count < 4) {
		Card replacement;
		Card toPickUp;
		faceUp.showHand();
		cout << "PLAYER ORDER: " << idxOfPlayerTurn << endl;
		cout << "player" << idxOfPlayerTurn << " Which card would you like to pick up? (0-5)";
		cin >> idxOfCardToTake;
		if (players[idxOfPlayerTurn].payCoin(faceUp.cost[idxOfCardToTake])) {
			replacement = gameDeck.draw();
			toPickUp = faceUp.exchange(idxOfCardToTake,replacement);
			cout << "Card picked up has action:" << toPickUp.getAction() <<" and cost "<<toPickUp.getCost()<< endl;
			players[idxOfPlayerTurn].pickUpCard(toPickUp);
		}
		idxOfPlayerTurn = players[idxOfPlayerTurn].nextPlayerTurn(idxOfPlayerTurn, numOfPlayers);
		count++;
		cout << endl;
	}

// ---------------------- END PART 3 -------------------------

// ---------------------- START PART 4 -------------------------

	Country * c1 = gameMap->getCountryArray()[4];
	Country * c2 = gameMap->getCountryArray()[5];

	cout << "Test player ID: " << endl;
	cout << players[0].GetId() << "\n" << endl;

	//test pay coin
	cout << "Coins before pay: " << players[0].GetGoldenCoins();
	players[0].payCoin(5);
	cout << "\nCoins after pay: " << players[0].GetGoldenCoins();

	//test placeNewArmy
	cout << "\nArmies before placement: " << *gameMap->getCountryArray()[5]->getNumberOfArmies(); // Example of starter armies when players are more than 3
	cout << "\nArmies before placement (REFACTORED): " << *gameMap->getCountryArray()[5]->getRefactoredArmies()[players[0].GetId()]; // Example of starter armies when players are more than 3
	players[0].PlaceNewArmies(3, gameMap->getCountryArray()[5]);
	cout << "\nArmies after placement: " << *gameMap->getCountryArray()[5]->getNumberOfArmies();
	cout << "\nArmies after placement (REFACTORED): " << *gameMap->getCountryArray()[5]->getRefactoredArmies()[players[0].GetId()];

	//test move armies(Implements moveOverLand within move armies method)
	cout << "\nDemo of the movement function for HUMAN players. Let's assume the move card allows to move 3 armies: " << endl;
	cout << "\nPlayer " << players[0].GetId() << " armies before move on country " << *c1->getCountryNumber() << ": " << *c1->getRefactoredArmies()[players[0].GetId()] << endl; 
	cout << "\nPlayer " << players[1].GetId() << " armies before move on country " << *c2->getCountryNumber() << ": " << *c2->getRefactoredArmies()[players[1].GetId()] << endl; 
	cout << endl;

	// Hard coded player choice for the purpose of demonstration
	int playersNumberOfMoves = 3;
	int playerCountryChoice;			// Takes the player's choice of where to move the army
	int playerLastCountryChoice;		// Keeps track of a player's past moved army

	for (int i = 0; i < playersNumberOfMoves; i++)
	{
		if (i == 0)
		{
			cout << "\nWhere do you want	 to move your army?: \n";
			gameMap->displayPossibleMoves(c1);
			cin >> playerCountryChoice;
			players[1].MoveArmies(1, 1, c1, gameMap->getCountryArray()[playerCountryChoice]);
			playerLastCountryChoice = playerCountryChoice;
		}
		else
		{
			cout << "\nWhere do you want to move your army?: \n";
			gameMap->displayPossibleMoves(gameMap->getCountryArray()[playerCountryChoice]);
			cin >> playerCountryChoice;
			players[1].MoveArmies(1, 1, gameMap->getCountryArray()[playerLastCountryChoice], gameMap->getCountryArray()[playerCountryChoice]);
			playerLastCountryChoice = playerCountryChoice;
		}
	}

	// Movements will be done one at a time, so that the player decides what path to take
	cout << "\nArmies after move c1: " << *c1->getRefactoredArmies()[players[1].GetId()] << " c2: " << *c2->getRefactoredArmies()[players[1].GetId()];
	cout << endl;

	//test destroy army
	cout << "\nArmies before delete c1: " << *c1->getRefactoredArmies()[players[1].GetId()];
	players[0].DestroyArmy(players[1].GetId(), 1, c1);
	cout << "\nArmies after delete c1: " << *c1->getRefactoredArmies()[players[1].GetId()];

	//test place city (Shows id# for player that owns the city)
	cout << "\ncity status before placement: " << *c1->getCity();
	players[1].BuildCity(c1);
	cout << "\ncity status before placement: " << *c1->getCity();
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

//----------------------END PART 5-------------------------
//----------------------START PART 6-----------------------
	int* scores = new int[numOfPlayers];
	int maxScore = 0;
	int winningPlayer=0;
	//for test only
	for (int i = 0; i < 10; i++) {
		players[0].pickUpCard(gameDeck.draw());
		players[1].pickUpCard(gameDeck.draw());
	}

	for (int i = 0; i < numOfPlayers; i++) {
		cout << endl;
		scores[i] = players[i].computeScore();
		scores[i] += gameMap->computePlayerScores(players[i].GetId());

		cout << "\nPlayer " << i << " has " << scores[i] << "points" << endl;
		if (scores[i] > maxScore) {
			maxScore = scores[i];
			winningPlayer = i;
		}
	}
	cout << "\nPlayer " << winningPlayer << "won" << endl;

	delete c1, c2;
	delete gameMap;
//----------------------END PART 6----------------------------

}