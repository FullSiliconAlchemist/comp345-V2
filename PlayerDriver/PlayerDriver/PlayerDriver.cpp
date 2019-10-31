#include <string>
#include <iostream>
#include <vector>
#include "Map.h"
#include "Country.h"
#include "Player.h"
#include "Cards.h"
using namespace std;

int main()
{
// ---------------------- START PART 4 -------------------------
	Player p;
	Country c1,c2;
	Country *ptrC1 = &c1;
	Country *ptrC2 = &c2;

	//test pay coin
	cout << "Coins before pay: " << p.GetGoldenCoins();
	p.payCoin(5);
	cout << "\nCoins after pay: " << p.GetGoldenCoins();

	//test placeNewArmy
	cout << "\nArmies before placement: " << *c1.getNumberOfArmies();
	p.PlaceNewArmies(3, ptrC1);
	cout << "\nArmies after placement: " << *c1.getNumberOfArmies();

	//test move armies(Implements moveOverLand within move armies method)
	cout << "\nArmies before move c1: " << *c1.getNumberOfArmies() <<" c2: "<< *c2.getNumberOfArmies();
	p.MoveArmies(3, 1, ptrC1, ptrC2);
	cout << "\nArmies before move c1: " << *c1.getNumberOfArmies() << " c2: " << *c2.getNumberOfArmies();

	//test destroy army
	cout << "\nArmies before delete c1: " << *c1.getNumberOfArmies();
	p.DestroyArmy(1, ptrC1);
	cout << "\nArmies after delete c1: " << *c1.getNumberOfArmies();

	//test place city (Shows id# for player that owns the city)
	cout << "\ncity status before placement: " << *c1.getCity();
	p.BuildCity(ptrC1);
	cout << "\ncity status before placement: " << *c1.getCity();
// ---------------------- END PART 4 -------------------------

// ---------------------- START PART 5 -------------------------
	cout << "\n\n";
	Deck gameDeck;
	Hand faceUp(gameDeck);
	faceUp.showHand();
	Card nextCard = gameDeck.draw();
	Card toPickup = faceUp.exchange(0, nextCard);
	cout << "\n\n";
	faceUp.showHand();
//---------------------- END PART 5 -------------------------
}