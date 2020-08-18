#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Player;

class Subject {
    std::vector<Observer*> observers;
    public:
        void notifyObservers(Player * somePlayer);
        void attach(Observer *o);
        void detach(Observer *o);
        ~Subject();
        Subject();
};

#endif
