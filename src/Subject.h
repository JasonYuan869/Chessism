#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer* o) { observers.push_back(o); }

    void detach(Observer* o) {}

    void notifyObservers() {
        for (Observer* o : observers) o->notify();
    }

    virtual ~Subject() = default;
};

#endif
