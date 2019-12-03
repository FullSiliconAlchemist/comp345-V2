#include "Map.h"
#include <cstddef>
#include <iostream>
#include <map>

// Map Class functions

// Singleton Implementation --> Must instantiate singleton instance to 0
Map* Map::m_instance = 0;

vector<vector<int>>* Map::getAdjacencyList() const
{
	return adjList;
}

void Map::setCountryArray(Country** cntryArr)
{
	countryArray = cntryArr;
}

Map* Map::instance()
{
	if (!m_instance)
		m_instance = new Map();
	return m_instance;
}

Map* Map::instance(vector<vector<int>>* adjList, int* totalPlayers)
{
	if (!m_instance)
		m_instance = new Map(adjList, totalPlayers);
	return m_instance;
}

Map::MapGraph* Map::getMapGraph() const
{
	return gameGraph;
}

int* Map::getTotalPlayers() const
{
	return totalPlayers;
}

int* Map::getTotalCountries() const
{
	return totalCountries;
}

Country** Map::getCountryArray() const
{
	return countryArray;
}

void Map::displayPlayerStats()
{
	Notify();
}

void Map::displayPossibleMoves(Country* countryToTake) // Method displays all moves possible to the user
{
	CountryNode* root;
	vector<int> noRepeats;
	noRepeats.reserve(*getTotalCountries());
	bool noRepeatsConfirmed = true;
	root = getMapGraph()->arrOfCountries[*countryToTake->getCountryNumber()].head;

	std::cout << "Here are the possible moves from country number " << *countryToTake->getCountryNumber() << ":" << std::endl;
	std::cout << "[ ";

	while (root != NULL)
	{
		for (int i = 0; i < noRepeats.size(); i++)
		{
			if (root->countryData != noRepeats.at(i))
			{
				noRepeatsConfirmed = true;
				continue;
			}
			else
			{
				noRepeatsConfirmed = false;
				break;
			}
		}

		if (noRepeatsConfirmed)
		{
			noRepeats.push_back(root->countryData);
			std::cout << root->countryData << " ";
		}
		root = root->next;
	}
	std::cout << "]" << std::endl;
}

// Depth first search implemented - Ideally must check passed countries to avoid repeating patterns
bool Map::moveIsLegal(Country* countryStart, Country* countryDest, int moves) 
{
	bool answer = false;
	CountryNode* root;
	root = getMapGraph()->arrOfCountries[*countryStart->getCountryNumber()].head;

	if (*countryStart->getCountryNumber() == *countryDest->getCountryNumber())
		return true;

	if (moves < 1)
		return false;
	
	while (root != NULL)
	{
		answer = moveIsLegal(this->getCountryArray()[root->countryData], countryDest, moves - 1);

		if (answer)
			return answer;
		else
			root = root->next;
	}

	return answer;
}

int Map::findOpponentArmy(int playerAttack)
{
	// Country* countryStart, Country* countryDest
	int startingCountry = rand() % *this->getTotalCountries();

	CountryNode* root;
	root = getMapGraph()->arrOfCountries[startingCountry].head;

	if (playerAttack < 0)
		playerAttack *= -1;

	if (*this->getCountryArray()[startingCountry]->getRefactoredArmies()[playerAttack] > 0)
		return startingCountry;

	while (root != NULL)
	{
		startingCountry = findOpponentArmy(playerAttack);

		if (startingCountry > 0)
			return startingCountry;
		else
			root = root->next;
	}

	return startingCountry;
}

bool Map::getIsValidMap() const
{
	return isConnectedGraph;
}

Map::CountryNode* Map::newAdjencyListNode(int data)
{
	CountryNode* nodePtr = new CountryNode;
	nodePtr->countryData = data;
	nodePtr->next = NULL;
	return nodePtr;
}

