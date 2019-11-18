#pragma once
#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

class GameStatisticsObserver; // What is this doing?

class GameStatisticsSubject
{
public:
	virtual void Attach(GameStatisticsObserver* GSO);
	virtual void Detach(GameStatisticsObserver* GSO);
	virtual void Notify();
	GameStatisticsSubject();
	~GameStatisticsSubject();

private:
	list <GameStatisticsObserver*> *_Observers; // One single observer for the game for now
};

