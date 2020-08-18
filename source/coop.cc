#include <string.h>
#include "coop.h"
#include "board.h"
#include "player.h"
using namespace std;

Coop::Coop(){
    setPosition(38);
    setName("COOP FEE");
}

Coop::~Coop(){}

void Coop::pay(Player * p){
    int currMoney = p->getCurrMoney();
    if (currMoney < 150) {
        cout << "You are bankrupt!" << endl;
        p->setIsBankrupt(true);
        // p->setIsPlaying(true);
    }
    else {
        p->setCurrMoney(currMoney - 150);
        cout << "You've had $150 deducted from your savings for coop." << endl;
    }
}

void Coop::notify(Player * p) {
    if (p->getCurrPosition() == getPosition()) {
        pay(p);
    }
}


