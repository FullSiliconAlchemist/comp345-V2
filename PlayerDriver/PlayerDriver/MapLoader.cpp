#include "MapLoader.h"

using namespace std;

bool MapLoader::openFileAndStore(std::string* fileName)
{
	cout << "Reading text file...\n" << endl;

	ifstream streamIn;

	cout << *fileName << endl;

	streamIn.open(*fileName);

	if (!streamIn) {
		cerr << "Unable to open file " << *fileName << endl;
		cerr << "File doesn't exist, or name is invalid. Please try again." << endl;
		setIsLoaded(false);
		return false;
		// exit(1);   // call system to stop
	}

	std::string line;
	int lineCount = 0;
	std::vector<std::vector<int>> intList;
	std::vector<std::vector<int>>* intListPntr;

	while (getline(streamIn, line)) {

		// Must check values in line to see if the inputs are correct

		std::string lineToValidate = line;

		if (line.find_first_not_of("1234567890 ") != std::string::npos) {
			cerr << "Error on line: " << lineCount << "." << endl;
			cerr << "The line " << lineToValidate << " contains invalid data." << endl;
			cerr << "This text file is invalid. Data may be corrupted. Please try with again with a different one." << endl;
			setIsLoaded(false);
			return false;
			// exit(1);
		}

		std::istringstream is(line);
		lineCount++;

		intList.push_back(
			std::vector<int>(std::istream_iterator<int>(is),
				std::istream_iterator<int>()));
	}

	cout << "File has been loaded succesfuly!" << endl;
	setIsLoaded(true);
	intListPntr = &intList;

	setLoadedData(intListPntr);
	streamIn.close();

	return true;
}

std::string* MapLoader::getFileName() const
{
	return fileName;
}

bool MapLoader::getIsLoaded() const
{
	return isLoaded;
}

vector<vector<int>>* MapLoader::getLoadedData() const
{
	return loadedData;
}

void MapLoader::setFileName(std::string* newFile)
{
	fileName = newFile;
}

void MapLoader::setIsLoaded(bool isTheMapLoaded)
{
	isLoaded = isTheMapLoaded;
}

void MapLoader::setLoadedData(vector<vector<int>>* data)
{
	loadedData = data;
}

MapLoader::MapLoader()
{
}

MapLoader::MapLoader(std::string* fileName)
	: fileName(fileName)
{
}

MapLoader::~MapLoader()
{
}
