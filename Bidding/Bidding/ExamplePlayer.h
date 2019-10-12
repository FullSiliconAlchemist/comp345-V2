#pragma once
#include "BiddingFacility.h"
class ExamplePlayer
{
	int coins;
	
public:
	int getCoins();
	void spendCoins(int x);
	void bid();
	void bid(int a, int b);
	void bidWon();
	ExamplePlayer();
	BiddingFacility bidding;
};

