#include "pch.h"
#include "Map.h"
#include <cstddef>;
#include <iostream>;

Map::CountryNode* Map::newAdjencyListNode(int data)
{
	CountryNode *nodePtr = new CountryNode;
	nodePtr->countryNumber = data;
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

void Map::addEdge(MapGraph * graph, int src, int dest)
{
	// Create node pointer which points to a new node which in turn
	CountryNode *nodePtr = newAdjencyListNode(dest);
	nodePtr->next = graph->arrOfCountries[src].head;

	graph->arrOfCountries[src].head = nodePtr;
	nodePtr = newAdjencyListNode(src);

	nodePtr->next = graph->arrOfCountries[dest].head;
	graph->arrOfCountries[dest].head = nodePtr;
}

void Map::printGraph(MapGraph* graph)
{
	for (int i = 0; i < graph->numberOfCountries; i++)
	{
		CountryNode *root = graph->arrOfCountries[i].head;
		std::cout << "Adjency list of vertex: " << i << std::endl;
		while (root != NULL)
		{
			std::cout << " -> " << root->countryNumber;
			root = root->next;
		}
		std::cout << std::endl;
	}
}

inline int Map::getNumberOfCountries() const
{
	return numberOfCountries;
}

inline int Map::getNumberOfContinents() const
{
	return numberOfContinents;
}

Map::Map()
{
}

Map::~Map()
{
}
