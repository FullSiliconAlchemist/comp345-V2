#include "CardsFactory.h"
#include <time.h>
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
const std::string* Card::getRandAction() const {
	const std::string* randAction = listOfActions + (rand() % 7);
	return randAction;
}

Card::Card() { //Creates a random card//initilize random
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


oneActionCard::oneActionCard() {

}
void oneActionCard::setAction() {

	{
		action = listOfSingleActions + (rand() % 4);
	}
}
twoActionCard::twoActionCard() {

}
void twoActionCard::setAction() {

	{
		action = listOfDoubleActions + (rand() % 2);
	}
}