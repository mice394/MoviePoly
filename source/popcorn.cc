#include "string"
#include "popcorn.h"
using namespace std;
#include <iostream>

POPCORN::POPCORN(){
    setPosition(20);
    setName("POPCORN");
}

POPCORN::~POPCORN(){}

void POPCORN::attack(){
    cout << "You have recieved free popcorn!" << endl;
}

void POPCORN::notify(Player * somePlayer) {
    if (somePlayer->getCurrPosition() == getPosition()) {
        attack();
    }
}
