#include "ExamplePlayer.h"
#include "BiddingFacility.h"
#include <iostream>
int ExamplePlayer::getCoins() {
	return coins;
}
void ExamplePlayer::spendCoins(int c) {
	coins = coins - c;
}
void ExamplePlayer::bid() {
	bidding.placeBidAndAge();
}
void ExamplePlayer::bid(int a, int b) {
	bidding.placeBidAndAge(a,b);
}
void ExamplePlayer::bidWon() {
	coins -= bidding.getBid();
	std::cout << "Player now has " << coins << " remaining";
}
ExamplePlayer::ExamplePlayer() {
	coins = 20;
	BiddingFacility bidding;
}


/*class ExamplePlayer
{
	int coins;
	BiddingFacility bidding;
public:
	int getCoins();
	void spendCoins(int x);
	void bid();
};
*/