// MapDriver.cpp : This file contains the first 'main' function. Program execution begins here then runs projects sequentially from the top to the bottom and ends at the final project driver. 

#include "pch.h"
#include <string>
#include <iostream>
#include "Map.h"
#include "Country.h"

// Can include outer project files
#include "../PlayerDriver/Player.h"

/**/

using namespace std;

int main()
{
	bool gameRunning = true;
	Country country;
	
	/*
	*/
	Country * countryArray = new Country[10];

	Country** arrayCountryPtrs = new Country*[10];
	for (int i = 0; i < 10; i++) {
		arrayCountryPtrs[i] = new Country(i, i, (rand() % 5));
	}

	for (int i = 0; i < 10; i++) {	// Not adjusted for dynamic arrays for now
		cout << "\nCurrent country continent: " << countryArray[i].getContinentNumber() << " Current number of armies: " << countryArray[i].getNumberOfArmies() << endl;
	}
	
	cout << "\nCREATING GRAPH MAP\n" << endl;

	std::string newName = "Bobby";
	
	int totalVertices = 2;
	Map newMap;

	Map::MapGraph *graph;
	//Map * secondNewMap = new Map;

	countryArray[1].setName(newName);

	graph = newMap.createGraph(totalVertices);
	
	cout << countryArray[1].getName() << "\n" << endl;

	/*
	*/

	//for (int i = 0; i < 20; i++)
	//{
	//	cout << "\nRandom number generation test: " << rand() % 10 << endl;
	//}

	newMap.addEdge(graph, countryArray[0], countryArray[1]);
	newMap.addEdge(graph, countryArray[1], countryArray[2]);
	newMap.addEdge(graph, countryArray[0], countryArray[2]);

	newMap.printGraph(graph);

	delete graph;

	delete[] countryArray;
	
}

/**/

