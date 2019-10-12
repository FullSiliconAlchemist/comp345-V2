#pragma once

#include "../MapProject/Map.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

class MapLoader
{
	std::string * fileName;

public:
	Map * openFileAndStore(std::string * fileName);

	std::string * getFileName() const;

	void setFileName(std::string * newFile);

	MapLoader();
	MapLoader(std::string * fileName);
	~MapLoader();
};

