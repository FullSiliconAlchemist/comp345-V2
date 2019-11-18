#pragma once
#include "Player.h"
#include "Cards.h"
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
