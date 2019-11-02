#include "Map.h"
#include <cstddef>
#include <iostream>

// Map Class functions

vector<Country*>* Map::getCountryVector() const
{
	return countryVector;
}

vector<vector<int>>* Map::getAdjacencyList() const
{
	return adjList;
}

void Map::setCountryVector(vector<Country*>* cntryVect)
{
	countryVector = cntryVect;
}

Map::MapGraph* Map::getMapGraph() const
{
	return gameGraph;
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
	int* ptrCountrySrc = src.getCountryNumber();;
	int srcCountryNumber = *ptrCountrySrc;

	int* ptrCountryDest = dest.getCountryNumber();
	int destCountryNumber = *ptrCountryDest;

	// Create node pointer which points to a new node which in turn
	CountryNode* nodePtr = newAdjencyListNode(destCountryNumber);
	nodePtr->next = graph->arrOfCountries[srcCountryNumber].head;

	graph->arrOfCountries[srcCountryNumber].head = nodePtr;
	nodePtr = newAdjencyListNode(srcCountryNumber);

	nodePtr->next = graph->arrOfCountries[destCountryNumber].head;
	graph->arrOfCountries[destCountryNumber].head = nodePtr;
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

Map::Map(vector<vector<int>> * initMapData) 
	: adjList(initMapData) 
{
	std::cout << "Initializing map..." << std::endl;

	int countryListSize = static_cast<int>(initMapData->size());

	int*** arrayOfPtrs = new int** [countryListSize];

	// initialize ptrs to country data
	for (int i = 0; i < countryListSize; i++)
	{
		arrayOfPtrs[i] = new int* [initMapData->at(i).size()];
	}
	for (int i = 0; i < countryListSize; i++)
	{
		for (int j = 0; j < static_cast<int>(initMapData->at(i).size()); j++)
		{
			arrayOfPtrs[i][j] = &initMapData->at(i).at(j);
		}
	}

	gameGraph  = createGraph(countryListSize); // Member variable initialized. Now accessible from map object.
	vector<Country*> countryVectorData;
	vector<Country*>* countryVectorPntr;

	for (int i = 0; i < static_cast<int>(initMapData->size()); i++)
	{
		countryVectorData.push_back(new Country(arrayOfPtrs[i][0], arrayOfPtrs[i][1]));
	}

	countryVectorPntr = &countryVectorData;
	countryVector = countryVectorPntr; // Member variable initialized. Now accessible from map object.

	/**/
	for (int i = 0; i < static_cast<int>(initMapData->size()); i++)
	{
		for (int j = 2; j < static_cast<int>(initMapData->at(i).size()); j++)
		{
			//cout << mapData.at(i).at(j) << " ";
			addEdge(gameGraph, *countryVectorData.at(i), *countryVectorData.at(*arrayOfPtrs[i][j]));
		}
	}

	//printGraph(gameGraph);

	delete[] arrayOfPtrs; // Must manage dangling pointers after
}

Map::~Map()
{
}


/*
	for (int i = 0; i < initMapData->size(); i++)
	{
		for (int j = 0; j < initMapData->at(i).size(); j++)
		{
			std::cout << *arrayOfPtrs[i][j] << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < countryVectorData.size(); i++)
	{
		std::cout << *countryVectorData.at(i)->getCountryNumber() << std::endl;
	}
*/