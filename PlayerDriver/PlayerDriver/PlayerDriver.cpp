#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include "Map.h"
#include "MapLoader.h"
#include "Country.h"
#include "Player.h"
#include "Cards.h"
#include "BiddingFacility.h"
#include "GameView.h"
#include "GameEngine.h"

using namespace std;
namespace fs = std::filesystem; // *** Filesystem library is part of C++ V17 ***

int main()
{

	//--------------------------------------------------------------- GAME SET UP --------------------------------------------------------------
	srand(time(0));

	Deck gameDeck;
	Map *gameMap;
	MapLoader* loader = new MapLoader();
	GameEngine someEngine;

	int numOfPlayers = 0;
	Player* players;
	string nameOfMapFile;
	string fullPath;
	vector<vector<int>> mapDataPntr;

	string decision;

	// TOURNAMENT MODE SELECTION
	do {
		cout << "Which game mode would you like to play?" << endl;
		cout << "Press 'a' for tournament mode and 'b' for normal mode:" << endl;
		cin >> decision;
		
		if (decision.at(0) == 'a')
		{
			someEngine.setIsTournament(true);
			cout << "Tournament mode has been selected." << endl;
		}
		else
		{
			cout << "Normal mode has been selected." << endl;
		}

	} while (decision.at(0) != 'a' && decision.at(0) != 'b');

	// PLAYER NUMBER SELECTION
	while (numOfPlayers < 2 || numOfPlayers > 5) {
		cout << "How many players (2-5)" << endl;
		cin >> numOfPlayers;
	}
	players = new Player[numOfPlayers];
	int typeOfPlayer;

	// PLAYER TYPE SELECTION (NORMAL MODE OR TOURNAMENT MODE)
	for (int i = 0; i < numOfPlayers; i++) {
		cout << "what type of player is player " << i << "?\n (0 for PlayerUser, 1 for PlayerAgressive, 2 for PlayerPassive" << endl;
		cin >> typeOfPlayer;
		switch (typeOfPlayer) {
		case 0: players[i].setPlayerType(new PlayerUser());
			break;
		case 1: players[i].setPlayerType(new PlayerAgressive());
			break;
		case 2: players[i].setPlayerType(new PlayerPassive());
			break;
		}
		PlayerView* v = new PlayerView(&players[i]);
	}
	// BROWSE MAPS
	// C++:V17 only, checks all files in a directory
	cout << "Map files are loaded from C:\\tmp\\\n" << endl;
	string path = "C:\\temp\\";
	for (const auto& entry : fs::directory_iterator(path))
	{
		std::cout << entry.path() << std::endl;
	}
	cout << endl;

	// MAP LOADING PROCESS: ERROR CHEKING IS PRESENT
	do {
		fullPath = path;
		cout << "Which map do you want to load?" << endl;
		cin >> nameOfMapFile;

		fullPath.append(nameOfMapFile);
		string* strptr = &fullPath;

		mapDataPntr = loader->openFileAndStore(strptr);
	
	} while (!loader->getIsLoaded());
	
	// MAP SINGLETON + GAMEMAP OBSERVER
	gameMap = Map::instance(&mapDataPntr, &numOfPlayers);	
	MapViewer* view = new MapViewer(gameMap);

	// MAP VERIFICATION
	if (gameMap->getIsValidMap())
	{
		cout << "This map is valid. Play on!" << endl;
	}
	else {
		cout << "This map is not a connected graph... Players will not be able to traverse it." << endl;
	}
	cout << endl;

	// DELETE MAP LOADER - PURPOSE HAS BEEN SERVED
	delete loader;

	// AI MOVEMENT DEPTH FIRST SEARCH FOR A COUNTRY WITHIN A CERTAIN LIMIT OF MOVEMENTS
	bool moveLegal = gameMap->moveIsLegal(gameMap->getCountryArray()[4], gameMap->getCountryArray()[1], 3);
	if (moveLegal)
		cout << "PLAYER CAN MOVE TO SELECTED COUNTRY" << endl;
	else
		cout << "MOVE IS ILLEGAL" << endl;
	cout << endl;

	// BIDDING PROCESS - BID METHOD ONLY WORKS WITH HUMAN INPUT
	Hand faceUp(gameDeck); 
	faceUp.showHand();
	int idxOfPlayerTurn;
	//string playerType;

	// In tournament mode, we check to see if the player type class is a User
	// if it is, we allow the user to pick an age and bid, 
	// if not numbers are generated randomly from some arbirtrary range
	if (someEngine.getIsTournament())
	{
		for (int i = 0; i < numOfPlayers; i++) {
			//playerType = typeid(*players[i].getPlayerType()).name();

			if (!someEngine.isUser(players[i]))
				players[i].bid(rand() % 50, rand() % 10);
			else
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
	}
	else
	{
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
	}

	// DISPLAY EACH PLAYERS GOLD COINS AFTER BIDDING PROCESS
	for (int i = 0; i < numOfPlayers; i++)
	{
		cout << players[i].GetGoldenCoins() << " " << endl;
	}

	// DISPLAY WINNING PLAYER AND STARTING PLAYER
	BiddingFacility::printBidStatus();
	idxOfPlayerTurn = BiddingFacility::biddingComplete();
	cout << "player" << idxOfPlayerTurn << " won the bid\n";

	//--------------------------------------------------------------- GAME SET UP END ---------------------------------------------------------------
	//
	// GAMEPLAY MODE WILL NOW BEGIN
	//
	//--------------------------------------------------------------- GAMEPLAY MODE ---------------------------------------------------------------

	// PLAYER ARMIES PLACEMENT ON THE GAME MAP WITH RESPECT TO THE NUMBER OF TOTAL PLAYERS IN THE GAME
	int countryToSetArmyP1, countryToSetArmyP2;

	if (numOfPlayers > 2)
	{
		std::cout << "\nPlayers, 3 of your armies will be placed on a random country in the \"starter region\"." << std::endl;
		std::cout << "The programmer making this game has decided it will be the country 4."					 << std::endl;
		std::cout << "Countries are defined by numbers, starting at 0 to the total number of countries - 1\n"    << std::endl;

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
			if (someEngine.isUser(players[0]))
			{
				std::cout << "Player 1 pick a Country number from 0 to " << (*gameMap->getTotalCountries() - 1) << " to place your army: ";
				cin >> countryToSetArmyP1;
			}
			else
				countryToSetArmyP1 = rand() % (*gameMap->getTotalCountries() - 1);
			
			if (someEngine.isUser(players[1]))
			{
				std::cout << "Player 2 pick a Country number from 0 to " << (*gameMap->getTotalCountries() - 1) << " to place your army: ";
				cin >> countryToSetArmyP2;
			}
			else
				countryToSetArmyP2 = rand() % (*gameMap->getTotalCountries() - 1);

			// Checks player army setting to be in the correct range
			while (countryToSetArmyP1 < 0 || countryToSetArmyP1 > *gameMap->getTotalCountries() - 1 || countryToSetArmyP2 < 0 || countryToSetArmyP2 > *gameMap->getTotalCountries() - 1)
			{
				std::cout << "\nPlayers cannot set an army outside of the range of countries on the map... Come on it ain't hard.\n" << std::endl;
				std::cout << "Round " << (i + 1) << " of setting armies..." << std::endl;
				// Only asks for a prompt when the player is a user
				if (someEngine.isUser(players[0]))
				{
					std::cout << "Player 1 pick a Country number from 0 to " << (*gameMap->getTotalCountries() - 1) << " to place your army: ";
					cin >> countryToSetArmyP1;
				}
				if (someEngine.isUser(players[1]))
				{
					std::cout << "Player 2 pick a Country number from 0 to " << (*gameMap->getTotalCountries() - 1) << " to place your army: ";
					cin >> countryToSetArmyP2;
				}
			}

			players[0].PlaceNewArmies(1, gameMap->getCountryArray()[countryToSetArmyP1]); // Should check to see if it is valid to put two armies of different players in the same country to start
			players[1].PlaceNewArmies(1, gameMap->getCountryArray()[countryToSetArmyP2]);
			std::cout << std::endl;

		}

		std::cout << "Armies have been set on desired countries. Too bad there's no GUI to see them. \nMaybe some day.\n" << std::endl;
	}

	// INITIAL GAME PLAYER STATS 
	gameMap->displayPlayerStats();
	int idxOfCardToTake = 0;

	Country* c1 = gameMap->getCountryArray()[4];
	Country* c2 = gameMap->getCountryArray()[5];

	//test destroy army
	cout << "\nArmies before delete c1: " << *c1->getRefactoredArmies()[players[1].GetId()];
	players[0].DestroyArmy(players[1].GetId(), 1, c1);
	cout << "\nArmies after delete c1: " << *c1->getRefactoredArmies()[players[1].GetId()];
	gameMap->displayPlayerStats();

	// GAME LOOP
	// GAME ENDS AT 30 TURNS PER PLAYER

	int count = 0;
	/**/
	while (idxOfCardToTake != -1 && count < 30) {
		Card replacement;
		Card toPickUp;
		std::string action; // Card action returned by getAction method

		faceUp.showHand();
		
		if (someEngine.isUser(players[idxOfPlayerTurn]))
		{
			cout << "Player" << idxOfPlayerTurn << " Which card would you like to pick up? (0-5)\n";
			cin >> idxOfCardToTake;

			cout << "Player " << idxOfPlayerTurn << " picked up card in slot " << idxOfCardToTake << endl;
			players[idxOfPlayerTurn].payCoin(faceUp.cost[idxOfCardToTake]);

			replacement = gameDeck.draw();
			toPickUp = faceUp.exchange(idxOfCardToTake, replacement);
			cout << "Card picked up has action:" << toPickUp.getAction() << " and cost " << toPickUp.getCost() << endl;
			players[idxOfPlayerTurn].pickUpCard(toPickUp);

			players[idxOfPlayerTurn].playCard(toPickUp, gameMap, someEngine, numOfPlayers);
		}
		else
		{
			cout << "Computer's turn. Player: " << idxOfPlayerTurn << "\n" << endl;
			idxOfCardToTake = players[idxOfPlayerTurn].getIdxOfCardToPickup(faceUp);

			players[idxOfPlayerTurn].payCoin(faceUp.cost[idxOfCardToTake]);

			replacement = gameDeck.draw();
			toPickUp = faceUp.exchange(idxOfCardToTake,replacement);
			cout << "\nCard picked up has action: " << toPickUp.getAction() << " and cost " <<toPickUp.getCost() << endl;
			players[idxOfPlayerTurn].pickUpCard(toPickUp);

			// Player uses card action
			players[idxOfPlayerTurn].playCard(toPickUp, gameMap, someEngine, numOfPlayers);
		}
		idxOfPlayerTurn = players[idxOfPlayerTurn].nextPlayerTurn(idxOfPlayerTurn, numOfPlayers);
		count++;
		cout << endl;
	}

	// PLAYER METHOD DEMOS
	/*

	
	// GAMEPLAY DEMONSTRATION: SHOWS ALL OF THE GAME METHODS INSTEAD OF RUNNING THROUGH THE WHOLE GAME

	cout << "Test player ID: " << endl;
	cout << players[0].GetId() << "\n" << endl;

	//test pay coin
	cout << "Coins before pay: " << players[0].GetGoldenCoins();
	players[0].payCoin(5);
	cout << "\nCoins after pay: " << players[0].GetGoldenCoins();

	//test placeNewArmy
	cout << "\nArmies before placement (REFACTORED): " << *gameMap->getCountryArray()[5]->getRefactoredArmies()[players[0].GetId()]; // Example of starter armies when players are more than 3
	players[0].PlaceNewArmies(3, gameMap->getCountryArray()[5]);
	cout << "\nArmies after placement (REFACTORED): " << *gameMap->getCountryArray()[5]->getRefactoredArmies()[players[0].GetId()];

	//test move armies(Implements moveOverLand within move armies method)
	cout << "\nDemo of the movement function for HUMAN players. Let's assume the move card allows to move 3 armies: " << endl;
	cout << "\nPlayer " << players[0].GetId() << " armies before move on country " << *c1->getCountryNumber() << ": " << *c1->getRefactoredArmies()[players[0].GetId()] << endl; 
	cout << "\nPlayer " << players[1].GetId() << " armies before move on country " << *c2->getCountryNumber() << ": " << *c2->getRefactoredArmies()[players[1].GetId()] << endl; 
	cout << endl;

	// Hard coded player choice for the purpose of demonstration
	int playersNumberOfMoves = 3;
	int playerCountryChoice;			// Takes the player's choice of where to move the army
	int playerLastCountryChoice;	   // Keeps track of a player's past moved army

	// ARMY MOVEMENT FOR PLAYERS
	for (int i = 0; i < playersNumberOfMoves; i++)
	{
		if (i == 0)
		{
			cout << "\nWhere do you want	 to move your army?: \n";
			gameMap->displayPossibleMoves(c1);
			cin >> playerCountryChoice;
			players[1].MoveArmies(1, 1, c1, gameMap->getCountryArray()[playerCountryChoice]);
			playerLastCountryChoice = playerCountryChoice;
			gameMap->displayPlayerStats();
		}
		else
		{
			cout << "\nWhere do you want to move your army?: \n";
			gameMap->displayPossibleMoves(gameMap->getCountryArray()[playerCountryChoice]);
			cin >> playerCountryChoice;
			players[1].MoveArmies(1, 1, gameMap->getCountryArray()[playerLastCountryChoice], gameMap->getCountryArray()[playerCountryChoice]);
			playerLastCountryChoice = playerCountryChoice;
			gameMap->displayPlayerStats();
		}
	}

	gameMap->displayPlayerStats();

	// Movements will be done one at a time, so that the player decides what path to take
	cout << "\nArmies after move c1: " << *c1->getRefactoredArmies()[players[1].GetId()] << " c2: " << *c2->getRefactoredArmies()[players[1].GetId()];
	cout << endl;

	//test place city (Shows id# for player that owns the city)
	cout << "\ncity status before placement: " << *c1->getCity();
	players[1].BuildCity(c1);
	cout << "\ncity status before placement: " << *c1->getCity();
	gameMap->displayPlayerStats();

	cout << "\n\n";
	faceUp.showHand();
	Card nextCard = gameDeck.draw();
	Card toPickup = faceUp.exchange(0, nextCard);
	cout << "\n\n";
	faceUp.showHand();
	*/

	gameMap->displayPlayerStats();

	//--------------------------------------------------------------- GAMEPLAY MODE END ---------------------------------------------------------------
	//
	// 
	//
	//--------------------------------------------------------------- GAME WINNER DECLARATION ---------------------------------------------------------------

	int* scores = new int[numOfPlayers];
	int maxScore = 0;
	int winningPlayer=0;

	someEngine.displayResults(players, gameMap, numOfPlayers);

	for (int i = 0; i < numOfPlayers; i++) {
		cout << endl;
		scores[i] = players[i].computeScore();
		scores[i] += gameMap->computePlayerScores(players[i].GetId());

		//cout << "\nPlayer " << i << " has " << scores[i] << "points" << endl;
		if (scores[i] > maxScore) {
			maxScore = scores[i];
			winningPlayer = i;
		}
	}
	cout << "\nPlayer " << winningPlayer << "won" << endl;

	delete c1, c2;
	delete gameMap;

	//--------------------------------------------------------------- GAME WINNER DECLARATION END ---------------------------------------------------------------
	
}