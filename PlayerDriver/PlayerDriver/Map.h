	#pragma once
#include <string>
#include <vector>
#include "Country.h"
#include "Player.h"

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

	// Score calculation method
	int computePlayerScores(int playerID);

	// Map methods
	vector<vector<int>>* getAdjacencyList() const;
	MapGraph* getMapGraph() const;
	int * getTotalCountries() const;
	Country** getCountryArray() const; // This right here is a headache
	void displayPossibleMoves(Country* countryToTake);
	bool getIsValidMap() const;
	bool moveIsLegal(Country* countryStart, Country* countryDest, int moves); // Checks adjacency between two countries to see if there is a path between them

	void setCountryArray(Country** cntryArr); // This too

	Map();
	Map(vector<vector<int>>* initMap);
	~Map();

private:

	vector<vector<int>>* adjList;
	int* totalCountries;
	MapGraph* gameGraph;
	bool isConnectedGraph;
	Country** countryArray;
	// Vector of country pointer used to be here instead of country array of pointers.
	// When setting the countryVector pointer to point to the reference of the created vector in the map constructor
	// I was not able to retain the data that the pointers were pointing to, although countryVector was pointing to the proper address.

};
