#include "pch.h"
#include "MapLoader.h"

using namespace std;

//Map MapLoader::openFileAndStore(std::string * fileName)
//{
//	cout << "Reading text file..." << endl;
//
//	ifstream streamIn;
//
//	streamIn.open(*fileName);
//
//	if (!streamIn) {
//		cerr << "Unable to open file datafile.txt";
//		exit(1);   // call system to stop
//	}
//
//	std::string line;
//	std::vector< std::vector<int> > intList;
//
//	while (getline(streamIn, line)) {
//
//		std::istringstream is(line);
//
//		intList.push_back(
//			std::vector<int>(std::istream_iterator<int>(is),
//				std::istream_iterator<int>()));
//	}
//
//
//
//	return Map();
//}

std::string * MapLoader::getFileName() const
{
	return fileName;
}

MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}
