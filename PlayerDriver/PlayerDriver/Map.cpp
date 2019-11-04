#include "Map.h"
#include <cstddef>
#include <iostream>

// Map Class functions

vector<vector<int>>* Map::getAdjacencyList() const
{
	return adjList;
}

void Map::setCountryArray(Country** cntryArr)
{
	countryArray = cntryArr;
}

Map::MapGraph* Map::getMapGraph() const
{
	return gameGraph;
}

int* Map::getTotalCountries() const
{
	return totalCountries;
}

Country** Map::getCountryArray() const
{
	return countryArray;
}

void Map::displayPossibleMoves(Country* countryToTake)
{
	CountryNode* root;
	vector<int> noRepeats;
	noRepeats.reserve(*getTotalCountries());
	bool noRepeatsConfirmed = true;
	root = getMapGraph()->arrOfCountries[*countryToTake->getCountryNumber()].head;

	std::cout << "Here are the possbile moves from country number " << *countryToTake->getCountryNumber() << ":" << std::endl;
	std::cout << "[ ";

	while (root != NULL)
	{
		for (int i = 0; i < noRepeats.size(); i++)
		{
			if (root->countryData != noRepeats.at(i))
				continue;
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
	std::cout << "Initializing a default game Map requires adding countries manually." << std::endl;
}

// Factory method design pattern
Map::Map(vector<vector<int>> * initMapData) 
	: adjList(initMapData) 
{
	std::cout << "Initializing map..." << std::endl;

	int countryListSize = static_cast<int>(initMapData->size());
	this->totalCountries = new int(countryListSize); // Add getters and setters for the totalCountries, check if saved

	int*** arrayOfPtrs = new int** [countryListSize];

	countryArray = new Country *[countryListSize]; // Initializing Map object pntr array ************

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

	gameGraph = createGraph(countryListSize); // Member variable initialized. Now accessible from map object.
	vector<Country*> countryVectorData;

	for (int i = 0; i < static_cast<int>(initMapData->size()); i++)
	{
		countryVectorData.push_back(new Country(arrayOfPtrs[i][0], arrayOfPtrs[i][1])); // Waste of space, should be using the array I made in the constructor
		countryArray[i] = new Country(arrayOfPtrs[i][0], arrayOfPtrs[i][1]);			// Buffer overrun - Whatever just trying to make it work right now
	}

	for (int i = 0; i < static_cast<int>(initMapData->size()); i++)
	{
		for (int j = 2; j < static_cast<int>(initMapData->at(i).size()); j++)
		{
			addEdge(gameGraph, *countryVectorData.at(i), *countryVectorData.at(*arrayOfPtrs[i][j]));
		}
	}

	// Validates graph by checking to see if there are any Country Nodes which aren't connected to some other country
	this->isConnectedGraph = checkGraphConnectivity();

	// Deallocate memory
	for (int i = 0; i < countryListSize; i++)
	{
		for (int j = 0; j < initMapData->at(i).size(); j++)
		{
			arrayOfPtrs[i][j] = NULL;
		}
		arrayOfPtrs[i] = NULL;
	}

	delete[] arrayOfPtrs;
}

Map::~Map()
{
}
