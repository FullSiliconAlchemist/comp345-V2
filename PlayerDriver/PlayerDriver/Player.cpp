#include "Player.h"

void Player::PayCoin(int amountToPay) {
	goldenCoins -= amountToPay;
}
void Player::receiveGoldenCoins(int numOfCoins) {
	goldenCoins += numOfCoins;
}
void Player::bid() {
	bidding.placeBidAndAge();
}
void Player::PlaceNewArmies() {
	return;
}

void Player::MoveArmies() {
	return;
}

void Player::MoveOverLand() {
	return;
}

void Player::BuildCity() {
	return;
}

void Player::DestroyArmy() {
	return;
}
Player::Player()
{
	armyCubes = 14;
	cityDiscs = 3;
	goldenCoins = 0;
}
Player::~Player()
{
}

//inline int Player::GetGoldenCoins() const {
//}
//
//inline int Player::GetArmyCubes() const {
//	
//}
//
//inline int Player::GetCityDiscs() const {
//	
//}