#include "Cards.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>  
#include <iostream>
std::string Card::getAction() const
{
	return *action;
}
std::string Card::getGood() const
{
	return *good;
}


Card::Card() {

	srand(time(NULL));//initilize random

	action = listOfActions + (rand() % 5);
	good = listOfGoods + (rand() % 5);
}
Card::Card (const Card& c) {
	*action = c.getAction();
	*good = c.getGood();
}

/*
Card Deck::draw() {
	Card cardToReturn = Card(cardsList.back());
	cardsList.pop_back();
	return cardToReturn;
}

int Deck::sizeOfDeck() {
	return cardsList.size();
}
Deck::Deck()
{
	int deckSize = 42;
	for (int i = 0; i < deckSize; i++) {
		Card c;
		//std::cout << "Adding Card" << c.getAction();
		cardsList.push_back(c);
	}

}