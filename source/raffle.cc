#include "raffle.h"
using namespace std;

RAFFLE::RAFFLE(int n){
    setPosition(n);
    setName("RAFFLE");
}

RAFFLE::~RAFFLE() {}

void RAFFLE::whichMovement(Player * currPlayer) {
    int chance = rand() % 24;
    string answer;
    int movement = 0;

    if (chance < 3) {
        cout << "You have moven back 3 steps.";
        movement = -3;
    }
    else if (chance < 7) {
        cout << "You have moven back 2 steps.";
        movement = -2;
    }
    else if (chance < 11) {
        cout << "You have moven back 1 step.";
        movement = -1;
    }
    else if (chance < 14) {
        cout << "You have moven forward 1 step.";
        movement = 1;
    }
    else if (chance < 18) {
        cout << "You have moven forward 2 steps.";
        movement = 2;
    }
    else if (chance < 22) {
        cout << "You have moven forward 3 steps.";
        movement = 3;
    }
    else if (chance < 23) {
        cout << "You have gone to the tims line.";
        currPlayer->getInTimeOut();
        currPlayer->setInTimeOut(true);
    }
    else if (chance < 24) {
        cout << "You have gone to recieve a free ticket.";
        currPlayer->setCurrMoney(currPlayer->getCurrMoney() + 200);
    }
    cout << endl;
    int newPosition = currPlayer->getCurrPosition() + movement;
    if (newPosition < 0) {
        newPosition += 40;
    } else if (newPosition > 39) {
        newPosition -= 40;
    }

    currPlayer->setPositions(newPosition);

}

void RAFFLE::notify(Player * somePlayer) {
     if (somePlayer->getCurrPosition() == getPosition()) {
        whichMovement(somePlayer);
    }
}

