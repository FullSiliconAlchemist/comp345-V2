#pragma once
#include <list>
#include "Cards.h"
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

