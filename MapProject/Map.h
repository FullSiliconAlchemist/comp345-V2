#pragma once
#include <string>
#include <vector>
#include "Country.h"

class Map
{
	const static int COUNTRY_ARGS = 2; // not pointer - set to 2 assuming there will only be countryNum and continentNum
	int * totalVertices;
	Country ** arrayCtryPtrs;
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

	int * getTotalVertices() const;
	Country ** getArrayOfCtryPtrs() const;
	int *** getArrayOfIntPtrs() const;
	int ** getArrayOfInts() const;

	void setTotalVertices(int * newVertices);
	void setArrayCtryPtrs(Country ** newCtryPtr);
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

	void addEdge(MapGraph *graph, Country src, Country dest); // adds connections between countries

	void printGraph(MapGraph* graph);

	Country ** initiateCountryDataStructure(std::vector< std::vector <int> > mapLoaderVect);

	Map();
	Map(std::vector<std::vector<int>>);
	~Map();

};


