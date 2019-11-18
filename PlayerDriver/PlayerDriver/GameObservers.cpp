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

