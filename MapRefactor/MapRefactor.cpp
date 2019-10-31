// MapRefactor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\MapRefactor\pch.h"

#include <iostream>

#include "Map.h"
#include "Country.h"
#include "MapLoader.h"

int main()
{
	std::cout << "Hello, friend." << std::endl;
	std::cout << "Welcome to the best damn game you've ever laid eyes on." << std::endl;

	std::string mapPath = "C:\\tmp\\dataFile.txt";

	MapLoader * newMap = new MapLoader(&mapPath);

	newMap->openFileAndStore(newMap->getFileName());
}
