// DeckHand.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cards.h"
#include <string>
#include <vector>
using namespace std;

int main()
{
	Card c;
	string action = c.getGood();

	cout << action;

	Deck d;

	Card x = d.draw();

	string actionx = x.getGood();
	cout << actionx;
}

