#pragma once
class BiddingFacility
{
	int* bid;
	static int playerAge[5];
	static int playerBids[5];
	static int numOfBids;

public:
	void placeBidAndAge();
	void placeBidAndAge(int a, int b);
	static int biddingComplete(); //this will take an array of players and return player # that won bid
	static void printBidStatus();
	int getBid();

	BiddingFacility();
	~BiddingFacility();
};