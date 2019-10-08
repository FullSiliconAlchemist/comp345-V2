// DeckHand.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cards.h"
#include <string>
using namespace std;

int main()
{
	Deck gameDeck;
	Hand faceUp(gameDeck);
	faceUp.showHand();

}
/*
Card c;
string action = c.getGood();

cout << action <<"\n";

Deck d;

Card x = d.draw();

string actionx = x.getAction();
cout << actionx << "\n";

Hand h(d);

Card myCard = h.exchange(0, x);

string myCardAction = myCard.getAction();
cout << myCardAction << "\n";
*/

