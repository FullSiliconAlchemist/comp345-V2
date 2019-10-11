// MapDriver.cpp : This file contains the first 'main' function. Program execution begins here then runs projects sequentially from the top to the bottom and ends at the final project driver. 

#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include "Map.h"
#include "Country.h"

// Can include outer project files
#include "../PlayerDriver/Player.h"

/**/

using namespace std;

int main()
{	
	std::cout << "\n-----CREATING GRAPH MAP-----\n" << endl;

	std::cout << "-----CREATING COUNTRY OBJECTS DATA STRUCTURE-----" << endl;

	// Creating an array of non-defaulted constructors
	// This is done using an array of Country pointers and initializing a Country object in the memory addres being 
	// pointed to by each pointer in the array

	// Grap Map initialization and testing

	bool gameRunning = true;

	int totalVertices; // total number of countries
	const static int COUNTRY_ARGS = 3;
	Map newMap; // New map initialization default constructor

	Map::MapGraph *graph; // Graph pointer

	Country ** arrayCtryPtrs; // Array of Country pointer objects
	int *** arrayOfIntsPtrs; // Array of pointers
	int ** arrayOfInts; // 2D array of integers

	int countryNum;
	int continentNum;
	int armiesNum;

	char correctness;

	std::vector<std::vector<int>> testVector = {
		{0, 0, 1, 12},
		{1, 0, 0, 2},
		{2, 0, 1, 3, 13},
		{3, 0, 2, 4, 5, 6}
	};

	arrayCtryPtrs = newMap.initiateCountryDataStructure(testVector);
	
	int someNum;

	for (int i = 0; i < testVector.size(); i++)
	{
		cout << "Printing country: " << *arrayCtryPtrs[i]->getCountryNumber() << endl;
		cout << "Printing continent: " << *arrayCtryPtrs[i]->getContinentNumber() << endl;
	}

	/*
	while (gameRunning) 
	{
		std::cout << "Hello, how many countries do you need?" << endl;

		std::cin >> totalVertices; // 1

		graph = newMap.createGraph(totalVertices); // create graph

		arrayCtryPtrs = new Country * [totalVertices];
		arrayOfIntsPtrs = new int ** [totalVertices];			// Array of pointers just makes new memory addresses for each number needed for Country obj
		arrayOfInts = new int * [totalVertices];				// Array of totalVertices number of country objects with 3 or more rows each for the necessary data

		for (int u = 0; u < totalVertices; u++)					// 2D array instantiation
		{
			arrayOfInts[u] = new int[COUNTRY_ARGS];				// Each slot is an object with 3 data members
		}

		for (int w = 0; w < totalVertices; w++)
		{
			arrayOfIntsPtrs[w] = new int * [COUNTRY_ARGS];		// Same here but with pointers
		}

		std::cout << "Great, now define your countries please." << endl;
		std::cout << "Which continent is this coutry from?" << endl;

		for (int i = 0; i < totalVertices; i++) {

			std::cout << "Defining country: " << i << endl;

			countryNum = i;

			std::cout << "Country continent: " << endl;

			std::cin >> continentNum;

			std::cout << "Armies given: " << endl;
			std::cin >> armiesNum;
			
			// Array of integers so that each integer has it's own memory address
			// and there won't be repeating values for countryNum, continentNum, armiesNum

			for (int a = 0; a < COUNTRY_ARGS; a++)
			{
				if (a == 0)
				{
					arrayOfInts[i][a] = countryNum;
				}
				else if (a == 1)
				{
					arrayOfInts[i][a] = continentNum;
				}
				else {
					arrayOfInts[i][a] = armiesNum;
				}
			}

		}

		for (int k = 0; k < totalVertices; k++)
		{
			arrayCtryPtrs[k] = new Country();

			for (int v = 0; v < COUNTRY_ARGS; v++)
			{
				arrayOfIntsPtrs[k][v] = &arrayOfInts[k][v];
			}

			for (int b = 0; b < COUNTRY_ARGS; b++)
			{
				if (b == 0)
				{
					arrayCtryPtrs[k]->setCountry(arrayOfIntsPtrs[k][b]);
				}
				else if (b == 1)
				{
					arrayCtryPtrs[k]->setContinent(arrayOfIntsPtrs[k][b]);
				}
				else {
					arrayCtryPtrs[k]->setArmies(arrayOfIntsPtrs[k][b]);
				}
			}
		}

		std::cout << "\nAwesome, countries defined." << endl;
		std::cout << "Verify the correctness of these countries plz." << endl;

		for (int j = 0; j < totalVertices; j++) {
			std::cout << "\nCountry : " << * arrayCtryPtrs[j]->getCountryNumber() << "\nNumber of armies: " << * arrayCtryPtrs[j]->getNumberOfArmies() <<
				"\nContinent belonging: " << * arrayCtryPtrs[j]->getContinentNumber() << endl;
		}

		std::cout << "\nCreating edges..." << endl;
		std::cout << "" << endl;

		for (int i = 0; i < totalVertices; i++)
		{
			newMap.addEdge(graph, * arrayCtryPtrs[i], * arrayCtryPtrs[i]);
		}

		newMap.printGraph(graph);
		delete graph;

		std::cout << "\nDoes this seem right? (y/n)" << endl;
		std::cin >> correctness;

		if (correctness == 'y')
		{
			delete[] arrayCtryPtrs;
			gameRunning = !gameRunning;
		}
	}
	*/

}

