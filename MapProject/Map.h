#pragma once
#include <string>
#include "Country.h"

class Map
{
public:

	struct CountryNode {
		// Country country;
		int data;
		CountryNode * next;
	};

	struct CountryList {
		CountryNode *head;
	};

	struct MapGraph {
		int numberOfCountries;
		CountryList *arrOfCountries;
	};

	CountryNode* newAdjencyListNode(int data); // Creates a new country node
	MapGraph* createGraph(int V); // Creates a new map

	void addEdge(MapGraph *graph, int src, int dest); // adds connections between countries

	void printGraph(MapGraph* graph);

	inline int getNumberOfCountries() const {
		return numberOfCountries;
	}

	inline int getNumberOfContinents() const {
		return numberOfContinents;
	}

	Map();
	~Map();

private:

	int numberOfCountries;
	int numberOfContinents;
	int * continentsArray[]; // Pointer to an array of continents

};


