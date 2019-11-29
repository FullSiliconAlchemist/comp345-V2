#pragma once
#pragma once
#include <string>

using namespace std;


class GameCards {
public:
	virtual string type() = 0;
};
class Card : public GameCards {
	std::string* action;
	std::string* good;

	int* cost;
	std::string listOfActions[8] = { "newArmy", "moveArmy", "moveOverLandOrWater", "city", "destroyArmy", "destroyArmymoveArmy","newArmymoveArmy","citymoveArmy" };
	std::string listOfGoods[6] = { "crystal", "stone", "iron", "wood", "veggies", "wild" };
public:
	std::string getAction()const;
	std::string getGood() const;
	inline string type() { return "card"; };
	int getCost() const;
	void setCost(int ct);
	void setAction();
	void setGood();

	Card();
	Card(const Card& obj);
	~Card();
};

class Deck : public GameCards {
	Card cardsList[42];
	int* numOfCards;
public:
	inline string type() { return "deck"; };
	Card draw();
	Deck();
	~Deck();
};

class Hand : public GameCards {
	Card currentHand[6];

public:
	inline string type() { return "hand"; };
	int const cost[6] = { 0, 1, 1, 2, 2, 3 };
	Card exchange(int slot, Card replacement);
	Card getCardAt(int i);
	void showHand() const;
	void fillHand(Deck d);
	Hand(Deck d);
	Hand();
	~Hand();
};
class CardsFactory {
public:

	static GameCards* create(string type) {
		if (type == "card") return new Card();
		//if (type == "hand") return new Hand();
		if (type == "deck") return new Deck();
	}
};