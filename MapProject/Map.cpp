#include "pch.h"
#include "Map.h"
#include <cstddef>;
#include <iostream>;

// Map Class functions

Map::CountryNode * Map::newAdjencyListNode(int data)
{
	CountryNode *nodePtr = new CountryNode;
	nodePtr->countryData = data;
	nodePtr->next = NULL;
	return nodePtr;
}

Map::MapGraph * Map::createGraph(int V)
{
	MapGraph *graph = new MapGraph;
	// Member numberOfCountries pointed to by graph pointer
	graph->numberOfCountries = V;
	graph->arrOfCountries = new CountryList[V];
	for (int i = 0; i < V; i++) {
		graph->arrOfCountries[i].head = NULL;
	}
	return graph;
}

void Map::addEdge(MapGraph * graph, Country src, Country dest) // Changing the src and dest types to Country objects
{
	int srcCountryNumber = src.getCountryNumber();
	int destCountryNumber = dest.getCountryNumber();

	// Create node pointer which points to a new node which in turn
	CountryNode *nodePtr = newAdjencyListNode(destCountryNumber);
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
		CountryNode *root = graph->arrOfCountries[i].head;
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
}

Map::~Map()
{
}

