	#pragma once
#include <string>
#include <vector>
#include "Country.h"

using std::vector;

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
	bool checkGraphConnectivity();

	vector<Country*>* getCountryVector() const;
	vector<vector<int>>* getAdjacencyList() const;

	void setCountryVector(vector<Country*>* cntryVect);

	MapGraph* getMapGraph() const;

	Map();
	Map(vector<vector<int>>* initMap);
	~Map();

private:

	vector<Country*>* countryVector;
	vector<vector<int>>* adjList;
	MapGraph* gameGraph;
	bool isConnectedGraph;

};
