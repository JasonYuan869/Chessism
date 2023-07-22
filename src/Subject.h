#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

using namespace std;

class Subject {
	vector<Observer*> observers;
	public: 
		void attach(Observer* o) { observers.push_back(o); }
		void detach(Observer* o) {  }
		void notifyObservers() {
			for (Observer* o : observers) o->notify();
		}
		virtual ~Subject() = 0;
};

#endif
