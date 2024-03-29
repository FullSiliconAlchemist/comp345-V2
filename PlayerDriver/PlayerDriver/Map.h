#pragma once
#include <string>
#include "Country.h"

class Map
{
public:

	struct CountryNode {
		int countryData;
		int continentData;
		CountryNode* next;
	};

	struct CountryList {
		//Country country; // Array of countries is created from CountryList struct
		CountryNode* head;
	};

	struct MapGraph {
		int numberOfCountries;
		CountryList* arrOfCountries;
	};

	CountryNode* newAdjencyListNode(int data); // Creates a new country node
	MapGraph* createGraph(int V); // Creates a new map

	void addEdge(MapGraph* graph, Country src, Country dest); // adds connections between countries

	void printGraph(MapGraph* graph);


	Map();
	~Map();

};
