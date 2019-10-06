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
	
	/*
	*/
	Country * countryArray = new Country[10];

	cout << "-----CREATING COUNTRY OBJECTS DATA STRUCTURE-----" << endl;

	// Creating an array of non-defaulted constructors
	// This is done using an array of Country pointers and initializing a Country object in the memory addres being 
	// pointed to by each pointer in the array
	Country** arrayCountryPtrs = new Country*[5];
	for (int i = 0; i < 5; i++) {
		arrayCountryPtrs[i] = new Country(i, (rand() % 5)+1, (rand() % 10)+1); // Arbitrary initialization values
	}

	std::string newName = "Bobby";

	arrayCountryPtrs[1]->setName(newName);

	for (int i = 0; i < 5; i++) {	// Not adjusted for dynamic arrays for now
		cout << "\nCurrent country : " << arrayCountryPtrs[i]->getCountryNumber() << " - Current number of armies: " << arrayCountryPtrs[i]->getNumberOfArmies() << 
			" - Current continent belonging: " << arrayCountryPtrs[i]->getContinentNumber() << " - Country name: " << arrayCountryPtrs[i]->getName() << endl;
	}
	
	cout << "\n-----CREATING GRAPH MAP-----\n" << endl;

	// Grap Map initialization and testing

	int totalVertices = 5; // total number of countries
	Map newMap; // New map initialization default constructor

	Map::MapGraph *graph; // Graph pointer

	graph = newMap.createGraph(totalVertices);
	
	/*
	*/

	/*struct pointerMembers {
		int * ptrA;
		std::string * ptrB;
	};

	pointerMembers ptr;
	
	int a = 10;
	std::string thing = "Hello";

	ptr.ptrB = &thing;

	ptr.ptrA = &a;

	cout << "Ptr data memember of struct: " << *ptr.ptrB << "\n" << endl;*/

	newMap.addEdge(graph, *arrayCountryPtrs[0], *arrayCountryPtrs[(rand() % 5)]);
	newMap.addEdge(graph, *arrayCountryPtrs[1], *arrayCountryPtrs[(rand() % 5)]);
	newMap.addEdge(graph, *arrayCountryPtrs[2], *arrayCountryPtrs[(rand() % 5)]);
	newMap.addEdge(graph, *arrayCountryPtrs[3], *arrayCountryPtrs[(rand() % 5)]);
	newMap.addEdge(graph, *arrayCountryPtrs[4], *arrayCountryPtrs[(rand() % 5)]);

	newMap.printGraph(graph);

	delete graph;

	delete[] countryArray;
	
}

/**/

