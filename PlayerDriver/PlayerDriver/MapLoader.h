#pragma once

#include "Map.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using std::vector;

class MapLoader
{
	std::string* fileName;
	bool isLoaded;
	vector<vector<int>>* loadedData;

public:
	bool openFileAndStore(std::string* fileName);

	std::string* getFileName() const;
	bool getIsLoaded() const;
	vector<vector<int>>* getLoadedData() const;

	void setFileName(std::string* newFile);
	void setIsLoaded(bool isTheMapLoaded);
	void setLoadedData(vector<vector<int>>* data);

	MapLoader();
	MapLoader(std::string* fileName);
	~MapLoader();
};



