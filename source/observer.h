#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
class Player;

class Observer {
    public:
        virtual void notify(Player * somePlayer);
        ~Observer();
};

#endif
