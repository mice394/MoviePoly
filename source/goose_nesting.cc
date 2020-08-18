#include "string"
#include "goose_nesting.h"
using namespace std;
#include <iostream>

GooseNesting::GooseNesting(){
    setPosition(20);
    setName("GOOSENESTING");
}

GooseNesting::~GooseNesting(){}

void GooseNesting::attack(){
    cout << "You have been attacked by a flock of resting geese!" << endl;
}

void GooseNesting::notify(Player * somePlayer) {
    if (somePlayer->getCurrPosition() == getPosition()) {
        attack();
    }
}
