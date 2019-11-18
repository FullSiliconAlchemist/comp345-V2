#include "GameObservers.h"
#include <iostream>
using namespace std;
ObserverPlayer::ObserverPlayer() {

}
ObserverPlayer::~ObserverPlayer() {

}

SubjectPlayer::SubjectPlayer() {
	_observers = new list<ObserverPlayer*>;

}
SubjectPlayer::~SubjectPlayer() {
	delete _observers;
}
void SubjectPlayer::attach(ObserverPlayer* o) {
	_observers->push_back(o);
}
void SubjectPlayer::detach(ObserverPlayer* o) {
	_observers->remove(o);
}
void SubjectPlayer::notify(Card c) {
	list<ObserverPlayer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); i++) {
		(*i)->update(c);
	}
}
GameStatisticsObserver::GameStatisticsObserver()
{
}

GameStatisticsObserver::~GameStatisticsObserver()
{
}
GameStatisticsSubject::GameStatisticsSubject() {
	_Observers = new list<GameStatisticsObserver*>;
}
GameStatisticsSubject::~GameStatisticsSubject() {
	delete _Observers;
}
void GameStatisticsSubject::Attach(GameStatisticsObserver* gso) {
	_Observers->push_back(gso);
};
void GameStatisticsSubject::Detach(GameStatisticsObserver* gso) {
	_Observers->remove(gso);
};
void GameStatisticsSubject::Notify() {
	list<GameStatisticsObserver*>::iterator i = _Observers->begin(); // Starting index of iterator
	for (; i != _Observers->end(); ++i)								 // No need for the first argument in for loop
		(*i)->Update();
};


