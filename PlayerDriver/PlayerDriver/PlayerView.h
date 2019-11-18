#pragma once
#include "Player.h"
class PlayerView: public ObserverPlayer {
public:
	PlayerView();
	PlayerView(Player* p);
	~PlayerView();
	void update();
	void display();
private:
	Player* _subject;
};
