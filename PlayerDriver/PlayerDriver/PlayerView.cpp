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
void PlayerView::update() {
	display();
}
void PlayerView::display() {
	_subject->GetId;
	
}