Map::MapGraph* Map::createGraph(int V)
{
	MapGraph* graph = new MapGraph;
	// Member numberOfCountries pointed to by graph pointer
	graph->numberOfCountries = V;
	graph->arrOfCountries = new CountryList[V];
	for (int i = 0; i < V; i++) {
		graph->arrOfCountries[i].head = NULL;
	}
	return graph;
}

void Map::addEdge(MapGraph* graph, Country src, Country dest) // Changing the src and dest types to Country objects
{
	int srcCountryNumber  = *src.getCountryNumber();
	int destCountryNumber = *dest.getCountryNumber();

	// Create node pointer which points to a new node which in turn
	CountryNode* nodePtr = newAdjencyListNode(destCountryNumber);
	nodePtr->next = graph->arrOfCountries[srcCountryNumber].head;

	graph->arrOfCountries[srcCountryNumber].head = nodePtr;
	nodePtr = newAdjencyListNode(srcCountryNumber);

	nodePtr->next = graph->arrOfCountries[destCountryNumber].head;
	graph->arrOfCountries[destCountryNumber].head = nodePtr;
}

bool Map::checkGraphConnectivity()
{
	MapGraph* graph = this->getMapGraph();
	std::cout << "Checking Map graph validity..." << std::endl;
	for (int i = 0; i < graph->numberOfCountries; i++)
	{
		CountryNode* root = graph->arrOfCountries[i].head;
		if (graph->arrOfCountries[i].head == NULL)
		{
			return false;
		}
	}
	return true;
}

// Messy method with pretty bad time complexity
/*
	 The method computes each player's score by checking each country in the country array for a player's armies.
	 For each country being visited, the algorithm checks if the current player's armies are the most significant in the country, 
	 if it is less than or equal to an opposing player's armies, it will skip to the next country, else it will count a point for the player.

	 Time complexity is O(n) = O(n * p) where n is the number of countries to visit and tally per player and p is the number of players
*/
int Map::computePlayerScores(int playerID)
{
	int totalScore = 0; // Tally score

	int ID = playerID;

	bool tallyScore = false;
	int playerArmiesConquered = 0; 
	int opposingArmiesConquered = 0;

	int totalContinents = (*this->getCountryArray()[*this->getTotalCountries() - 1]->getContinentNumber() + 1); // +1 'cause arrays - assuming the map has valid continent data

	std::cout << "\nBIG REVEAL... CALCULATING SCORES...." << std::endl;
	std::cout << "FOR PLAYER :" << ID << std::endl;

	std::map<int, vector<int>> continentGraphSummary; // Map keeps track of the continents being talied

	// Initializing the map object to have the size of the amount of continents. This will be used to tally the points for 
	// the player with the most continents in control.
	for (int i = 0; i < totalContinents; i++) 
	{
		// Map with keys associated to the continent number, values are vectors of size 5 (5 players max) set to 0.
		// The idea is to count all the player's dominating countries in a continent and select the player with the most countries per continent.
		continentGraphSummary.insert(std::make_pair(i, vector<int>(5)));  
		for (int j = 0; j < 5; j++)
		{
			continentGraphSummary.find(i)->second.at(j) = 0;
		}
	}

	for (int i = 0; i < *this->getTotalCountries(); i++)
	{
		playerArmiesConquered = *this->getCountryArray()[i]->getRefactoredArmies()[ID];

		for (int j = 0; j < 5; j++)
		{
			if (j == ID)
				continue;

			opposingArmiesConquered = *this->getCountryArray()[i]->getRefactoredArmies()[j];

			if (playerArmiesConquered <= opposingArmiesConquered)
			{
				continue;
			}
			else
			{
				tallyScore = true;
			}
		}
		if (tallyScore)
		{
			continentGraphSummary.find(*this->getCountryArray()[i]->getContinentNumber())->second.at(ID) += 1;
			totalScore += 1;
		}

		tallyScore = false;
	}

	int playerContinent;
	for (int i = 0; i < totalContinents; i++)
	{
		playerContinent = continentGraphSummary.find(i)->second.at(ID);
		for (int j = 0; j < 5; j++)
		{
			if (playerContinent <= continentGraphSummary.find(i)->second.at(j))
				break;
			else
				tallyScore = true;
		}
		if (tallyScore)
			totalScore += 1;

		tallyScore = false;
	}

	return totalScore;
}

