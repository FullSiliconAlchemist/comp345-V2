// PlayerDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Player.h"

using namespace std;

int main()
{
	Player p;
	//Player * p1 = new Player;

	int armyCubes = p.GetArmyCubes();
		
	//delete p1;

	cout << "Player one's army cube amount is: " << armyCubes << endl;
}

