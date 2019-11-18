#pragma once
#include <list>
class GameObservers
{

};

class ObserverPlayer{
public:
	ObserverPlayer();
	~ObserverPlayer();
	virtual void update() = 0;
private:

};
class ObserverPlayer;
class SubjectPlayer {

public:
	virtual void attach(ObserverPlayer* o);
	virtual void detach(ObserverPlayer* o);
	virtual void notify();
	SubjectPlayer();
	~SubjectPlayer();

private:
	std::list<ObserverPlayer*>* _observers;
};

