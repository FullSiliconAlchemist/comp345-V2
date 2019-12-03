#pragma once
#include "string"
using namespace std;
class Card {

public:
	std::string* action;
	std::string* good;
	int* cost;
	std::string listOfGoods[6] = { "crystal", "stone", "iron", "wood", "veggies", "wild" };
	std::string listOfActions[8] = { "newArmy", "moveArmy", "moveOverLandOrWater", "city", "destroyArmy", "destroyArmymoveArmy","newArmymoveArmy","citymoveArmy" };
	std::string getAction()const;
	std::string getGood() const;
	const std::string* getRandAction()const;
	int getCost() const;
	void setCost(int ct);
	void setAction();
	void setGood();

	Card();
	Card(const Card& obj);
	~Card();
};


class oneActionCard : public Card {
public:
	std::string listOfSingleActions[5] = { "newArmy", "moveArmy", "moveOverLandOrWater", "city", "destroyArmy"};
	void setAction();
	oneActionCard();
};
class twoActionCard : public Card {
public:
	void setAction();
	std::string listOfDoubleActions[3] = {"destroyArmymoveArmy","newArmymoveArmy","citymoveArmy" };
	twoActionCard();
};
class CardFactory {
public:
	static Card* create(string action) {
		if (action == "single") return new oneActionCard();
		if (action == "double") return new twoActionCard();
	}
private:
	CardFactory() {};
};