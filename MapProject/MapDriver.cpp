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
	bool gameRunning = true;
	
	/*
	*/
	Country * countryArray = new Country[10];

	std::cout << "-----CREATING COUNTRY OBJECTS DATA STRUCTURE-----" << endl;

	// Creating an array of non-defaulted constructors
	// This is done using an array of Country pointers and initializing a Country object in the memory addres being 
	// pointed to by each pointer in the array

	std::cout << "\n-----CREATING GRAPH MAP-----\n" << endl;

	// Grap Map initialization and testing

	int totalVertices; // total number of countries
	Map newMap; // New map initialization default constructor

	Map::MapGraph *graph; // Graph pointer
	//Country ** arrayCountryPtrs = new Country * [2] {new Country(a, b, c), new Country(d, e, f)};
	Country ** arrayCtryPtrs;
	int *** arrayOfIntsPtrs; // Array of pointers
	int ** arrayOfInts; // 2D array
	//std::vector<Country> arrCountries;

	/*for (int i = 0; i < 2; i++) 
	{
		int a = i;
		int b = i + 5;
		arrayCountryPtrs[i]->setCountry(a);
		arrayCountryPtrs[i]->setContinent(b);
		int * ptr = arrayCountryPtrs[i]->getContinentNumber();

		std::cout << * ptr << endl;
	}*/

	int countryNum;
	int continentNum;
	int armiesNum;

	char correctness;

	while (gameRunning) 
	{
		std::cout << "Hello, how many countries do you need?" << endl;
		std::cin >> totalVertices;

		graph = newMap.createGraph(totalVertices);
		arrayCtryPtrs = new Country * [totalVertices];
		arrayOfIntsPtrs = new int ** [totalVertices]; // Array of pointers just makes new memory addresses for each number needed for Country obj
		arrayOfInts = new int * [totalVertices]; // Array of totalVertices number of country objects with 3 or more rows each for the necessary data

		for (int u = 0; u < totalVertices; u++) // 2D array instantiation
		{
			arrayOfInts[u] = new int[3]; // Each slot is an object with 3 data members
		}

		for (int w = 0; w < totalVertices; w++)
		{
			arrayOfIntsPtrs[w] = new int * [3]; // Same here but with pointers
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

			for (int a = 0; a < 3; a++)
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

			for (int v = 0; v < 3; v++)
			{
				arrayOfIntsPtrs[k][v] = &arrayOfInts[k][v];
			}

			for (int b = 0; b < 3; b++)
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
	
	/*

	for (int i = 0; i < 5; i++)
	{
		newMap.addEdge(graph, *arrayCountryPtrs[i], *arrayCountryPtrs[i]);

		cout << "Country number: " << i << " " << arrayCountryPtrs[i]->getContinentNumber() << " " << arrayCountryPtrs[i]->getCountryNumber() << endl;
	}
	
	newMap.printGraph(graph);
	delete graph;


	*/

}

/**/

