#pragma once
#include <list>
#include "iostream"
#include "Cards.h"
using std::cout;
using std::endl;
using std::list;
class GameObservers
{

};

class ObserverPlayer{
public:
	ObserverPlayer();
	~ObserverPlayer();
	virtual void update(Card c) = 0;
private:

};
class ObserverPlayer;
class SubjectPlayer {

public:
	virtual void attach(ObserverPlayer* o);
	virtual void detach(ObserverPlayer* o);
	virtual void notify(Card c);
	SubjectPlayer();
	~SubjectPlayer();

private:
	std::list<ObserverPlayer*>* _observers;
};

class GameStatisticsObserver
{
public:
	~GameStatisticsObserver();
	virtual void Update() = 0;
protected:
	GameStatisticsObserver();
};


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
	list <GameStatisticsObserver*>* _Observers; // One single observer for the game for now
};

