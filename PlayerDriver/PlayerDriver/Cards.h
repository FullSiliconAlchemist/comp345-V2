#pragma once
#include <string>
#include "CardsFactory.h"

class Deck {
	Card cardsList[42];
	int* numOfCards;
public:
	Card draw();
	Deck();
	~Deck();
};

class Hand {
	Card currentHand[6];
	
public:
	int const cost[6] = { 0, 1, 1, 2, 2, 3 };
	Card exchange(int slot, Card replacement);
	Card getCardAt(int i);
	void showHand() const;
	Hand(Deck d);
	~Hand();
};