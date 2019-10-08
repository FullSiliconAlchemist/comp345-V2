#include "Cards.h"
#include <string>
#include <cstdlib>
#include <time.h>  
#include <iostream>
#include <array>
std::string Card::getAction() const
{
	return *action;
}
std::string Card::getGood() const
{
	return *good;
}
void Card::setAction(std::string ac)
{
	*action = ac;
}
void Card::setGood(std::string gd)
{
	*good = gd;
}

Card::Card() {
	srand(time(NULL));//initilize random

	action = listOfActions + (rand() % 5);
	good = listOfGoods + (rand() % 5);
}


Card Deck::draw() {
	numOfCards--;
	//Card x = *(cardsList + numOfCards);
	//std::string c = cardsList + numOfCards;
	return cardsList[numOfCards];
}
Deck::Deck()
{
	int deckSize = 42;
	numOfCards = deckSize;
	
}