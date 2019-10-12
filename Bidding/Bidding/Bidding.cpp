// To test code, remove /**/ one at a time, to test the 3 cases, and the last 1 to test with hidden user input
#include <iostream>
#include "ExamplePlayer.h"
#include "BiddingFacility.h"

int main()
{	

	
	
	//example1 1, showing highest bid wins
	/*
	ExamplePlayer p[4];
	for (int i = 0; i < 4; i++) {
		p[i].bid(i, i); //age,bid
	}
	*/
	// end of example

	//example 2,  yougest tie wins
	/*
	ExamplePlayer p[2];
	p[0].bid(1, 5);
	p[1].bid(5, 5);
	*/
	//end of example

	//example 3,  all bids 0, youngest wins
	/*
	ExamplePlayer p[4];
	p[0].bid(10, 0);
	p[1].bid(6, 0);
	p[2].bid(40, 0);
	p[3].bid(20, 0);
	*/
	//end of example

	//example 4, user input
	/*
	ExamplePlayer p[4];
	for (int i = 0; i < 4; i++) {
		p[i].bid();
	}
	*/
	// end of example


	BiddingFacility::printBidStatus();

	int x = BiddingFacility::biddingComplete();
	
	std::cout <<"player"<< x << " won the bid\n";

	p[x].bidWon(); // removes coins
	
}

