// comp345-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Map.h"
#include "Country.h"

using namespace std;

int main()
{
	Country * countryArray = new Country[10];

	for (int i = 0; i < 10; i++) { // Not adjusted for dynamic arrays for now
		cout << "Current country continent: " << countryArray[i].getContinent() << "\nCurrent number of armies: " << countryArray[i].getNumberOfArmies();
		delete &countryArray[i];
	}

	int totalVertices = 4;
	Map newMap;

	Map::MapGraph *graph;
	Map * scondNewMap = new Map;

	graph = newMap.createGraph(totalVertices);

	newMap.addEdge(graph, 0, 1);
	newMap.addEdge(graph, 0, 2);
	newMap.addEdge(graph, 0, 3);
	newMap.addEdge(graph, 1, 3);
	newMap.addEdge(graph, 2, 3);

	cout << "Hello World!" << endl; 

	newMap.printGraph(graph);
}

