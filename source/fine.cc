#include <string>
#include <iostream>
#include "fine.h"
#include "board.h"
#include "player.h"
using namespace std;

FINE::FINE(){
    setPosition(4);
    setName("FINE");
}

FINE::~FINE() {}

void FINE::pay(Player * p){
    //if b is true, then pay fine
    string cmd;
    cout << "You must either pay [$300] or 10% of your total [net] worth for a fine." << endl;
    cout << ">";
    cin >> cmd;

    if (cmd == "$300"){
        int currMoney = p->getCurrMoney();
        if (currMoney < 300) {
            cout << "You are bankrupt!" << endl;
            p->setIsBankrupt(true);
        }
        else {
            p->setCurrMoney(currMoney - 300);
            cout << "You've had $300 deducted from your savings." << endl;
        }
    }
    if (cmd == "net"){
        int currMoney = p->getCurrMoney();
        if (currMoney < (p->getNetWorth() * 0.1)) {
            cout << "You are bankrupt!" << endl;
            p->setIsBankrupt(true);
        }
        else {
            cout << "You've had " << (p->getNetWorth() * 0.1) << " deducted from your savings." << endl;
            int n = p->getCurrMoney() - (p->getNetWorth() * 0.1);
            p->setCurrMoney(n);
        }
    }
    cout << "You currently have " << p->getCurrMoney() << " in your savings." << endl;
}

void FINE::notify(Player * p) {
    if (p->getCurrPosition() == getPosition()) {
        pay(p);
    }
}

