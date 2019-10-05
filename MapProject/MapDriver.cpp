// MapDriver.cpp : This file contains the first 'main' function. Program execution begins here then runs projects sequentially from the top to the bottom and ends at the final project driver. 



#include "pch.h"
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
	

	Country * countryArray = new Country[10];

	for (int i = 0; i < 10; i++) {	// Not adjusted for dynamic arrays for now
		cout << "\nCurrent country continent: " << countryArray[i].getContinentNumber() << "Current number of armies: " << countryArray[i].getNumberOfArmies() << endl;
	}

	cout << "CREATING GRAPH MAP\n" << endl;

	int totalVertices = 10;
	Map newMap;

	Map::MapGraph *graph;
	Map * scondNewMap = new Map;

	graph = newMap.createGraph(totalVertices);
	


	countryArray[rand() / 10].setName("Bobby");

	for (int j = 0; j < totalVertices; j++)
	{
		newMap.addEdge(graph, countryArray[(rand() / 10)], countryArray[rand() / 10]);
	}

	newMap.printGraph(graph);

	delete[] countryArray;
}

/**/

