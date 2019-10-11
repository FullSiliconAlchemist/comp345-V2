// MapLoaderProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

#include "../MapProject/Map.h"

using namespace std;

int main()
{
    cout << "Reading text file..." << endl; 

	ifstream streamIn;

	// Need to create a map function which will create the Arrays necessary to 
	// store the map data from the map loader

	streamIn.open("C:\\tmp\\datafile.txt");

	if (!streamIn) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}
	
	std::string line;
	std::vector< std::vector<int> > intList;

	int *** countryStructure;  // will hold ragged array of integers

	std::vector<std::vector<int>> countryVector; // Vector holds ragged array of integers 

	while (getline(streamIn, line)) { // Reads file line by line and stores integers in an array

		std::istringstream is (line);
		
		intList.push_back(
			std::vector<int>(std::istream_iterator<int>(is),
							 std::istream_iterator<int>() ) );
	}

	cout << intList.size() << endl;

	for (int a = 0; a < intList.size(); a++)
	{
		//countryStructure[a] = new int * [intList.at(a).size()];
		//cout << intList.at(a).size() << " ";
	}

	for (int i = 0; i < intList.size(); i++)
	{	
		for (int j = 0; j < intList.at(i).size(); j++)
		{
			//countryStructure[i][j] = &intList.at(i).at(j);
		}
	}

	for (int k = 0; k < intList.size(); k++)
	{
		for (int l = 0; l < intList.at(k).size(); l++)
		{
			cout << intList[k][l] << " ";
		}
		std::cout << std::endl;
	}
	
	/*while (inFile.getline(buffer, sizeof(buffer)))
	{
		cout << buffer << endl;

		while (buffer)
		{

		}

		count++;
	}*/

	streamIn.close();

}

