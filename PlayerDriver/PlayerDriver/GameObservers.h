#pragma once
#include <list>
class GameObservers
{

};

class Observer{
public:
	Observer();
	~Observer();
	virtual void update() = 0;
private:

};
class Subject {

public:
	virtual void attach(Observer* o);
	virtual void detach(Observer* o);
	virtual void notify();
	Subject();
	~Subject();

private:
	std::list<Observer*>* _observers;
};


