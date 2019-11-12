#include "Cards.h"
#include <string>
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
void Card::setAction()
{
	action = listOfActions + (rand() % 7);
}
void Card::setGood()
{
	good = listOfGoods + (rand() % 5);
}
void Card::setCost(int ct)
{
	*cost = ct;
}
int Card::getCost()const
{
	return *cost;
}

Card::Card() { //Creates a random card
	srand(time(0));//initilize random
	cost = new int(0);
	action = listOfActions + (rand() % 7);
	good = listOfGoods + (rand() % 5);
}
Card::Card(const Card& obj) { //copy contructor
	action = obj.action;
	good = obj.good;
	cost = new int(0);
	*cost = obj.getCost();
}

Card::~Card()
{
}

Card Deck::draw() {
	*numOfCards = *numOfCards - 1;
	return cardsList[*numOfCards];
}
Deck::Deck()
{
	numOfCards = new int(42);
	for (int i = 0; i < 42; i++) { //insures deck is full on random cards
		cardsList[i].setAction();
		cardsList[i].setGood();
	}

}

Deck::~Deck()
{
}

Card Hand::exchange(int slot, Card replacement) { //Returns desired card, slides cards to the left, recalulates prices
	Card cardToReturn = Card(currentHand[slot]);
	int i = slot;
	while ((i + 1) < 6) {
		currentHand[i] = currentHand[i + 1];
		currentHand[i].setCost(cost[i]);
		i++;
	}
	currentHand[5] = replacement;
	currentHand[5].setCost(cost[5]);

	return cardToReturn;
}
void Hand::showHand()const { //prints status of all cards
	for (int i = 0; i < 6; i++) {
		std::cout << "Card" << i << ": action: " << currentHand[i].getAction() << " good: " << currentHand[i].getGood() << " cost:" << currentHand[i].getCost() << "\n";
	}
}
Hand::Hand(Deck d) { //fills hand with cards from the deck

	for (int i = 0; i < 6; i++) {
		Card c = d.draw();
		currentHand[i] = Card(c);
		//currentHand[i].setAction();
		//currentHand[i].setGood();
		currentHand[i].setCost(cost[i]);
	}
}
Card Hand::getCardAt(int i) {
	return currentHand[i];
}

Hand::~Hand()
{
}