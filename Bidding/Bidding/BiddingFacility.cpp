#include "BiddingFacility.h"
#include "conio.h"
#include "string"
#include "iostream"
#include "sstream"
void BiddingFacility::placeBidAndAge() {
	std::string enteredBid = "";
	char currentChar;
	std::cout << "Enter bid \n";
	currentChar = _getch(); // hides the entered num
	while (currentChar != 13) {
		enteredBid.push_back(currentChar);
		std::cout << "*";
		currentChar = _getch();
	}
	std::stringstream convertBid(enteredBid);
	convertBid >> *bid;
	std::cout << "\nEnter Age \n";

	playerBids[numOfBids] = *bid;
	std::cin >> playerAge[numOfBids];
	numOfBids++;
}
void BiddingFacility::placeBidAndAge(int a, int b) {
	*bid = b;
	playerBids[numOfBids] = b;
	playerAge[numOfBids] = a;
	numOfBids++;

}
int BiddingFacility::biddingComplete() { // returns player # of who won
	int maxBid = 0;
	int numOfMaxes = 0;
	int indexOfWinner = 0;

	int indexOfMaxes[5] = { -1,-1,-1,-1 };

	int lowestAge = 200; // assuming no one playing is older than 200

	for (int i = 0; i < numOfBids; i++) { // find the highest bid
		if (playerBids[i] > maxBid) {
			maxBid = playerBids[i];
		}
	}
	for (int i = 0; i < numOfBids; i++) { //check if theres a tie
		if (playerBids[i] == maxBid) {
			indexOfMaxes[i] = 1;
			indexOfWinner = i;
			numOfMaxes++;
		}
	}
	if (numOfMaxes != 1){ //if there is only 1 max, retrun the winners index
		for (int i = 0; i < numOfBids; i++) { //check for age
			if (playerAge[i] < lowestAge && indexOfMaxes[i] == 1) {
				indexOfWinner = i;
				lowestAge = playerAge[i];
			}
		}
	}
	return indexOfWinner;
}

void BiddingFacility::printBidStatus() {
	for (int i = 0; i < numOfBids; i++) { 
		std::cout << "Player "<< i<<": bid:" << playerBids[i] << " age: " << playerAge[i]<<"\n";
	}
}
int BiddingFacility::getBid() {
	return *bid;
}

int BiddingFacility::playerBids[5] = { 0,0,0,0,0 };
int BiddingFacility::playerAge[5] = { 0,0,0,0,0 };
int BiddingFacility::numOfBids = 0;

BiddingFacility::BiddingFacility() {
	bid = new int(0);
}
BiddingFacility::~BiddingFacility() {

}
/*
class BiddingFacility
{
	int bid;
	int age;
	static int playerBids[5];
	int numOfBids;

public:
	void getBidAndAge();
	static int biddingOver(); //this will take an array of players and return player # that won bid

	BiddingFacility();
	~BiddingFacility();
};

*/