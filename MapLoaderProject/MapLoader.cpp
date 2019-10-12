#include "pch.h"
#include "MapLoader.h"

using namespace std;

Map * MapLoader::openFileAndStore(std::string * fileName)
{
	cout << "Reading text file...\n" << endl;

	ifstream streamIn;

	streamIn.open(*fileName);

	if (!streamIn) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	std::string line;
	int lineCount = 0;
	std::vector< std::vector<int> > intList;

	while (getline(streamIn, line)) {

		// Must check values in line to see if the inputs are correct

		std::string lineToValidate = line;
			
		if (line.find_first_not_of("1234567890 ") != std::string::npos) {
			cerr << "Error on line: " << lineCount << "." << endl;
			cerr << "The line " << lineToValidate << " contains invalid data." << endl;
			cerr << "This text file is invalid. Please try with again with a different one." << endl;
			exit(1);
		}

		std::istringstream is(line);
		lineCount++;

		intList.push_back(
			std::vector<int>(std::istream_iterator<int>(is),
			std::istream_iterator<int>()));
	}

	streamIn.close();

	return new Map(intList);
}

std::string * MapLoader::getFileName() const
{
	return fileName;
}

void MapLoader::setFileName(std::string * newFile)
{
	fileName = newFile;
}

MapLoader::MapLoader()
{
}

MapLoader::MapLoader(std::string * fileName)
	: fileName(fileName)
{
}

MapLoader::~MapLoader()
{
}
