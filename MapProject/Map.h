#pragma once
#include <string>
#include <vector>
#include "Country.h"

class Map
{
	const static int COUNTRY_ARGS = 2; // not pointer - set to 2 assuming there will only be countryNum and continentNum

	int * totalCountryVertices;
	int * totalContinentVertices;

	Country ** arrayCtryPtrs;

	std::vector<Country*> arrayCntntPtrs; // also not a pointer need to refactor

	int *** arrayOfIntPtrs;
	int ** arrayOfInts;

	// Possibly not necessary
	int * countryNum;
	int * continentNum;
	int * armiesNum;

public:

	int getCountryArgs() const;

	int * getCountryNum() const;
	int * getContinentNum() const;
	int * getArmiesNum() const;

	void setCountryNum(int * newCountryNum);
	void setContinentNum(int * newContinentNum);
	void setArmiesNum(int * newArmiesNum);

	int * getTotalCountryVertices() const;
	int * getTotalContinentVertices() const;

	Country ** getArrayOfCtryPtrs() const;
	std::vector<Country*> getArrayOfCntntPtrs() const;

	int *** getArrayOfIntPtrs() const;
	int ** getArrayOfInts() const;

	void setTotalCountryVertices(int * newVertices);
	void setTotalContinentVertices(int * newVertices);

	void setArrayCtryPtrs(Country ** newCtryPtr);
	void setArrayCntntPtrs(std::vector<Country*> newCntntPtr);

	void setArrayOfIntPtrs(int *** newArrIntPtrs);
	void setArrayOfInts(int ** newArrayInts);

	struct CountryNode {
		int countryData;
		int continentData;
		CountryNode * next;
	};

	struct CountryList {
		//Country country; // Array of countries is created from CountryList struct
		CountryNode * head;
	};

	struct MapGraph {
		int numberOfCountries;
		CountryList *arrOfCountries;
	};

	CountryNode* newAdjencyListNode(int data); // Creates a new country node
	MapGraph* createGraph(int V); // Creates a new map

	void addEdgeCountry(MapGraph *graph, Country src, Country dest); // adds connections between countries

	void addEdgeContinent(MapGraph * graph, Country src, Country dest);

	void printGraph(MapGraph* graph);

	Country ** initializeCountryDataStructure(std::vector< std::vector <int> > mapLoaderVect);
	std::vector<Country*> initializeContinentDataStructure(std::vector <std::vector <int>> mapLoaderVector);

	MapGraph * createCountryGraph(std::vector<std::vector<int>>);
	MapGraph * createContinentGraph(std::vector<std::vector<int>>);

	Map();
	Map(std::vector<std::vector<int>>);
	~Map();

};


