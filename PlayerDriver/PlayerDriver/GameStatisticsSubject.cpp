#include "GameStatisticsSubject.h"

#include "GameStatisticsObserver.h"
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
