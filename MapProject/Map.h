#pragma once
#pragma once
class Map
{
public:

	class CountryNode {
	public:
		int countryNumber;
		int continentNumber;
		CountryNode *next;
	};

	class CountryList {
	public:
		CountryNode *head;
	};

	class MapGraph {
	public:
		int numberOfCountries;
		CountryList *arrOfCountries;
	};

	CountryNode* newAdjencyListNode(int data);
	MapGraph* createGraph(int V);
	void addEdge(MapGraph *graph, int src, int dest);
	void printGraph(MapGraph* graph);

	inline int getNumberOfCountries() const;

	inline int getNumberOfContinents() const;

	Map();
	~Map();

private:

	int numberOfCountries;
	int numberOfContinents;

};
