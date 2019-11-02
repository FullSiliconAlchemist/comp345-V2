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

public:
	vector<vector<int>> openFileAndStore(std::string* fileName);

	std::string* getFileName() const;

	void setFileName(std::string* newFile);

	MapLoader();
	MapLoader(std::string* fileName);
	~MapLoader();
};



