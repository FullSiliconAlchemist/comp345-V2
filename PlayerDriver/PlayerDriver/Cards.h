#pragma once
#include <string>

class Card {
	std::string* action;
	std::string* good;
	int* cost;
	std::string listOfActions[8] = { "newArmy", "moveArmy", "moveOverLandOrWater", "city", "destroyArmy", "destroyArmymoveArmy","newArmymoveArmy","citymoveArmy" };
	std::string listOfGoods[6] = { "crystal", "stone", "iron", "wood", "veggies", "wild" };
public:
	std::string getAction()const;
	std::string getGood() const;
	int getCost() const;
	void setCost(int ct);
	void setAction();
	void setGood();

	Card();
	Card(const Card& obj);
	~Card();
};

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
	void showHand() const;
	Hand(Deck d);
	~Hand();
};