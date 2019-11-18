#include "PlayerView.h"
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
