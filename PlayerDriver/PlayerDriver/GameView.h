#pragma once
#include "Player.h"
#include "CardsFactory.h"
#include "Map.h"

class PlayerView: public ObserverPlayer {
public:
	PlayerView();
	PlayerView(Player* p);
	~PlayerView();
	void update(Card c);
	void display(Card c);
private:
	Player* _subject;
};

// View part of the MVC model, this will update the view and display the scores, etc of the game
class MapViewer : public GameStatisticsObserver
{
public:
	MapViewer();
	MapViewer(Map* s);
	~MapViewer();

	void Update();
	void display();

private:
	Map* _Subject;
};

