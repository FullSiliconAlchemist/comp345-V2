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
	int * ptrCountrySrc = src.getCountryNumber();;
	int srcCountryNumber = * ptrCountrySrc;

	int * ptrCountryDest = dest.getCountryNumber();
	int destCountryNumber = * ptrCountryDest;

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

// mapLoaderVect is a 2D vector which contains country, continent and adjacency information for evry country
Country ** Map::initiateCountryDataStructure(std::vector < std::vector <int> > mapLoaderVect)
{
	int vectorSize = mapLoaderVect.size();
	setTotalVertices(&vectorSize);
	
	Country ** cntryPtrsHolder = new Country *[*getTotalVertices()];
	int *** intPtrsHolder = new int **[*getTotalVertices()];
	int ** intHolder = new int *[*getTotalVertices()];

	// Initializing pointers to datastructures used to initialize countries
	// vector should resemble the following:
	/*
		Where column 1 is the country number, column 2 is the continent number
		and the rest of the columns is the countries column 1 is adjacent to.

		0 0 1 2 3
		1 0 2 3
		2 1 3 
		3 2 1
	*/

	// initialize data manipulation structures to arr[][3] (for countryNum, continentNum, Armies)
	for (int i = 0; i < *getTotalVertices(); i++)
	{
		intPtrsHolder[i] = new int * [getCountryArgs()];
		intHolder[i] = new int[getCountryArgs()];
	}

	for (int j = 0; j < *getTotalVertices(); j++)
	{
		setCountryNum(&mapLoaderVect.at(j).at(0));
		setContinentNum(&mapLoaderVect.at(j).at(1));

		for (int k = 0; k < getCountryArgs(); k++)
		{
			if (k == 0)
			{
				intHolder[j][k] = *getCountryNum();
			}
			else if (k == 1)
			{
				intHolder[j][k] = *getContinentNum();
			}
		}
	}

	// Might be some dangling pointers around

	for (int u = 0; u < *getTotalVertices(); u++)
	{
		cntryPtrsHolder[u] = new Country();

		for (int v = 0; v < getCountryArgs(); v++)
		{
			intPtrsHolder[u][v] = &intHolder[u][v];
		}

		for (int w = 0; w < getCountryArgs(); w++)
		{
			if (w == 0)
			{
				cntryPtrsHolder[u]->setCountry(intPtrsHolder[u][w]);
			}
			else if (w == 1)
			{
				cntryPtrsHolder[u]->setContinent(intPtrsHolder[u][w]);
			}
		}
	}

	setArrayCtryPtrs(cntryPtrsHolder);
	return getArrayOfCtryPtrs();
}

Map::Map()
{
}

Map::Map(std::vector <std::vector <int>> mapLoaderVector)
{
	Map::MapGraph * graph = createGraph(mapLoaderVector.size());
	Country ** arrayOfInitCtrs = initiateCountryDataStructure(mapLoaderVector);

	for (int i = 0; i < mapLoaderVector.size(); i++)
	{
		for (int j = 2; j < mapLoaderVector.at(i).size(); j++)
		{
 			addEdge(graph, *arrayOfInitCtrs[i], *arrayOfInitCtrs[mapLoaderVector.at(i).at(j)]);
		}
	}

	printGraph(graph);
}

Map::~Map()
{
}

int Map::getCountryArgs() const
{
	return COUNTRY_ARGS;
}

int * Map::getCountryNum() const
{
	return countryNum;
}

int * Map::getContinentNum() const
{
	return continentNum;
}

int * Map::getArmiesNum() const
{
	return armiesNum;
}

void Map::setCountryNum(int * newCountryNum)
{
	countryNum = newCountryNum;
}

void Map::setContinentNum(int * newContinentNum)
{
	continentNum = newContinentNum;
}

void Map::setArmiesNum(int * newArmiesNum)
{
	armiesNum = newArmiesNum;
}

int * Map::getTotalVertices() const
{
	return totalVertices;
}

Country ** Map::getArrayOfCtryPtrs() const
{
	return arrayCtryPtrs;
}

int *** Map::getArrayOfIntPtrs() const
{
	return arrayOfIntPtrs;
}

int ** Map::getArrayOfInts() const
{
	return arrayOfInts;
}

void Map::setTotalVertices(int * newVertices)
{
	totalVertices = newVertices;
}

void Map::setArrayCtryPtrs(Country ** newCtryPtr)
{
	arrayCtryPtrs = newCtryPtr;
}

void Map::setArrayOfIntPtrs(int *** newArrIntPtrs)
{
	arrayOfIntPtrs = newArrIntPtrs;
}

void Map::setArrayOfInts(int ** newArrayInts)
{
	arrayOfInts = newArrayInts;
}