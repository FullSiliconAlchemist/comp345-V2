
#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

#include "../MapProject/Map.h"
#include "../MapProject/Map.cpp"
#include "../MapProject/Country.h"
#include "../MapProject/Country.cpp"
#include "../MapLoaderProject/MapLoader.h"
#include "../MapLoaderProject/MapLoader.cpp"

int main()
{
	std::cout << "Hello, friend." << std::endl;
	std::cout << "Welcome to the best damn game you've ever laid eyes on." << std::endl;

	std::string mapPath = "C:\\tmp\\datafile - Copy.txt";
	MapLoader * newMap = new MapLoader(&mapPath);

	newMap->openFileAndStore(newMap->getFileName());
}