void Map::printGraph(MapGraph* graph)
{
	for (int i = 0; i < graph->numberOfCountries; i++)
	{
		CountryNode* root = graph->arrOfCountries[i].head;
		std::cout << "Adjency list of vertex: " << i << std::endl;
		while (root != NULL)
		{
			std::cout << " -> " << root->countryData;
			root = root->next;
		}
		std::cout << std::endl;
	}
}

Map::Map()
{
	this->adjList = NULL;
	this->countryArray = NULL;
	this->gameGraph = NULL;
	this->isConnectedGraph = false;
	this->totalCountries = new int(0);
	this->totalPlayers = new int(0);
}

// Factory method design pattern
Map::Map(vector<vector<int>>* initMapData, int* totalPlayers)
	: adjList(initMapData), totalPlayers(totalPlayers)
{
	std::cout << "Initializing map..." << std::endl;

	int countryListSize = static_cast<int>(initMapData->size());
	this->totalCountries = new int(countryListSize); // Add getters and setters for the totalCountries, check if saved

	int*** arrayOfPtrs = new int** [countryListSize];

	this->countryArray = new Country* [countryListSize]; // Initializing Map object pntr array ************

	// initialize ptrs to country data
	for (int i = 0; i < countryListSize; i++)
	{
		arrayOfPtrs[i] = new int* [initMapData->at(i).size()];
	}

	for (int i = 0; i < countryListSize; i++)
	{
		for (int j = 0; j < static_cast<int>(initMapData->at(i).size()); j++)
		{
			arrayOfPtrs[i][j] = new int(initMapData->at(i).at(j));
		}
	}

	this->gameGraph = createGraph(countryListSize); // Member variable initialized. Now accessible from map object.

	for (int i = 0; i < static_cast<int>(initMapData->size()); i++)
	{
		if (arrayOfPtrs[i][0] != NULL)
		{
			this->countryArray[i] = new Country(arrayOfPtrs[i][0], arrayOfPtrs[i][1]);  // Buffer overrun Warning: Basically means we can't be 100% certain that 
		}
																				// 2D array passed in the constructor will have a minimum length of array[i].size() >= 2
																				// How do I prove to the compiler that this will always be the case?
	}
	for (int i = 0; i < static_cast<int>(initMapData->size()); i++)
	{
		for (int j = 2; j < static_cast<int>(initMapData->at(i).size()); j++)
		{
			if (this->getCountryArray() != NULL && arrayOfPtrs != NULL)
			{
				this->addEdge(gameGraph, *this->getCountryArray()[i], *this->getCountryArray()[*arrayOfPtrs[i][j]]); // What could this mean ffs
			}
		}
	}

	// Validates graph by checking to see if there are any Country Nodes which aren't connected to some other country
	this->isConnectedGraph = checkGraphConnectivity();

	// Deallocate memory
	for (int i = 0; i < countryListSize; i++)
	{
		for (int j = 0; j < initMapData->at(i).size(); j++)
		{
			arrayOfPtrs[i][j] = NULL; // Why the warning here?
		}
		arrayOfPtrs[i] = NULL;
	}

	delete[] arrayOfPtrs;
}

// Should notify the view to display stats or some shit
//void Map::displayPlayerStats()
//{
//	Notify();
//}

Map::~Map()
{
	this->adjList = NULL;
	for (int i = 0; i < *this->totalCountries; i++)
	{
		this->countryArray[i]->~Country();
		this->countryArray[i] = NULL;
	}
	delete[] this->countryArray;
	delete this->gameGraph;
	this->gameGraph = NULL;
	delete this->totalCountries;
	totalCountries = NULL;
	totalPlayers = NULL;
	std::cout << "Map deleted" << std::endl;
}
