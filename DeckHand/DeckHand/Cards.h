#pragma once
#include <string>
#include <vector>

class Card {
	std::string *action;
	std::string *good;
	std::string listOfActions[6] = { "newArmy", "moveArmy", "moveOverLandOrWater", "city", "destroyArmy", "combo" };
	std::string listOfGoods[6] = { "crystal", "stone", "iron", "wood", "veggies", "wild" };
public:
	std::string getAction()const;
	std::string getGood() const;
	void setAction(std::string ac);
	void setGood(std::string gd);
	//Card(const Card& c);
	Card();
	//~Card();;
};

class Deck {


public:
	Card draw();
	Deck();
	Card cardsList[42];
	int numOfCards;
	//Deck(int size);
	//~Deck();
};
/*
class Hand {
	int* currentHand[6];
	int* cost[6];

public:
	Card exchange();

	void addCard();
	void showHand() const;
	Hand();
	~Hand();
};
*/
