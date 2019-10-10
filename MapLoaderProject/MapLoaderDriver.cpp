// MapLoaderProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Reading text file..." << endl; 

	int sum = 0;
	int x;
	ifstream inFile;

	inFile.open("C:\\tmp\\datafile.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	while (inFile >> x) {
		sum = sum + x;
	}

	inFile.close();

	cout << "Sum equals to: " << sum;
}

