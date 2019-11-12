#pragma once
#include "Cards.h"
class PlayerStrategies
{
public:
	virtual int idxOfCardToPickup(Hand gameCards, int numOfCoins) = 0;
};

class PlayerUser : public PlayerStrategies {
public:
	int idxOfCardToPickup(Hand gameCards, int numOfCoins);
};

class PlayerAgressive : public PlayerStrategies {
public:
	int idxOfCardToPickup(Hand gameCards, int numOfCoins);
};
class PlayerPassive : public PlayerStrategies {
public:
	int idxOfCardToPickup(Hand gameCards, int numOfCoins);
};