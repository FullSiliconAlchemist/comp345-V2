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

	// Graph methods
	CountryNode* newAdjencyListNode(int data); // Creates a new country node
	MapGraph* createGraph(int V); // Creates a new map
	void addEdge(MapGraph* graph, Country src, Country dest); // adds connections between countries
	void printGraph(MapGraph* graph);
	bool checkGraphConnectivity();

	// Map methods
	vector<vector<int>>* getAdjacencyList() const;
	MapGraph* getMapGraph() const;
	int * getTotalCountries() const;
	Country*** getCountryArray() const; // This right here is a headache

	void setCountryArray(Country*** cntryArr); // This too

	Map();
	Map(vector<vector<int>>* initMap);
	~Map();

private:

	vector<vector<int>>* adjList;
	int* totalCountries;
	MapGraph* gameGraph;
	bool isConnectedGraph;

	Country*** countryArray;

};
