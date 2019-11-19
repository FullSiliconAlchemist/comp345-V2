#include "GameView.h"
#include <iostream>
PlayerView::PlayerView()
{
}
PlayerView::PlayerView(Player* p)
{
	_subject = p;
	_subject->attach(this);
}

PlayerView::~PlayerView()
{
	_subject->detach(this);
}
void PlayerView::update(Card c) {
	display(c);
}
void PlayerView::display(Card c) {
	std::cout << "OBSERVER: Player " << _subject->GetId() << " Has " << _subject->GetGoldenCoins() << " coins and has picked up the card with the action " << c.getAction() << std::endl;
	std::cout << "OBSERVER: That card costs " << c.getCost() << " which will leave Player " << _subject->GetId() << " with " 
		<< _subject->GetGoldenCoins() - c.getCost() << " coins" << std::endl;
	
}

using std::cout;
using std::endl;

MapViewer::MapViewer()
{
	cout << "MapViewer object instantiated without setting a subject. You may use a setter, or instantiate using specific constructor." << endl;
	_Subject = NULL;
}

MapViewer::MapViewer(Map* s)
{
	_Subject = s;
	_Subject->Attach(this);
}

MapViewer::~MapViewer()
{
	_Subject->Detach(this);
}

void MapViewer::Update()
{
	this->display();
}

void MapViewer::display()
{
	// Call the desired function to display the map's current state
	// Shows each player's countries
	cout << "\n|||||||||| GAME STATISTICS ||||||||||\n" << endl;
	int players = *_Subject->getTotalPlayers();
	for (int i = 0; i < players; i++)
	{
		cout << "Player " << i << " stats: ";
		for (int j = 0; j < *_Subject->getTotalCountries(); j++)
		{
			int armiesPresent = *_Subject->getCountryArray()[j]->getRefactoredArmies()[i];
			int cityPresent = *_Subject->getCountryArray()[j]->getCity();
			if (armiesPresent > 0)
				cout << "\n\n\t[ Country #" << j << " has " << armiesPresent << " armies ]";
			
			if (cityPresent)
				cout << " \n\n\t[ Player has a city present on country " << j << " ]";

		}
		cout << "\n" << endl;
	}
}

