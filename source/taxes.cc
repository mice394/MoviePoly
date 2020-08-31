#include <string.h>
#include "taxes.h"
#include "board.h"
#include "player.h"
using namespace std;

TAXES::TAXES(){
    setPosition(38);
    setName("TAXES");
}

TAXES::~TAXES(){}

void TAXES::pay(Player * p){
    int currMoney = p->getCurrMoney();
    if (currMoney < 150) {
        cout << "You are bankrupt!" << endl;
        p->setIsBankrupt(true);
        // p->setIsPlaying(true);
    }
    else {
        p->setCurrMoney(currMoney - 150);
        cout << "You've had $150 deducted from your savings for taxes." << endl;
    }
}

void TAXES::notify(Player * p) {
    if (p->getCurrPosition() == getPosition()) {
        pay(p);
    }
}


