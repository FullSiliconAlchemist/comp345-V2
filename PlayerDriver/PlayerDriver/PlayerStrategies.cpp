#include "PlayerStrategies.h"
#include <iostream>
#include <string>
using namespace std;
int PlayerUser::idxOfCardToPickup(Hand choiceCards, int numOfCoins) {
	int idxOfCardToTake;
	bool invalidPickup = true;
	while (invalidPickup) {
		choiceCards.showHand();
		std::cin >> idxOfCardToTake;
		if (choiceCards.cost[idxOfCardToTake] <= numOfCoins) {
			return idxOfCardToTake;
		}
		std::cout << "Invalid Card Pickup" << std::endl;
	}
}
int PlayerAgressive::idxOfCardToPickup(Hand choiceCards, int numOfCoins){
	string currAction;
	for (int i = 0; i < 6; i++) {
		currAction = choiceCards.getCardAt(i).getAction();
		bool desirableAction = currAction.compare("city") == 0 || currAction.compare("destroyArmy") == 0 || currAction.compare("citymoveArmy") == 0 || currAction.compare("destroyArmymoveArmy") == 0;
		// if it builds city or is destroy army and is affordable, choose it
		if (desirableAction && choiceCards.cost[i] <= numOfCoins) {
				return i;
		}
	}
	//if it didn't find the card it wanted, pickup the cheapest card
	return 0;
}
int PlayerPassive::idxOfCardToPickup(Hand choiceCards, int numOfCoins) {
	string currAction;
	for (int i = 0; i < 6; i++) {
		currAction = choiceCards.getCardAt(i).getAction();
		bool desirableAction = currAction.compare("newArmy") == 0 || currAction.compare("destroyArmy") == 0 || currAction.compare("moveArmy") == 0 || currAction.compare("destroyArmymoveArmy") == 0 || currAction.compare("newArmymoveArmy") == 0;
		// if it finds desirable action and is affordable, choose it
		if (desirableAction && choiceCards.cost[i] <= numOfCoins) {
			return i;
		}
	}
	//if it didn't find a card it wanted, pickup the cheapest card
	return 0;
}

